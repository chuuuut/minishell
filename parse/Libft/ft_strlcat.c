/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:28:44 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:22:36 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  size_t strlcat (char * dst, const char * src, size_t siz)

  Concatenate two strings. Appends src to string dst of size siz (siz is the
  full size of dst, not space left). At most siz-1 characters will be copied.
  Always NULL terminates (unless siz <= strlen(dst)).

		Returns
  The strlcat() function returns strlen(src) + MIN(siz, strlen(initial dst)).
  If retval >= siz, truncation occurred.

concatenate 2 strings
add src to dest of size siz w/ no space
copy at most siz-1 char (-1 -> '\0')
ALWAYS '\0' at the end

return	strlen(src) + MIN(siz, strlen(origin dest))
si return val >= siz, truncate
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;
	size_t	d;

	d = ft_strlen(dst);
	i = 0;
	j = 0;
	if (!dst || siz == 0)
		return (ft_strlen(src));
	while (dst[i])
		i++;
	if (dst[i] == '\0')
	{
		while (src[j] && i + j < siz - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
	}
	dst[i + j] = '\0';
	if (siz < d)
		return (ft_strlen(src) + siz);
	return (ft_strlen(src) + d);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char		dest_ft[] = "C";
// 	const char	src[] = "CCCCCAAAAAAAAA";
// 	size_t		size;

// 	// char		dest_man[] = "C";
// 	size = 16;
// 	printf("size = %zu\n", size);
// 	printf("dest_ft = %s | retval_ft = %zu\n", dest_ft, ft_strlcat(dest_ft, src,
// 			size));
// }
