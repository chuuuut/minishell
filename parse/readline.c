/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:32:18 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/25 17:47:20 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_prompt_space(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (is_space(line[i]))
			len++;
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	char		*line;
	char		*expand;
	t_quotes	*quotes;

	quotes = malloc(sizeof(t_quotes));
	if (!quotes)
		return (errno);
	get_signal();
	while ((line = readline("> ")) != NULL)		//norme pas contente
	{
		init_quotes(quotes);
		if (syntax_error(line, quotes))
		{
			free(line);
			free (quotes);
			rl_clear_history();
			return (0);
		}
		if (is_prompt_space(line))
			continue ;
		printf("result : %s\n", line);
		expand = expand_quotes(line, quotes, env);
		printf("w/ expand :\t%s\n", expand);
		add_history(line);
		free(expand);
		free(line);
	}
	free (quotes);
	rl_clear_history();
	return (0);
}
