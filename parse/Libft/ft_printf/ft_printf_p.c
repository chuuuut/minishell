/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:57:30 by chdoe             #+#    #+#             */
/*   Updated: 2024/12/01 18:57:34 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• %p The void * pointer argument has to be printed in hexadecimal format.
*/

#include "libftprintf.h"

static int	len_p(unsigned long p)
{
	int	i;

	i = 1;
	while (p != 0)
	{
		p /= 16;
		i++;
	}
	return (i);
}

int	ft_printf_p(unsigned long p)
{
	char			*addr;
	unsigned long	ptr;
	int				i;
	int				ret;

	ptr = p;
	i = len_p(ptr);
	if (p == 0)
		return (write(1, "(nil)", 5));
	addr = (char *)malloc(sizeof(char) * (i + 2));
	if (!addr)
		return (-1);
	addr[i + 1] = 0;
	while (ptr > 0)
	{
		addr[i] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
		i--;
	}
	addr[0] = '0';
	addr[1] = 'x';
	ret = write(1, addr, ft_strlen(addr));
	free(addr);
	return (ret);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*p = "salut";
//	char	*p = NULL;
//	printf("%d\n", len_p(p));
	printf("%d, %d\n",printf("%p", p), ft_printf_p((unsigned long)p));
	printf("\n");

//	unsigned long sz = sizeof(p) * 8;
//	while (sz)
//	{
//		last_four_bits = p & 0xf;
//		p >>= 4
//	}
}
*/
