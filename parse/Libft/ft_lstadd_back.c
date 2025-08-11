/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:51:17 by chdoe             #+#    #+#             */
/*   Updated: 2025/04/23 19:51:18 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_lstadd_back
Prototype
	void ft_lstadd_back(t_list **lst, t_list *new);
Turn in files -
Parameters
	lst: The address of a pointer to the first node of a list.
	new: The address of a pointer to the node to be added.
Return value
	None
External functs.
	None
Description
	Adds the node ’new’ at the end of the list.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!lst || !new)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}
