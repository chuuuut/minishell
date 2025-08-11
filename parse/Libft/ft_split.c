/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:00:12 by chdoe             #+#    #+#             */
/*   Updated: 2025/05/19 17:56:45 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_split
Prototype
	char **ft_split(char const *s, char c);
Parameters
	s: The string to be split.
	c: The delimiter character.
Return value
	The array of new strings resulting from the split.
	NULL if the allocation fails.
External functs.
	malloc, free
Description
	Allocates (with malloc(3)) and returns an array of strings obtained by
	splitting ’s’ using the character ’c’ as a delimiter. The array must end
	with a NULL pointer.

		|| another way to count words len ||
int	len_w(char *str, char c)
{
		int i;

		i = 0;
		while (str[i] && str[i] != c)
				i++;
		return (i);
}

len_w(&str[i],c)

str = "Bonjour"

i = 2

&str[i] = "njour"
*/

#include "libft.h"

static void	ft_free(char **tab, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
		free(tab[j++]);
	free(tab);
}

static size_t	count_w(char const *s, char c)
{
	size_t	i;
	size_t	is;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		is = 0;
		while (s[i] != c && s[i])
		{
			is += 1;
			i++;
		}
		if (is > 0)
			count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static size_t	len_w(char const *s, char c, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	return (j);
}

static char	*word(char const *s, char c, size_t i)
{
	size_t	j;
	char	*sub;

	j = 0;
	sub = (char *)ft_calloc(sizeof(char), (len_w(s, c, i) + 1));
	if (!sub)
		return (NULL);
	while (s[i] != c && s[i])
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = 0;
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	char	**sep;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	sep = (char **)ft_calloc(sizeof(char *), (count_w(s, c) + 1));
	if (!sep)
		return ((char **)ft_strdup(""));
	i = 0;
	j = 0;
	while (s[i] && j < count_w(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		sep[j] = (word(s, c, i));
		if (!sep[j++])
			return (ft_free(sep, j), NULL);
		while (s[i] != c && s[i])
			i++;
	}
	return (sep);
}

//int	main()
//{
//	char *str = NULL;
//	char **tab;
//
//	tab = ft_split(str, ' ');
//}
// #include <stdio.h>

// int	main(void)
// {
// 	size_t		i;
// 	const char	*s1 = NULL;
// 	char		c;
// 	char		**result2;
// 	const char	s2[] = " le  iu dr st aet, coe   ";
// 	char		**result1;

// 	c = ' ';
// 	i = 0;
// 	result1 = ft_split(s1, c);
// 	result2 = ft_split(s2, c);
// 	if (result1)
// 	{
// 		while (result1[i])
// 		{
// 			printf("[%zu] = %s\n", i, result1[i]);
// 			i++;
// 		}
// 	}
// 	i = 0;
// 	while (result2[i])
// 	{
// 		printf("[%zu] = %s\n", i, result2[i]);
// 		i++;
// 	}
// 	ft_free(result2, i);
// 	return (0);
// }
