/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:41:32 by tcali             #+#    #+#             */
/*   Updated: 2025/06/12 13:44:05 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	return (!ft_strncmp(cmd, "echo", 5)
		|| !ft_strncmp(cmd, "cd", 3)
		|| !ft_strncmp(cmd, "pwd", 4)
		|| !ft_strncmp(cmd, "export", 7)
		|| !ft_strncmp(cmd, "unset", 6)
		|| !ft_strncmp(cmd, "env", 4)
		|| !ft_strncmp(cmd, "exit", 5));
}

int	exec_builtin(t_token *token, t_data *data)
{
	if (!ft_strncmp(token->str, "echo", 5))
		return (builtin_echo(token));
	// if (!ft_strncmp(token->str, "cd", 3))
	// 	return (builtin_cd(token, data));
	// if (!ft_strncmp(token->str, "pwd", 4))
	// 	return (builtin_pwd());
	if (!ft_strncmp(token->str, "exit", 5))
		return (builtin_exit(data));
	return (1);
}

int	builtin_echo(t_token *token)
{
	int		newline;
	t_token	*current;

	newline = 1;
	current = token->next;
	if (current && !ft_strncmp(current->str, "-n", 3))
	{
		newline = 0;
		current = current->next;
	}
	while (current)
	{
		printf("%s", current->str);
		if (current->next && current->next->str)
			printf(" ");
		current = current->next;
	}
	if (newline)
		printf("\n");
	return (0);
}

int	builtin_exit(t_data *data)
{
	free_minishell(data);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}
