/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:21:23 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:29:48 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
  strnstr — locate a substring in a string

LIBRARY
  Utility functions from BSD systems (libbsd, -lbsd)

SYNOPSIS
  #include <string.h>

  char *strnstr(const char *big, const char *little, size_t len);

DESCRIPTION
  strnstr() locates the first occurence of little in big, or at most len
char in big are searched. chars after '\0' are not searched.

RETURN VALUES
  if little is empty, return big
  if little isn't found, return NULL
  otherwise, points on the first char of the first occurence of little
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	if (lil[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		count = 0;
		if (big[i + j] == lil[j])
		{
			while (big[i + j] == lil[j] && i + j < len && j < ft_strlen(lil))
			{
				count += 1;
				j++;
			}
		}
		if (count == ft_strlen(lil))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	big[] = "t te tes test teste tested";
	char	lil[] = "teste";
	size_t	len;

	len = 25;
	printf("len = %zu\n", len);
	printf("ft_ = %s\n", ft_strnstr(big, lil, len));
	printf("man = %s\n", strnstr(big, lil, len));
}
*/
