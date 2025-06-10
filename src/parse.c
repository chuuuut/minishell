/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:26:29 by tcali             #+#    #+#             */
/*   Updated: 2025/06/10 15:10:54 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parse_line(const char *line)
{
	char		**tokens;
	const char	*start;
	int			i;
	int			len;

	tokens = safe_malloc(sizeof(char) * 100);
	i = 0;
	len = 0;
	while (*line)
	{
		while (*line && ft_isspace(*line))
			line++;
		if (!line)
			break ;
		start = line;
		while (*line && !ft_isspace(*line))
			line++;
		len = line - start;
		tokens[i] = ft_strndup(start, len);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
