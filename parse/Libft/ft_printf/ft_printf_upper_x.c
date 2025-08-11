/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_upper_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:58:34 by chdoe             #+#    #+#             */
/*   Updated: 2024/12/01 18:58:36 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• %X Prints a number in hexadecimal (base 16) uppercase format.
*/

#include "libftprintf.h"

static int	len_x(unsigned int n)
{
	int	i;

	i = 1;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_printf_upper_x(unsigned int n)
{
	char	*hex;
	char	*ret;
	int		i;
	int		upp;

	i = len_x(n);
	hex = "0123456789ABCDEF";
	if (n == 0)
		return (write(1, "0", 1));
	ret = (char *)malloc(sizeof(char) * (i));
	if (!ret)
		return (-1);
	ret[--i] = 0;
	while (n > 0)
	{
		i--;
		ret[i] = hex[n % 16];
		n /= 16;
	}
	upp = write(1, ret, ft_strlen(ret));
	free(ret);
	return (upp);
}
/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int	n = 0;

	ft_printf_upper_x(n);
	printf("|\n");
	printf("%X\n", n);
}
*/
