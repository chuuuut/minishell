/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:57:53 by chdoe             #+#    #+#             */
/*   Updated: 2024/12/01 18:57:54 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• %u Prints an unsigned decimal (base 10) number.
*/

#include "libftprintf.h"

static int	len_n(unsigned int n)
{
	int	i;

	i = 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_u(unsigned int n)
{
	char	*num;
	int		len;

	len = len_n(n);
	num = (char *)malloc(sizeof(char) * (len));
	if (!num)
		return (NULL);
	num[--len] = '\0';
	if (n == 0)
		num[0] = '0';
	while (len--)
	{
		num[len] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}

int	ft_printf_u(int n)
{
	int				nb;
	char			*str;
	unsigned int	m;

	m = (unsigned int)n;
	if (n >= 0)
		str = ft_itoa(n);
	else
	{
		str = ft_itoa_u(m);
	}
	nb = write(1, str, ft_strlen(str));
	free(str);
	return (nb);
}
/*
#include <stdio.h>
int	main(void)
{
	unsigned int	n = 123456;
	ft_printf_u(n);
	printf("\n");
	printf("%d\n", ft_printf_u(n));
}
*/
