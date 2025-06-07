/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:34:28 by tcali             #+#    #+#             */
/*   Updated: 2025/06/07 17:34:47 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
