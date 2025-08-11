/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:33:09 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:18:57 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
  strdup - duplicate a string

SYNOPSIS
  #include <string.h>

  char *strdup(const char *s);

DESCRIPTION
  The strdup() function returns a pointer to a new string which is a duplicate
of the string s.  Memory for the new string is obtained with malloc(3), and
can be freed with	free(3).

RETURN VALUE
  On success, the strdup() function returns a pointer to the duplicated string.
It returns NULL if insufficient memory was available, with errno set
to indicate the cause of the error.

(char*) = var cast
malloc = allocate memory to the variable
sizeof = size of variable
(ft_strlen(src) + 1) = size of variable + 1 (safety with '\0')
(!dest) = if dest doesnt existe
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*dest;
	char	*dest2;
	char	src[] = "salut";

	dest = ft_strdup(src);
	dest2 = strdup(src);
	printf("%s\n", dest);
	printf("%s\n", dest2);
	free(dest);
	free(dest2);
	return (0);
}
*/
