/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:01:30 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:26:46 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_strmapi
Prototype
	char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
Parameters
	s: The string on which to iterate.
	f: The function to apply to each character.
Return value
	The string created from the successive applications of ’f’.
	Returns NULL if the allocation fails.
External functs.
	malloc
Description
	Applies the function f to each character of the string s, passing its
	index as the first argument and the character itself as the second. A new
	string is created (using malloc(3)) to collect the results from the
	successive applications of f.
*/

#include "libft.h"
/*
static char	to_lower(unsigned int i, char c)
{
	i = 0;
	if (c >= 65 && c <= 90)
		c += 32;
	i += 1;
	return (c);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;
	char			*s1;

	s1 = (char *)s;
	i = 0;
	result = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = f(i, s1[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*result;
	char	s[] = "COuCoU";

	result = ft_strmapi(s, &to_lower);
	printf("%s\n", result);
	free(result);
}
*/
