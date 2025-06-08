/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:34:28 by tcali             #+#    #+#             */
/*   Updated: 2025/06/08 17:03:11 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data, char **env)
{
	int	i;

	i = 0;
	data->pid = 0;
	data->pid2 = 0;
	//if (data->cmd2 == NULL || data->cmd2[0] == '\0')
	//{
	//	write(2, "empty command\n", 22);
	//	exit(EXIT_FAILURE);
	//}
	data->envp = env;
	data->file1 = NULL;
	data->file2 = NULL;
	while (data->tokens[i])
		i++;
	data->nb_tokens = i;
	data->cmd = safe_malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (data->tokens[i])
	{
		data->cmd[i] = ft_strdup(data->tokens[i]);
		i++;
	}
	data->cmd[i] = NULL;
}
