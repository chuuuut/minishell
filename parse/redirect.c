/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:35:24 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/22 20:02:17 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// < file cmd = cmd < file
// utiliser strchr pour trouver le chevron
// strchr renvoie un pointeur sur ou il a trouve le chevron
// avancer comme ca dans la str et checker chaque chevron
// s'ils sont bons il peut avancer
// checker si entre quotes '' ou "", booleen pour indiquer la situation
// comportement != selon la valeur du booleen

// | Symbole    | Nom anglais courant             | Description                         |
// | ---------- | ------------------------------- | ----------------------------------- |
// | `<`        | **input redirection** operator  | redirection de l’entrée (`stdin`)   |
// | `>`        | **output redirection** operator | redirection de la sortie (`stdout`) |
// | `>>`       | **append redirection** operator | sortie en ajout (append)            |
// | `<<`       | **here-document operator**      | début d’un *here-doc* (`<<EOF`)     |
// | `<&`, `>&` | **file descriptor duplication** | duplication de descripteur (avancé) |	//ne pas gerer


// < file cmp |) file cmd | cmd | < file | file cmd < 

// strchr en checkant s'il y a un truc entre le < et le ( | ou \0)
// ! <<
// checher si apres un chevron :
//	-pas de \0 (+ espaces)
//	-pas de | (+ espaces)
//	-si <, valide
//	<> marche (prend en infile, et en lecture/ecriture)
//	cat < > out.txt invalide
//	>< marche pas
// cat < file1 < file2 valide


// | Chevrons | Valide ?  | Signification          |
// | -------- | --------- | ---------------------- |
// | `>`      | ✅        | redirection stdout     |
// | `<`      | ✅        | redirection stdin      |
// | `>>`     | ✅        | append stdout          |
// | `<<`     | ✅        | heredoc                |
// | `<>`     | ✅        | open read/write (rare) |


// ><       # interdit
// <>>      # interdit
// >><      # interdit
// <<>      # interdit
// <<>>     # interdit
// <<<      # (⚠️ utilisé par Bash comme "here string", mais NON POSIX)
// >><<     # interdit
// <>><     # interdit
// ><>      # interdit


// | Forme            | Obligatoire ?     |
// | ---------------- | ----------------- |
// | `>`              | ✅                |
// | `<`              | ✅                |
// | `>>`, `<<`       | ✅                |
// | `<>`             | ✅                |
// | `2>`, `1<`       | ✅                |		//ne pas gerer
// | `3>`, `4<`, etc. | ✅ (si fd ouvert) |		//ne pas gerer


// int	redirect_in(char *str, t_inout_ope *in, t_quotes *quotes)
int	triple_in(char *line, t_quotes *quotes)
{
	char	*check;

	check = ft_strnstr(line, "<<<", ft_strlen(line));
	if (!check)
		return (1);
	if (is_quote_closed(quotes, line, ft_strlen(line) - ft_strlen(check)))
		return (1);
	return (0);
}

int	triple_out(char *line, t_quotes *quotes)
{
	char	*check;

	check = ft_strnstr(line, ">>>", ft_strlen(line));
	if (!check)
		return (1);
	if (is_quote_closed(quotes, line, ft_strlen(line) - ft_strlen(check)))
		return (1);
	return (0);
}

int	redirect_inout(char *line, t_quotes *quotes)
{
	int	i;
	
	i = 0;
	if (!triple_in(line, quotes))
		return (-1);
	if (!triple_out(line, quotes))
		return (-1);
	while (line[i])
	{
		if (line[i] && (line[i] == '<' || line[i] == '>'))
		{
			i++;
			while (line[i] && is_space(line[i]))
				i++;
            if (is_bad_redirect(line[i]))
				return (-1);
		}
        else
    		i++;
	}
	return (0);
}

int	append_inout(char *line, t_quotes *quotes)
{
	int	i;
	
	i = 0;
	if (!triple_in(line, quotes))
		return (-1);
	if (!triple_out(line, quotes))
		return (-1);
	while (line[i])
	{
		if (line[i + 1] && \
		    !is_quote_closed(quotes, line, i) && \
		    ((line[i] == '<' && line[i + 1] == '<') || \
		     (line[i] == '>' && line[i + 1] == '>')))
		{
			i += 2;
				while (line[i] && is_space(line[i]))
					i++;
				if (is_bad_redirect(line[i]))
					return (-1);
		}
        else
    		i++;
	}
	return (0);
}

