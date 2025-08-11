/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 19:33:37 by chdoe             #+#    #+#             */
/*   Updated: 2025/03/30 19:33:46 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_lstnew
Prototype
	t_list *ft_lstnew(void *content);
Turn in files -
Parameters content:
	The content to store in the new node.
Return value
	A pointer to the new node
External functs.
	malloc
Description
	Allocates memory (using malloc(3)) and returns a new node. The ’content’
	member variable is initialized with the given parameter ’content’. The
	variable ’next’ is initialized to NULL.
*/
#include "libft.h"

/* char *ft_new_string(int size);
{
	char	*str;

	str = malloc(sizeof(char) * size);
	if (!str)					//pas necessaire
		return (NULL);			//pas necessaire
	return (str);
}
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
