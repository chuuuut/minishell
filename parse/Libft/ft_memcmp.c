/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:20:46 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:26:02 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
  memcmp - compare memory areas

SYNOPSIS
  #include <string.h>

  int memcmp(const void *s1, const void *s2, size_t n);

DESCRIPTION
  The memcmp() function compares the first n bytes (each interpreted as
  unsigned char) of the memory areas s1 and s2.

RETURN VALUE
  The memcmp() function returns an integer less than, equal to, or greater
  than zero if the first n bytes of s1 is found, respectively, to be less than,
  to match, or be greater than the first n bytes of s2.

  For a nonzero return value, the sign is determined by the sign of the
  difference between the first pair of bytes (interpreted as unsigned char)
  that differ in s1 and s2.

  If n is zero, the return value is zero.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*c1;
	const char	*c2;
	size_t		i;

	i = 0;
	c1 = (const char *)s1;
	c2 = (const char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (c1[i] != c2[i])
			return ((unsigned char)c1[i] - (unsigned char)c2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	int		n;

	s1 = "";
	s2 = "coucvu";
	n = 6;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d\n", memcmp(s1, s2, n));
}
*/
