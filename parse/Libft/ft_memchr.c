/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:20:06 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:11:44 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
		memchr - scan memory for a character

SYNOPSIS
		#include <string.h>

		void *memchr(const void *s, int c, size_t n);

DESCRIPTION
  The memchr() function scans the initial n bytes of the memory area pointed to
  by s for the first instance of c. Both c and the bytes of the memory area
  pointed to by s are interpreted as unsigned char.

RETURN VALUE
  The memchr() function return a pointer to the matching byte or NULL if the
  character does not occur in the given memory area.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	ch;
	char	*sh;

	sh = (char *)s;
	i = 0;
	ch = c;
	while (i < n)
	{
		if (ch == sh[i])
			return (&sh[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s;
	int		c;
	size_t	n;

	s = "salut comment ca va ?";
	c = '?';
	n = 10;
	printf("%p  %s\n", ft_memchr(s, c, n), s);
	printf("%p  %s\n", memchr(s, c, n), s);
}
*/
