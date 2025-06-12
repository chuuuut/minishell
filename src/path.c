/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:22:04 by tcali             #+#    #+#             */
/*   Updated: 2025/06/12 13:23:59 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_cmd_path(char *cmd, char **path)
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

char	*get_cmd_path(char *cmd, char **env)
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
	bin = find_cmd_path(cmd, path);
	if (!bin)
	{
		free_array(path);
		return (NULL);
	}
	return (bin);
}
