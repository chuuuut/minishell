/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 12:10:02 by tcali             #+#    #+#             */
/*   Updated: 2025/06/10 15:39:34 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tkn_code	get_token_type(char *str)
{
	if (!ft_strncmp(str, "|", 2))
		return (PIPE);
	if (!ft_strncmp(str, "<", 2))
		return (IN);
	if (!ft_strncmp(str, ">", 2))
		return (OUT);
	if (!ft_strncmp(str, ">>", 3))
		return (APPEND);
	if (!ft_strncmp(str, "<<", 3))
		return (HEREDOC);
	return (CMD);
}

t_token	*new_token(char *str, int i)
{
	t_token	*node;

	node = safe_malloc(sizeof(t_token));
	node->str = str;
	node->pos = i;
	node->type = get_token_type(str);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	token_add_back(t_token **lst, t_token *new)
{
	t_token	*current;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
	current->next->prev = current;
}

void	print_token(t_data *data)
{
	t_token	*current;
	char	*str;

	current = data->token;
	while (current)
	{
		if (current->type == CMD)
			str = "cmd";
		else if (current->type == ARG)
			str = "arg";
		else if (current->type == IN)
			str = "input";
		else if (current->type == OUT)
			str = "trunc";
		else if (current->type == APPEND)
			str = "append";
		else if (current->type == HEREDOC)
			str = "heredoc";
		else if (current->type == PIPE)
			str = "pipe";
		printf("current token : %s\nposition : %d\ntype : %s\n",
			current->str, current->pos, str);
		current = current->next;
	}
}

void	create_add_token(t_data *data)
{
	int		i;
	t_token	*new;

	i = 0;
	while (data->tokens[i])
	{
		new = new_token(data->tokens[i], i);
		token_add_back(&data->token, new);
		i++;
	}
	print_token(data);
}
