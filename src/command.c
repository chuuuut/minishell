/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:30:52 by tcali             #+#    #+#             */
/*   Updated: 2025/06/07 17:57:08 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_command(char *cmd, char **path)
{
	char	*cmd_path;
	int		i;

	i = 0;
	while (path[i])
	{
		cmd_path = ft_str_threejoin(path[i], "/", cmd);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*get_command_path(char *cmd, char **env)
{
	char	**path;
	char	*bin;
	int		i;

	if (cmd[0] == '/')
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	i = 0;
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	path = ft_split(env[i] + 5, ':');
	bin = find_command(cmd, path);
	if (!bin)
	{
		free_array(path);
		return (NULL);
	}
	return (bin);
}

void	split_cmd(char *command, char **env, char ***args, char **path)
{
	*args = ft_split(command, ' ');
	if (!*args || !*args[0])
	{
		free_array(*args);
		error_exit("command not found\n");
	}
	*path = get_command_path((*args)[0], env);
	if (!*path)
	{
		ft_printf_fd(2, "%s : command not found\n", (*args)[0]);
		free_array(*args);
		return ;
	}
}

void	execute_command(char *command, char **env)
{
	char	**args;
	char	*path;

	if (ft_strchr(command, ';') || ft_strchr(command, '&')
		|| ft_strchr(command, '|') || ft_strchr(command, '*'))
	{
		args = malloc(sizeof(char *) * 4);
		if (!args)
			error_exit("malloc failed");
		args[0] = ft_strdup("/bin/sh");
		args[1] = ft_strdup("-c");
		args[2] = ft_strdup(command);
		args[3] = NULL;
		path = ft_strdup("/bin/sh");
	}
	else
		split_cmd(command, env, &args, &path);
	if (execve(path, args, env) == -1)
	{
		if (path != args[0])
			free(path);
		free_array(args);
		printf("error executing command");
		return ;
	}
}
