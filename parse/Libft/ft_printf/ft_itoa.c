/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:00:22 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:06:18 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_itoa
Prototype
	char *ft_itoa(int n);
Parameters
	n: the integer to convert.
Return value
	The string representing the integer.
	NULL if the allocation fails.
External functs.
	malloc
Description
	Allocates (with malloc(3)) and returns a string representing the integer
	received as an argument.
	Negative numbers must be handled.
*/

#include "libftprintf.h"

static int	len_n(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	long	nb;

	len = len_n(n);
	nb = n;
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (nb < 0)
	{
		num[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		num[0] = '0';
	while (nb > 0)
	{
		len--;
		num[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (num);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int n;
// 	char *s;

// 	n = -1234560;
// 	s = ft_itoa(n);
// 	printf("%s\n", s);
// 	free(s);
// }
