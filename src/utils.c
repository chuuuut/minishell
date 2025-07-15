/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:35:34 by tcali             #+#    #+#             */
/*   Updated: 2025/06/24 16:04:13 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipes(int **pipes, int n, t_data *data)
{
	int	i;

	i = 0;
	if (!data->nb_pipes)
		return ;
	while (i < n)
	{
		if (pipes[i][0] >= 0)
			close(pipes[i][0]);
		if (pipes[i][1] >= 0)
			close(pipes[i][1]);
		i++;
	}
}

void	cmd_to_arg(t_token *current)
{
	while (current
		&& (current->type == CMD || current->type == ARG))
	{
		current->type = ARG;
		if (!current->next)
			break ;
		current = current->next;
	}
}

void	check_type(t_token *token, t_data *data)
{
	t_token	*current;

	current = token;
	while (current)
	{
		if (current->pos >= 1)
		{
			if (!is_builtin(current->prev->str) && current->type == CMD
				&& (current->prev->type == CMD || current->prev->type == ARG))
			{
				current = current->prev;
				add_arg(current);
			}
			else if (is_builtin(current->prev->str))
				cmd_to_arg(current);
			else if (is_redirection(current->type))
			{
				current->next->type = ARG;
				redirect_stream(current, data);
			}
		}
		if (!current->next)
			break ;
		current = current->next;
	}
}

void	wait_all(t_data *data, int *last_status)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i <= data->nb_pipes)
	{
		if (data->pids[i] > 0)
		{
			waitpid(data->pids[i], &status, 0);
			*last_status = status;
		}
		i++;
	}
}
