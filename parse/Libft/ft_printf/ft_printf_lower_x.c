/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:58:00 by chdoe             #+#    #+#             */
/*   Updated: 2024/12/01 18:58:03 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• %x Prints a number in hexadecimal (base 16) lowercase format.
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

int	ft_printf_lower_x(unsigned int n)
{
	char	*hex;
	char	*ret;
	int		low;
	int		i;

	i = len_x(n);
	hex = "0123456789abcdef";
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
	low = write(1, ret, ft_strlen(ret));
	free(ret);
	return (low);
}
/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int	n = INT_MIN;

	ft_printf_lower_x(n);
	printf("|\n");
	printf("%x\n", n);
}
*/
