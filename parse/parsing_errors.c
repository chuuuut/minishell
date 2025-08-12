/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:58:51 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/12 15:12:00 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	syntax_error(char *line, t_quotes *quotes)
{
	if (!line)
		return (1);
	if (check_empty_pipes(line) == 0)
	{
		ft_putstr_fd("Syntax error : empty pipe\n", 2);
		return (2);
	}
	if (is_quote_closed(quotes, line, ft_strlen(line)))
	{
		ft_putstr_fd("Syntax error : open quote\n", 2);
		return (2);
	}
	if (redirect_inout(line, quotes) == -1)
	{
		ft_putstr_fd("Syntax error : command not found\n", 2);
		return (2);
	}
	if (append_inout(line, quotes) == -1)
	{
		ft_putstr_fd("Syntax error : command not found\n", 2);
		return (2);
	}
	return (0);
}

//	perror a utiliser seulement si besoin d'une info liee a errno