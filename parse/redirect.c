/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:35:24 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/25 17:51:31 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
