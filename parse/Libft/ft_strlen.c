/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:57:22 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/23 17:46:04 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
SYNOPSIS
		#include <string.h>

		size_t strlen(const char *s);

DESCRIPTION
		The  strlen()  function  calculates  the  length  of the
		string pointed to by s, excluding the  terminating  null
		byte ('\0').

RETURN VALUE
		The strlen() function returns the number of bytes in the
		string pointed to by s.
*/

#include "libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%zu\n", ft_strlen("compte"));
}
*/
