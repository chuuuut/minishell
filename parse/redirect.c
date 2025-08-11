/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:35:24 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/11 14:44:15 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* J'adore ta logique trop mims a chaque fois, ou tu fait etape par etape pour 
   cela que je sais que tu va reussir en moins de 10 jours. Je t'aime ❤️
   */
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
int	redirect_in(char *str)
{
	int	i;
	
	i = 0;
	if (ft_strchr(str, '<') == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '<')
		{	
			i++;
			while (is_space(str[i]))
				i++;
			if (str[i] == '<' || str[i] == '>' || str[i] == '|' || !str[i])
				return (-1);
		}
		i++;
	}
	return (0);
}

/*
❌ Cas invalides (à détecter comme erreurs syntaxiques)

XXX    | < file.txt
        Pipe au début. Erreur potentielle : "syntax error near |"

    < file.txt | | grep test
        Double pipe sans commande entre les deux.

    < file.txt >
        Redirection de sortie sans spécification de fichier.

❌ Quotes ouvertes non fermées

    < "file.txt
        Quote double ouverte, jamais fermée.
        ➤ Erreur : "unclosed double quote"

    < 'file.txt
        Même problème avec quote simple.
        ➤ Erreur : "unclosed single quote"

    < "file.txt | grep something
        Tout est dans une quote non fermée.
        ➤ Ne jamais exécuter : tout est en attente de fermeture de la quote.

    echo "salut | wc < file.txt
        Le < est littéral car il est dans une quote ouverte.
        ➤ Ce n’est pas une redirection, mais une chaîne de caractères (sauf si quote fermée ensuite).
*/






// fonction qui checke si il y a qqch avant un pipe ou avant la fin apres un chevron
// cmd > file = > file cmd
// commande (valide ou non) pas necessaire
// creera le fichier meme si la commande ne marche pas ou si pas de commande


// int	redirect_out(char *str, t_inout_ope out)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_strchr(str, '>') == NULL)
// 		return (-1);
// 	while (str[i])
// 	{
		
// 	}
// }


// < file1 cmd1 | cmd2 > file2
