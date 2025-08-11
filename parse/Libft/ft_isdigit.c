/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:54:29 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:05:24 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	isdigit() checks for a digit (0 through 9).
*/
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("c = %d\n", ft_isdigit('c'));
	printf("c = %d\n", isdigit('c'));
	printf("2 = %d\n", ft_isdigit('2'));
	printf("2 = %d\n", isdigit('2'));
	printf("$ = %d\n", ft_isdigit('$'));
	printf("$ = %d\n", isdigit('$'));
}
*/
