/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:54:44 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/17 16:39:17 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isalnum()
  checks for an alphanumeric character; it is equivalent to (isalpha(c) ||
isdigit(c)).
*/
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) > 0 || ft_isalpha(c) > 0)
		return (8);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("c = %d\n", ft_isalnum('c'));
	printf("c = %d\n", isalnum('c'));
	printf("2 = %d\n", ft_isalnum('2'));
	printf("2 = %d\n", isalnum('2'));
	printf("$ = %d\n", ft_isalnum('$'));
	printf("$ = %d\n", isalnum('$'));
}
*/
