/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:29:44 by tcali             #+#    #+#             */
/*   Updated: 2025/06/06 18:17:44 by tcali            ###   ########.fr       */
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

void	init_data(t_data *data, char **tokens, char **env)
{
	int	i;

	i = 0;
	data->pid1 = 0;
	data->pid2 = 0;
	data->cmd1 = tokens[0];
	data->cmd2 = NULL;
	//if (data->cmd2 == NULL || data->cmd2[0] == '\0')
	//{
	//	write(2, "empty command\n", 22);
	//	exit(EXIT_FAILURE);
	//}
	data->envp = env;
	data->file1 = NULL;
	data->file2 = NULL;
	while (tokens[i])
		i++;
	data->nb_tokens = i;
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

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
	{
		args = ft_split(command, ' ');
		if (!args || !args[0])
			printf("invalid command\n");
		path = get_command_path(args[0], env);
		if (!path)
		{
			ft_printf_fd(2, "%s : command not found\n", args[0]);
			free_array(args);
			//exit(127);
		}
	}
	if (execve(path, args, env) == -1)
	{
		if (path != args[0])
			free(path);
		free_array(args);
		printf("error executing command");
	}
}

void	handle_sigint(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_redisplay();
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	char	**tokens;
	t_data	data;

	(void)ac;
	(void)av;
	line = NULL;
	tokens = NULL;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
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
		init_data(&data, tokens, envp);
		execute_command(data.cmd1, data.envp);
		free(line);
		free(tokens);
	}
	return (0);
}
