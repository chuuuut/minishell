/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:00:12 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:01:04 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
		bzero, explicit_bzero - zero a byte string

DESCRIPTION
  The bzero() function erases the data in the n bytes of the memory
  starting at the location pointed to by s, by writing zeros (bytes
  containing '\0') to that area.

RETURN VALUE
		None.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s_char;

	i = 0;
	s_char = s;
	while (i < n)
	{
		s_char[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "coucou";
	char	s2[] = "coucou";
	size_t	n;

	n = 1;
	ft_bzero(s1, n);
	bzero(s2, n);
	printf("s1 %s\n", s1);
	printf("s2 %s\n", s2);
}
*/
