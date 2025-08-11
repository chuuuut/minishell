/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:44:21 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:27:14 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   int strncmp (const char * s1, const char * s2, size_t len)
  Compare two strings. The strncmp() function is similar to strcmp(), except
  it only compares the first (at most) n characters of s1 and s2.

Returns
  The strncmp() function returns an integer less than, equal to, or greater
  than zero if s1 (or the first n bytes thereof) is found, respectively, to be
  less than, to match, or be greater than s2.

*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < len)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	size_t	len;

// 	s1 = "test\1";
// 	s2 = "test\200";
// 	len = 12;
// 	printf("%d\n", ft_strncmp(s1, s2, len));
// 	printf("%d\n", strncmp(s1, s2, len));
// }
