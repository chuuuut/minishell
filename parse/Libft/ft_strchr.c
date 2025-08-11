/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:14:53 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:17:28 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  Locate character in string. The strchr() function returns a pointer to the
  first occurrence of the character val in the string src.

  Here 'character' means 'byte' - these functions do not work with wide or
  multi-byte characters.

		Returns
  The strchr() function returns a pointer to the matched character or NULL
  if the character is not found.

src + i : increment pointer's value
*src point on tab first value
i increment tab's value
*/

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	char	*ptr;
	int		i;

	ptr = 0;
	i = 0;
	while (src[i])
	{
		if (src[i] == (char)c)
		{
			ptr = (char *)src + i;
			return (ptr);
		}
		i++;
	}
	if ((char)c == 0)
		return ((char *)&src[i]);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "coucou toi";
	int		c;
	char	*result;
	char	*result2;

	c = 'o';
	result = ft_strchr(str, c);
	result2 = strchr(str, c);
	printf("ft_[i] = %ld\n", result - str);
	printf("man[i] = %ld\n", result2 - str);
// %s - %s -> returns the diff between lens of the 2 str
	printf("%s\n", strchr(str, c));
	printf("%s\n", ft_strchr(str, c));
}
*/
