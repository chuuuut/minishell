/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:34:28 by tcali             #+#    #+#             */
/*   Updated: 2025/06/16 11:28:52 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data, char **env)
{
	int	i;

	i = 0;
	data->pid = 0;
	data->envp = env;
	data->file1 = NULL;
	data->file2 = NULL;
	while (data->tokens[i])
		i++;
	data->nb_tokens = i;
	data->token = NULL;
	create_add_token(data);
}
