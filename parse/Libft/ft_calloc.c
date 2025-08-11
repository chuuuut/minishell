/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:23:25 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:04:29 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
  calloc - allocate and free dynamic memory

SYNOPSIS
  #include <stdlib.h>

  void *calloc(size_t nmemb, size_t size);

DESCRIPTION
  The free() function frees the memory space pointed to by ptr, which must
  have been returned by a previous call to malloc(), calloc(), or realloc().
  Otherwise, or if free(ptr) has already been called before, undefined behavior
  occurs.
  If ptr is NULL, no operation is performed.

  The calloc() function allocates memory for an array of nmemb elements of
  size bytes each and returns a pointer to the allocated memory. The memory
  is set to zero. If nmemb or size is 0, then calloc() returns either NULL,
  or a unique pointer value that can later be successfully passed to free().
  If the multiplication of nmemb and size would result in integer overflow,
  then calloc() returns an error. By contrast, an integer overflow would not be
  detected in the following call to malloc(), with the result that an
  incorrectly sized block of memory would be allocated:

			malloc(nmemb * size);

RETURN VALUE
  The calloc() function return a pointer to the allocated memory, which
  is suitably aligned for any built-in type. On error, these functions
  return NULL. NULL may also be returned by a successful call to malloc()
  with a size of zero, or by a successful call to calloc() with nmemb or
  size equal to zero.

char -> stocks 1 byte
int -> stocks 4 bytes
useful to know the index of pointers
if overflow -> error (overflow = too large content for the "box")

 nmemb = nb of elements ; size = size of an element
*/

#include "libft.h"

static void	*none(void)
{
	unsigned char	*mem;

	mem = malloc(1);
	if (!mem)
		return (NULL);
	mem[0] = 0;
	return ((void *)mem);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;

	if (size == 0 && nmemb == 0)
		return (none());
	if (nmemb * size > INT_MAX)
		return (NULL);
	mem = (unsigned char *)malloc(size * nmemb);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (nmemb * size));
	return ((void *)mem);
}

/*
'*mem++'	move the address stocked in var
	BUT dont move the var
'*mem++ = 0;' == 'ft_bzero(mem_space, nmemb * size);'
'*mem++ = 0' means '*mem = 0; mem++;'
*/

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*c;
	char	*d;
	size_t	nmemb;
	size_t	size;

	nmemb = 1;
	size = 1;
	c = ft_calloc(nmemb, size);
	d = calloc(nmemb, size);
	d[0] = 0;		// strcpy ne checke pas la taille de *dest
	strncpy(c, "testtest", size);
	strncpy(d, "testtest", size);
	printf("%s\n", c);
	printf("%s\n", d);
	free(c);
	free(d);
	return (0);
}
*/
