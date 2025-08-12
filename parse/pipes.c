/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:32:32 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/12 14:50:33 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// erreurs de syntaxe :
//	OK	- rien avant pipe, rien apres pipe
// - simples et doubles quotes verif bien fermées je t'aime ma femme <3
// - < et > : verif qu'il y a qqch apres autre qu'un pipe

#include "../includes/minishell.h"

int	is_char_space(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (is_space(line[i]))
			count++;
		i++;
	}
	if (count == i)
		return (1);
	return (0);
}

int	nb_of_pipes(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '|')
			count++;
		i++;
	}
	return (count);
}

int	check_empty_pipes(char *line)
{
	int		i;
	int		nb_pipes;
	char	**pipes_tab;

	pipes_tab = ft_split(line, '|');
	if (!pipes_tab)
		return (-1);
	nb_pipes = nb_of_pipes(line);
	if (nb_pipes != ft_tablen(pipes_tab) - 1)
		return (0);
	i = 0;
	while (pipes_tab[i])
	{
		if (is_char_space(pipes_tab[i]))
			return (0);
		i++;
	}
	ft_free_tab(pipes_tab);
	return (1);
}
