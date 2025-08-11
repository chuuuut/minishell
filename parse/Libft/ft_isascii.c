/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:56:20 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:08:34 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 isascii()
  checks whether c is a 7-bit unsigned char value that fits into the ASCII
  character set.
*/
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("c = %d\n", ft_isascii('c'));
	printf("c = %d\n", isascii('c'));
	printf("2 = %d\n", ft_isascii('2'));
	printf("2 = %d\n", isascii('2'));
	printf("$ = %d\n", ft_isascii('$'));
	printf("$ = %d\n", isascii('$'));
}
*/
