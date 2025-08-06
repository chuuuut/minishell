/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:35:24 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/05 18:22:27 by chdoe            ###   ########.fr       */
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

int	redirect_in(char *str)
{
	int	i;

	i = 0;
	if (ft_strchr(str, '<') == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == )
	}
}

// fonction qui checke si il y a qqch avant un pipe ou avant la fin apres un chevron
// cmd > file = > file cmd
int	redirect_out(char *str)
{
	int	i;

	i = 0;
	if (ft_strchr(str, '>') == NULL)
	while (str[i])
	{
		
	}
}


// < file1 cmd1 | cmd2 > file2
