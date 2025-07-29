/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:58:51 by chdoe             #+#    #+#             */
/*   Updated: 2025/07/29 18:53:05 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
if check_quote
  printf("syntax error")
  return 1
if check_pipe
  printf("syntax error")
  return 1
if check_redirect
  printf("syntax error")
  return 1
return 0
*/

#include "../includes/minishell.h"

int	syntax_error(char *line, t_quotes *quotes)
{
	if (check_empty_pipes(line) == 0)
	{
		// printf("%s\n", strerror(2));
		printf("Syntax error : empty pipe\n");
		return (2);
	}
	if (is_quote_closed(quotes, line))
	{
		printf("Syntax error : open quote\n");
		return (2);
	}
	return (0);
}

int	main(void)
{
	t_quotes	*quotes;
	
	quotes = malloc(sizeof(t_quotes));
	if (!quotes)
	return (errno);
	init_quotes(quotes);
	syntax_error("| |", quotes);
	free(quotes);
	return (0);
}


//	perror a utiliser seulement si besoin d'une info liee a errno