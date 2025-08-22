/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:38:50 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/22 20:01:58 by chdoe            ###   ########.fr       */
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


// int	main(int argc, char **argv)
// {
// 	(void)	argc;
// 	t_quotes	*quotes;
	
// 	quotes = malloc(sizeof(t_quotes));
// 	if (!quotes)
// 	return (errno);
// 	init_quotes(quotes);
// 	syntax_error(argv[1], quotes);
// 	// syntax_error(">> \"", quotes);
// 	free(quotes);
// 	return (0);
// }



// int	main(int argc, char **argv)
// {
// 	t_quotes	*quotes;
// 	// t_inout_ope	*inout;

// 	quotes = malloc(sizeof(t_quotes));
// 	if (!quotes)
// 		return (errno);
// 	(void)argc;
// 	// inout = malloc(sizeof(t_inout_ope));
// 	// if (!inout)
// 	// 	return (errno);
// 	init_quotes(quotes);
// 	// init_inout(inout);
// 	printf("%d\n", append_inout(argv[1], quotes));
// 	free(quotes);
// 	return (0);
// }



int	main(int argc, char **argv, char **env)
{
	int	i;
	(void)	argc;
	t_quotes	*quotes;

	i = 0;
	quotes = malloc(sizeof(t_quotes));
	if (!quotes)
		return (errno);
	init_quotes(quotes);
	// while (env[i])
	// {
	// 	printf("%d = %s\n", i, env[i]);
	// 	i++;
	// }
	// printf("%s\n", expand_quotes(argv[1], quotes, env));
	printf("%s\n", argv[1]);
	printf("%s\n", expand_quotes(argv[1], quotes, env));
	free(quotes);
	return (0);
}
