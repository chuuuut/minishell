/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:35:24 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/07 17:06:51 by chdoe            ###   ########.fr       */
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
int	redirect_in(char *str, t_quotes *quotes)
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
			while (ft_isspace(str[i]))
				i++;
			if (str[i] == '<' || str[i] == '>' || str[i] == '|' || !str[i])
				return (-1);
			while (is_quote_closed(quotes, str, i))
				i++;
		}
		i++;
	}
	return (0);
}

void	init_inout(t_inout_ope *inout)
{
	inout->is_file = false;
	inout->is_cmd = false;
}

int	main(void)
{
	t_quotes	*quotes;
	// t_inout_ope	*inout;

	quotes = malloc(sizeof(t_quotes));
	if (!quotes)
		return (errno);
	// inout = malloc(sizeof(t_inout_ope));
	// if (!inout)
	// 	return (errno);
	init_quotes(quotes);
	// init_inout(inout);
	// printf("%d\n", redirect_in("< file", inout, quotes));
	printf("%d\n", redirect_in("< |", quotes));
}


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
