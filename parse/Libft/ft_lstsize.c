/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:27:19 by chdoe             #+#    #+#             */
/*   Updated: 2024/12/01 03:27:20 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_lstsize
Prototype
	int ft_lstsize(t_list *lst);
Parameters
	lst: The beginning of the list.
Return value
	The length of the list
External functs.
	None
Description
	Counts the number of nodes in a list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	i++;
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "Hello Chloe";
	t_list	*tmp;
	int	i = 0;

	tmp = ft_lstnew(str);
	while (i < 5)
	{
		ft_lstadd_back(&tmp, ft_lstnew((void *)str));
		i++;
	}
	printf("%d", ft_lstsize(tmp));
}
*/
