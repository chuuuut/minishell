/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:05:00 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:25:55 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 size_t strlcpy (char * dst, const char * src, size_t siz)

  Copy src to string dst of size siz. At most siz-1 characters
  will be copied. Always NULL terminates (unless siz == 0).

		Returns
  The strlcpy() function returns strlen(src). If return value >= siz,
  truncation occurred.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	if (siz == 0)
		return (ft_strlen(src));
	i = 0;
	if (siz > 0)
	{
		while (i < (siz - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	dst_ft[20] = {0};
// 	char	dst_man[20] = {0};
// 	char	src[] = "";
// 	size_t	siz;

// 	memset(dst_ft, 'r', 6);
// 	memset(dst_man, 'r', 6);
// 	siz = 0;
// 	printf("src = %s\n\n", src);
// 	ft_strlcpy(dst_ft, src, siz);
// 	strlcpy(dst_man, src, siz);
// 	printf("dst_ft = %s\n", dst_ft);
// 	printf("dst_man = %s\n\n", dst_man);
// 	printf("size_ft = %zu\n", ft_strlcpy(dst_ft, src, siz));
// 	printf("size_man = %zu\n", strlcpy(dst_man, src, siz));
// 	return (0);
// }
