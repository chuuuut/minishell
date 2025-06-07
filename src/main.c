/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:29:44 by tcali             #+#    #+#             */
/*   Updated: 2025/06/07 18:11:47 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//void	print_tokens(char **tokens)
//{
//	int	i;

//	i = 0;
//	while (tokens[i])
//	{
//		printf("tokens[%d] = [%s]\n", i, tokens[i]);
//		i++;
//	}
//}

void	fork_process(t_data *data)
{
	data->pid1 = fork();
	if (data->pid1 == 0)
	{
		execute_command(data->cmd1, data->envp);
		exit(1);
	}
	else if (data->pid1 > 0)
		wait(NULL);
	else
		perror("fork");
}

void	get_line(t_data *data, char **envp, char *line, char **tokens)
{
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
		//printf("%s\n", line);
		//print_tokens(tokens);
		init_data(data, tokens, envp);
		fork_process(data);
		free(line);
		free(tokens);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	char	*line;
	char	**tokens;

	(void)ac;
	(void)av;
	line = NULL;
	tokens = NULL;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	get_line(&data, envp, line, tokens);
	return (0);
}
