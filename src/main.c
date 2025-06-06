/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:29:44 by tcali             #+#    #+#             */
/*   Updated: 2025/06/06 16:03:09 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		printf("tokens[%d] = [%s]\n", i, tokens[i]);
		i++;
	}
}

int	main(void)
{
	char	*line;
	char	**tokens;

	line = NULL;
	tokens = NULL;
	while (1)
	{
		line = readline("minishell>");
		if (!line)
		{
			printf("exit\n");
			break ;
		}
		if (*line)
			add_history(line);
		tokens = parse_line(line);
		if (!tokens)
		{
			printf("Error parsing line\n");
			break ;
		}
		printf("%s\n", line);
		print_tokens(tokens);
		free(line);
	}
	return (0);
}
