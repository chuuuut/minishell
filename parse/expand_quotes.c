/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:31:20 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/14 16:21:31 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//pas d'interpretation de $ dans ''

//		objectif : savoir s'il faut expand ou pas
//	- quand on est dans "" 		->	EXPAND
//	- quand $ suivi de texte	->	EXPAND
//	- quand on est dans ''		->	pas d'expand
//	- quand $ précédé de '\\'	->	pas d'expand

//		renvoyer quand expand ou quand ignorer


// int	expand_quotes(char *line, t_quotes *quotes, char **env)
// {
// 	int	i;
	
// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] && line[i] == '$')
// 		{
// 			i++;
// 			if (line[i - 1] == '\\')
// 				return (1);			//pas d'expand
// 			if (is_quote_closed(quotes, line, i) == '\'')
// 				return (1);			//pas d'expand
//             if (is_bad_redirect(line[i]))
// 				return (-1);		
// 			while (line[i] && is_space(line[i]))
// 				i++;
// 		}
//         else
//     		i++;
// 	}
// 	return (0);
// }

size_t	ft_len_expand(char *line, t_quotes *quotes, char **env)
{
	size_t	i;
	size_t	len_exp;

	i = 0;
	len_exp = ft_strlen(line);
	if (!ft_strchr(line, '$'))
		return (0);
	while (line[i])
	{
		while (line[i] && line[i] != '$')
			i++;
		while (is_quote_closed(quotes, line, i) == '\'')
			i++;
		if (!(is_quote_closed(quotes, line, i) == '\''))
		{

		}
	}
}
size_t	is_end_expand(char c)
{
	size_t	i;
	static char	set[23] = "\"$'[]%=/0123456789><\\|\0";

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
// " "$'[]%=/0123456789><"

char	*expand_quotes(char *line, t_quotes *quotes, char **env)
{
	size_t		i;
	size_t		j;
	size_t		start;
	char	*exp;
	
	i = 0;
	if (!ft_strchr(line, '$'))
		return (NULL);
	while (line[i])
	{
		while (line[i] && line[i] != '$')
			i++;
		i++;
		start = i;	
		while (!is_space(line[i]) && line[i] != '$' && !is_bad_redirect(line[i]))
			i++;
		while (is_quote_closed(quotes, line, i) == '\'')
			i++;
		if (!(is_quote_closed(quotes, line, i) == '\''))
		{
			exp = ft_strjoin(ft_substr(line, start, i - start - 1), "=");
			if (!exp)
				return (NULL);
			j = 0;
 			while (env[j])
			{
				if (ft_strnstr(env[j], exp, ft_strlen(exp)))
					return (exp);
				j++;
			}
		}
		i++;
	}
	return (0);
}
// il me faut une fonction qui prend une str et qui peut inserer un mot dedans
// retirer la len de exp et rajouter la len de env[j]



// ######################################
// # ✅ 1. CAS ENTIÈREMENT VALIDES
// ######################################

// echo salut                          # Commande simple
// echo "salut monde"                  # Double quotes
// echo 'salut monde'                  # Single quotes
// echo "$USER"                        # Expansion valide
// echo "Bonjour $USER !"              # Expansion dans double quotes
// echo '$USER'                        # Pas d'expansion dans single quotes
// echo texte$USERfin                   # Expansion collée à du texte
// echo "txt$USER"fin                   # Expansion dans quotes + texte hors quotes
//	NPG		echo ${USER}                         # Expansion avec accolades
// ls -l > file.txt                     # Redirection out
// cat < file.txt                       # Redirection in
// echo "salut" > file.txt              # Quote + redirection
// cat <<EOF                            # Heredoc valide
// fin de texte
// EOF
// ls -l >> log.txt                     # Append valide
// cat <<EOF | grep "txt"               # Heredoc + pipe
// test
// EOF
// echo "$INEXISTANT"                   # Expansion vide
// echo ${INEXISTANT:-default}          # Valeur par défaut (bash extension)

// ######################################
// # ❌ 2. CAS ENTIÈREMENT INVALIDES
// ######################################

// | ls                                 # Pipe en début
// ls || ls                             # Double pipe (non géré dans minishell simple)
// <                                    # Redirection in sans fichier
// >                                    # Redirection out sans fichier
// >>                                   # Append sans fichier
// <<                                   # Heredoc sans délimiteur
// ls < >                               # Redirection incohérente
// < file.txt >                         # Out sans fichier après
// echo "salut                          # Double quote non fermée
// echo 'salut                          # Single quote non fermée
// echo ${USER                          # Accolade non fermée
// cat <<EOF                            # Heredoc non terminé
// test

// ls > $INEXISTANT                     # Fichier vide après expansion
// cat < $INEXISTANT                    # Idem
// >> $INEXISTANT/                      # Répertoire inexistant après expansion
// < $INEXISTANT >                      # In + Out sur fichier vide

// ######################################
// # ⚠️ 3. CAS MIXTES (partiellement OK)
// ######################################

// echo salut | grep sal >> log.txt     # Commande + pipe + append valide
// echo "ok" | grep "o" > file.txt      # Expansion implicite + redirection valide
// echo "Hello $USER" | grep "$INEXISTANT"  # Expansion vide mais commande fonctionne
// cat < file.txt | grep "txt"          # In valide + pipe valide
// echo "salut" > file.txt >> log2.txt  # Double redirection out → dernière gagne
// ls -l > $USER.txt                    # Expansion dans nom fichier
// ls -l > "$USER.txt"                  # Expansion dans quotes
// echo $USER $INEXISTANT               # Expansion mixte : valide + vide
// echo "$USER" "$INEXISTANT"           # Expansion vide dans quotes
// echo 'test"ok'                       # Quotes mélangées mais fermées
// echo "test'ok"                       # Idem
// cat <<EOF | grep "ok"                 # Heredoc + pipe valide
// coucou
// EOF
// cat <<EOF | grep "$INEXISTANT"        # Heredoc + expansion vide dans pipe
// vide
// EOF







// chercher le $, checker s'il est dans une quote
// checker dans quel quote il est pour savoir si expand
// 	- si '', pas d'expand
//	- si "", expand
//	- si \$, juste du texte donc pas d'expand




// # ✅ Cas valides (expansion autorisée)
// echo $USER                  # ➤ Affiche la valeur de la variable USER
// echo "$HOME"                # ➤ Expansion dans double quotes (préserve les espaces)
// echo text_$PATH             # ➤ Expansion collée à du texte
// echo "${PATH}"              # ➤ Expansion avec accolades
// echo "$USER_$HOSTNAME"      # ➤ Plusieurs expansions dans une même string
// echo "Bonjour $USER !"      # ➤ Mélange texte + expansion
// echo $@                     # ➤ Expansion des paramètres positionnels
// echo "$1"                   # ➤ Expansion d’un argument spécifique
// echo "$(date)"              # ➤ Command substitution dans double quotes
// echo $INEXISTANT            # ➤ Expansion d'une variable inexistante → affiche rien
// echo "$INEXISTANT"          # ➤ Expansion inexistante dans double quotes → affiche ""
// echo texte$INEXISTANT fin   # ➤ Expansion inexistante au milieu → affiche "textefin"
// echo "${INEXISTANT}"        # ➤ Avec accolades → expansion vide
// echo "$INEXISTANT$USER"     # ➤ Mélange vide + expansion valide
// echo ${INEXISTANT:-default} # ➤ Expansion avec valeur par défaut (bash, non POSIX strict)

// # ❌ Cas à traiter correctement en parsing
// echo '$INEXISTANT'          # ➤ Pas d’expansion dans single quotes → littéral
// echo "\$INEXISTANT"         # ➤ Dollar échappé → affiche $INEXISTANT
// echo ${INEXISTANT           # ➤ Accolade ouverte non fermée → erreur de syntaxe
// echo "$INEXISTANT           # ➤ Double quote ouverte non fermée → erreur
// echo '$USER'                # ➤ Pas d’expansion dans single quotes
// echo "\$USER"               # ➤ Caractère dollar échappé → affiche $USER
// echo $                      # ➤ Dollar seul → littéral, pas d’expansion
// echo $123                   # ➤ Variable non valide (commence par un chiffre) → littéral
// echo "${UNFINISHED"         # ➤ Accolade non fermée → erreur de syntaxe
// echo $"TEXT"                # ➤ Cas spécial (localisation) → à supporter ou ignorer
// echo ${}                    # ➤ Vide entre accolades → erreur
// echo "$UNFINISHED           # ➤ Double quote ouverte → erreur (unclosed double quote)

