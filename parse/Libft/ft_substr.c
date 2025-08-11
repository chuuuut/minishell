/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:59:32 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:51:48 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_substr
Prototype
	char *ft_substr(char const *s, unsigned int start, size_t len);
Description
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of maximum size ’len’.
Parameters
	s: The string from which to create the substring.
	start: The start index of the substring in the string ’s’.
	len: The maximum length of the substring.
Return value
	The substring.
	NULL if the allocation fails.
External functs.
	malloc
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char			*sub;
// 	char			s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 	size_t			len;
// 	unsigned int	start;

// 	//	char	s[] = "The malloc() function allocates size bytes";
// 	len = 10;
// 	start = 20;
// 	sub = ft_substr(s, start, len);
// 	printf("ft_ = %s\n", sub);
// 	free(sub);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	char			*sub;
// 	size_t			len;
// 	unsigned int	start;

// 	start = 0;
// 	len = 42000;
// 	sub = ft_substr("tripouille", start, len);
// 	printf("ft_ = %s\n", sub);
// 	free(sub);
// }
