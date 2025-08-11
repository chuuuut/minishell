/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:00:05 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:30:09 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_strtrim
Prototype
	char *ft_strtrim(char const *s1, char const *set);
Parameters
	s1: The string to be trimmed (== reduced/cut).
	set: The reference set of characters to trim.
Return value
	The trimmed string.
	NULL if the allocation fails.
External functs.
	malloc
Description
	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
	specified in ’set’ removed from the beginning and the end of the string.
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	beg;
	size_t	end;
	size_t	siz;

	i = 0;
	beg = 0;
	end = 0;
	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (NULL);
	while (ft_strchr(set, s1[i++]))
		beg++;
	while (s1[i])
		i++;
	while (ft_strrchr(set, s1[i--]))
		end++;
	siz = ft_strlen(s1) + 1 - beg - end;
	return (ft_substr(s1, beg, siz));
}

/* int	main(void)
 {
  #include <stdio.h>
	char	s1[] = "STRTRIM_TEST !";
	char	s2[] = "STRTRIM_TEST !";
	char	*trim1;
	char	*trim2;
	char	set[] = "";

	trim1 = ft_strtrim(s1, set);
	trim2 = ft_strtrim(s2, set);
	printf("s1 trimmed = %s\n", s1);
	printf("s2 trimmed = %s\n", s2);
	free(trim1);
	free(trim2);
}
*/
