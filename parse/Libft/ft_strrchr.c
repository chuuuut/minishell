/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:30:07 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:30:13 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   char * strrchr (const char * src, int val)

  Locate character in string. The strrchr() function returns a pointer to the
  last occurrence of the character val in the string src.

  Here 'character' means 'byte' - these functions do not work with wide or
  multi-byte characters.

Returns
  The strrchr() function returns a pointer to the matched character or NULL
  if the character is not found.
*/

#include "libft.h"

char	*ft_strrchr(const char *src, int val)
{
	int	i;

	i = ft_strlen(src);
	while (i >= 0)
	{
		if (src[i] == (char)val)
			return ((char *)&src[i]);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "abdcefghijklmnopq";
	int		v;

	v = 'f';
	printf("ft_ = %s\n", ft_strrchr(src, v));
	printf("man = %s\n", strrchr(src, v));
}
*/
