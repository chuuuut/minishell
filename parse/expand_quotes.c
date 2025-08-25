/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:31:20 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/25 12:33:02 by chdoe            ###   ########.fr       */
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

size_t	ft_len_expand(char *line, t_quotes *quotes, char **env)
{
	size_t	i;
	size_t	len_exp;
	size_t	start;

	i = 0;
	if (!line)
		return (0);
	len_exp = ft_strlen(line);
	while (i < ft_strlen(line))
	{
		while (line[i] && line[i] != '$')
			i++;
		if (line[i])
			i++;
		start = i;
		while (line[i] && is_quote_closed(quotes, line, i) == '\'' && ft_isalpha(line[i]))
			i++;
		if (!(is_quote_closed(quotes, line, i) == '\''))
			len_exp += (len_expand_var(i, line, env, start));
		i++;
	}
	return (len_exp);
}

size_t	len_expand_var(size_t i, char *line, char **env, size_t start)
{
	size_t	j;
	char	*exp;
	char	*exp_first;
	size_t	len_exp;

	j = 0;
	len_exp = 0;
	while (line[i + j] && line[i + j] !='$' && !is_space(line[i + j]) && i + j < ft_strlen(line))
		j++;
	exp_first = ft_substr(line, start, j);
	if (!exp_first)
		return (-1);
	exp = ft_strjoin(exp_first, "=");
	free (exp_first);
	if (!exp)
		return (-1);
	j = 0;
	while (env[j] && line[i])
	{
		if (ft_strnstr(env[j], exp, ft_strlen(exp)))
			len_exp = len_exp + (ft_strlen(env[j]) - (ft_strlen(exp) * 2));
		j++;
	}
	free(exp);
	return (len_exp);
}

int is_stop_exp(char c)
{
	int i;
	static char check[] = " \"$'[]%=/0123456789><\0";

	i = 0;
	while (i != 22)
	{
		if (check[i] == c)
			return (0);
		i++;
	}
	return (1);
}

size_t	expand_var(char *line, char **env)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*exp_var;
	char		*exp_first;

	i = 0;
	k = 0;
	while (line[i] && is_stop_exp(line[i]))
		i++;
	exp_first = ft_substr(line, 0, i);
	if (!exp_first)
		return (-1);
	exp_var = ft_strjoin(exp_first, "=");
	free(exp_first);
	if (!exp_var)
		return (-1);
	j = 0;
	while (env[j])
	{
		if (ft_strnstr(env[j], exp_var, ft_strlen(exp_var)))
			break ;
		j++;
	}
	if (!env[j])
		return (0);
	i++;
	free(exp_var);
	return (k);
}

char	*expand_quotes(char *line, t_quotes *quotes, char **env)
{
	size_t		i;
	size_t		j;
	size_t		len_exp;
	char	*exp;
	
	i = 0;
	j = 0;
	len_exp = ft_len_expand(line, quotes, env);
	exp = NULL;
	if (len_exp)
		exp = malloc(sizeof(char) * (len_exp + 1));
	if (!exp)
		return (NULL);
	while (i < ft_strlen(line))
	{
		while (line[i] && line[i] != '$')
		{
			exp[j] = line[i];
			i++;
			j++;
		}
		i++;
		j += expand_var(&line[i], env);
		while (line[i] && is_stop_exp(line[i]))
			i++;
	}
	exp[len_exp] = 0;
	if (exp)
		return (exp);		// leak
	return (line);
}



// ➜  parse git:(main) ✗ valgrind ./minishell "echo "salut monde""
// ==69582== Memcheck, a memory error detector
// ==69582== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==69582== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
// ==69582== Command: ./minishell echo\ salut monde
// ==69582== 
// echo salut
// echo salut
// ==69582== 
// ==69582== HEAP SUMMARY:
// ==69582==     in use at exit: 7 bytes in 1 blocks
// ==69582==   total heap usage: 7 allocs, 6 frees, 1,067 bytes allocated
// ==69582== 
// ==69582== LEAK SUMMARY:
// ==69582==    definitely lost: 7 bytes in 1 blocks
// ==69582==    indirectly lost: 0 bytes in 0 blocks
// ==69582==      possibly lost: 0 bytes in 0 blocks
// ==69582==    still reachable: 0 bytes in 0 blocks
// ==69582==         suppressed: 0 bytes in 0 blocks
// ==69582== Rerun with --leak-check=full to see details of leaked memory
// ==69582== 
// ==69582== For lists of detected and suppressed errors, rerun with: -s
// ==69582== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


// ➜  parse git:(main) ✗ valgrind ./minishell "echo \"salut monde\""
// ==69601== Memcheck, a memory error detector
// ==69601== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==69601== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
// ==69601== Command: ./minishell echo\ "salut\ monde"
// ==69601== 
// echo "salut monde"
// echo "salut monde"
// ==69601== 
// ==69601== HEAP SUMMARY:
// ==69601==     in use at exit: 0 bytes in 0 blocks
// ==69601==   total heap usage: 7 allocs, 7 frees, 1,097 bytes allocated
// ==69601== 
// ==69601== All heap blocks were freed -- no leaks are possible
// ==69601== 
// ==69601== For lists of detected and suppressed errors, rerun with: -s
// ==69601== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


// ➜  parse git:(main) ✗ valgrind ./minishell "echo 'salut monde'"
// ==70345== Memcheck, a memory error detector
// ==70345== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==70345== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
// ==70345== Command: ./minishell echo\ 'salut\ monde'
// ==70345== 
// echo 'salut monde'
// echo 'salut monde'
// ==70345== 
// ==70345== HEAP SUMMARY:
// ==70345==     in use at exit: 0 bytes in 0 blocks
// ==70345==   total heap usage: 7 allocs, 7 frees, 1,097 bytes allocated
// ==70345== 
// ==70345== All heap blocks were freed -- no leaks are possible
// ==70345== 
// ==70345== For lists of detected and suppressed errors, rerun with: -s
// ==70345== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)




// malloc un char * a la taille len_exp
// puis recopie line dans new_line avec les var d'env a la place des $
// Puis apres cela token et fini


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

