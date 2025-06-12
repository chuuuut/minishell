/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:30:52 by tcali             #+#    #+#             */
/*   Updated: 2025/06/12 13:24:14 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	split_cmd(char *command, char **env, char ***args, char **path)
{
	*args = ft_split(command, ' ');
	if (!*args || !*args[0])
	{
		free_array(*args);
		error_exit("command not found\n");
	}
	*path = get_cmd_path((*args)[0], env);
	if (!*path)
	{
		ft_printf_fd(2, "%s : command not found\n", (*args)[0]);
		free_array(*args);
		return (-1);
	}
	return (0);
}

char	*exec_bin(char *command, char **args)
{
	args = malloc(sizeof(char *) * 4);
	if (!args)
		error_exit("malloc failed");
	args[0] = ft_strdup("/bin/sh");
	args[1] = ft_strdup("-c");
	args[2] = ft_strdup(command);
	args[3] = NULL;
	return (ft_strdup("/bin/sh"));
}

void	execute_command(char *command, char **env)
{
	char	**args;
	char	*path;

	if (ft_strchr(command, ';') || ft_strchr(command, '&')
		|| ft_strchr(command, '|') || ft_strchr(command, '*'))
		path = exec_bin(command, args);
	else
	{
		if (split_cmd(command, env, &args, &path) == -1)
			return ;
	}
	if (execve(path, args, env) == -1)
	{
		if (path != args[0])
			free(path);
		free_array(args);
		printf("error executing command");
		return ;
	}
}