// # valides
// echo "OK: append" >>file.txt
// echo "OK: append with space" >> file.txt
// echo "heredoc" << EOF
// abc
// EOF

// # invalides (doivent être rejetés par ton parser)
// >>                     # doit échouer
// >>   |                 # doit échouer
// >> < file.txt          # doit échouer
// >> file.txt >>         # doit échouer
// 	KO mais gere par open "'	>> "unclosed           # doit échouer (unclosed double quote)
// 	KO mais gere par open "'	>> 'unclosed           # doit échouer (unclosed single quote)
// >>> file.txt           # doit échouer (triple chevron)
// <<                    # doit échouer (heredoc sans limiteur)
// cat << | grep          # doit échouer (token interdit après <<)





/*
❌ Cas invalides (à détecter comme erreurs syntaxiques)

XXX    | < file.txt
        Pipe au début. Erreur potentielle : "syntax error near |"
géré par le pipes.c

    < file.txt | | grep test
        Double pipe sans commande entre les deux.
OK  MAIS géré par le pipes.c

    < file.txt >
        Redirection de sortie sans spécification de fichier.
*/


// ########## ✅ Cas valides ##########

//		A gerer dans une autre fonction avec double chevrons

// >>file.txt                 # Redirection append sans espace. 
// KO     ➤ Ajoute à file.txt (ou le crée).
// >> file.txt                # Redirection append avec espace. 
// KO     ➤ Ajoute à file.txt (ou le crée).


// echo "file name" > "my file.txt" # Nom de fichier cible entre quotes. 
//  OK    ➤ Crée/écrase "my file.txt".
// >file.txt                  # Redirection vers fichier sans espace. 
//  OK    ➤ Crée/écrase file.txt.
// > file.txt                 # Redirection avec espace après le chevron. 
//  OK    ➤ Crée/écrase file.txt.
// echo salut > out.txt       # Commande avec redirection sortie. 
//  OK    ➤ Écrit "salut\n" dans out.txt.
// ls > out.txt               # Commande classique avec redirection. 
//  OK    ➤ Écrit la liste dans out.txt.
// echo salut | cat > out.txt # Pipe + redirection sortie. 
//  OK    ➤ Résultat du pipe dans out.txt.
// cat < in.txt > out.txt     # Entrée depuis in.txt, sortie vers out.txt. 
//  OK    ➤ Copie in.txt dans out.txt.
// echo "abc > def" > out.txt # '>' dans une chaîne quoted. 
//  OK    ➤ Écrit "abc > def" dans out.txt.
// > "file name | grep"     # Quote fermée donc OK (sinon erreur). 
//  OK    ➤ Si fermée, fichier "file name | grep".


// ########## ❌ Cas invalides ##########

// >                        # Redirection seule. 
//  OK    ➤ Erreur : syntax error near unexpected token 'newline'.
// >>                       # Double chevron seul. 
//  OK    ➤ Erreur : syntax error near unexpected token 'newline'.
// >   |                    # Pipe direct après redirection. 
//  OK    ➤ Erreur : syntax error near unexpected token '|'.
// >>  < file.txt           # Chevrons mélangés immédiatement. 
//  OK    ➤ Erreur : syntax error near unexpected token '<'.
// > > out.txt              # Deux '>' séparés par espace. 
//  OK    ➤ Erreur : syntax error near unexpected token '>'.
// > file.txt >             # Deuxième '>' sans fichier. 
//  OK    ➤ Erreur : syntax error near unexpected token 'newline'.
// > file.txt | | grep test # Double pipe avec trou. 
//  OK    ➤ Erreur : syntax error near unexpected token '|'.
// echo salut > | cat       # Pipe juste après redirection. 
//  OK    ➤ Erreur : syntax error near unexpected token '|'.
// > "file.txt              # Quote double non fermée. 
//  OK    ➤ Erreur : unclosed double quote.
// > 'file.txt              # Quote simple non fermée. 
//  OK    ➤ Erreur : unclosed single quote.
// echo "salut > out.txt    # '>' littéral dans quote ouverte. 
//  OK    ➤ Pas une redirection, mais chaîne incomplète.

