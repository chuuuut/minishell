/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:38:50 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/12 14:50:36 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int	main(void)
// {
// 	t_quotes	*quotes;

// 	quotes = malloc(sizeof(t_quotes));
// 	if (!quotes)
// 		return (errno);
// 	init_quotes(quotes);
// 	printf("%c\n", is_quote_closed(quotes, ""));
// 	free(quotes);
// 	return (0);
// }


// int	main(void)
// {
// 	t_quotes	*quotes;
	
// 	quotes = malloc(sizeof(t_quotes));
// 	if (!quotes)
// 	return (errno);
// 	init_quotes(quotes);
// 	syntax_error(">> \"", quotes);
// 	free(quotes);
// 	return (0);
// }


// int	main(void)
// {
// 	char	*line;

// 	get_signal();
// 	while((line = readline("> ")) != NULL)
// 	{
// 		if (is_prompt_space(line))
// 			continue ;
// 		printf("result : %s\n", line);
// 		printf("%d\n", check_empty_pipes(line));
// 		add_history(line);
// 		free(line);
// 	}
// 	rl_clear_history();
// 	return (0);
// }



int	main(int argc, char **argv)
{
	t_quotes	*quotes;
	// t_inout_ope	*inout;

	quotes = malloc(sizeof(t_quotes));
	if (!quotes)
		return (errno);
	(void)argc;
	// inout = malloc(sizeof(t_inout_ope));
	// if (!inout)
	// 	return (errno);
	init_quotes(quotes);
	// init_inout(inout);
	printf("%d\n", append_inout(argv[1], quotes));
	free(quotes);
	return (0);
}
