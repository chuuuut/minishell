/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:58:24 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:13:00 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
  memset - fill memory with a constant byte

SYNOPSIS
  #include <string.h>

  void *memset(void *s, int c, size_t n);

DESCRIPTION
  The memset() function fills the first n bytes of the memory area pointed
  to by s with the constant byte c.

RETURN VALUE
  The memset() function returns a pointer to the memory area s.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_char;

	s_char = (unsigned char *)s;
	while (n-- > 0)
		*s_char++ = c;
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

//	/!\ : test the 2 functions separately
//"coucou"; n = 8;
//"coucou"; n = 0;
//""; n = 8;
//""; n = 0;

int	main(void)
{
	char	s1[] = "coucou";
	char	s2[] = "coucou";
	int		c;
	size_t	n;

	c = 'v';
	n = 8;
	ft_memset(s1, c, n);
	printf("ft_ = %s\n", s1);
	memset(s2, c, n);
	printf("man = %s\n", s2);
}
*/
