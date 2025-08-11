/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:01:14 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:10:01 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
  memcpy - copy memory area

SYNOPSIS
  #include <string.h>

  void *memcpy(void *dest, const void *src, size_t n);

DESCRIPTION
  The memcpy() function copies n bytes from memory area src to memory area
  dest. The memory areas must not overlap. Use memmove(3) if the memory areas
  do overlap.

RETURN VALUE
  The memcpy() function returns a pointer to dest.

copie n octets de la src vers la dest. ne doit pas chevaucher.
si overlap -> memmove
retourne un pointeur vers dest
pour ne pas chevaucher :
|| *src > *dest
-si la destination est localisee APRES la source dans la memoire
=>risque d'overlap, donc il faut copier dans le sens inverse
|1|2|3|4|5|6|7|8|
|___src___|
		|__dest___|
=> 1 -> 4, 2 -> 5, 3 -> 6
/!\ 4 a ete efface lors de la copie
=> il faut commencer la copie par :
5 -> 8, 4 -> 7, 3 -> 6, 2 -> 5, 1 -> 4
De meme dans l'autre sens :
|| *dest > *src
-si la destination est localisee AVANT la source dans la memoire
=>risque d'overlap, donc il faut copier dans le sens inverse
|1|2|3|4|5|6|7|8|
|__dest___|
		|___src___|
=> 4 -> 1, 5 -> 2, 6 -> 3
/!\ 5 a ete efface lors de la copie
=> il faut commencer la copie par :
4 -> 1, 5 -> 2, 6 -> 3, 7 -> 4, 8 -> 5

*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	char	dest[] = "salut";
	char	dest2[] = "salut";
	char	src[] = "coucou";
	int		n;

	n = 7;
	ft_memcpy(dest, src, n);
	memcpy(dest2, src, n);
//	printf("ft_ = %s\n", dest);
	write(1, &dest, n);
	write(1, "\n", 1);
	printf("man = %s\n", dest2);
}
// si n > len(dest) : risque de supp '\0' et d'overlap
*/
