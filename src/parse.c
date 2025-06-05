/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:26:29 by tcali             #+#    #+#             */
/*   Updated: 2025/06/05 19:57:38 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parse_line(const char *line)
{
	char	**tokens;

	tokens = safe_malloc(sizeof(char) * 100);
	return (tokens);
}