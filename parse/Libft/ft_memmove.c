/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:04:28 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:12:30 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
  memmove - copy memory area

SYNOPSIS
		#include <string.h>

  void *memmove(void *dest, const void *src, size_t n);

DESCRIPTION
  The memmove() function copies n bytes from memory area src to memory area
  dest. The memory areas may overlap: copying takes place as though the bytes
  in src are first copied into a temporary array that does not overlap src or
  dest, and the bytes are then copied from the temporary array to dest.

RETURN VALUE
  The memmove() function returns a pointer to dest.

	void *source = (void *)data;
	void *destination = (void *)(data + 1);
	size_t size = ELEMENT_COUNT * sizeof(int);
	memmove(destination, source, size);
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (n == 0)
		return (dest);
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (n-- > 0)
			d[n] = s[n];
	return (d);
}

// #include <stdio.h>
// #include <string.h>

// void	DumpHex(const void *data, size_t size)
// {
// 	char	ascii[17];

// 	size_t i, j;
// 	ascii[16] = '\0';
// 	for (i = 0; i < size; ++i)
// 	{
// 		printf("%02X ", ((unsigned char *)data)[i]);
// 		if (((unsigned char *)data)[i] >= ' '
// 			&& ((unsigned char *)data)[i] <= '~')
// 		{
// 			ascii[i % 16] = ((unsigned char *)data)[i];
// 		}
// 		else
// 		{
// 			ascii[i % 16] = '.';
// 		}
// 		if ((i + 1) % 8 == 0 || i + 1 == size)
// 		{
// 			printf(" ");
// 			if ((i + 1) % 16 == 0)
// 			{
// 				printf("|  %s \n", ascii);
// 			}
// 			else if (i + 1 == size)
// 			{
// 				ascii[(i + 1) % 16] = '\0';
// 				if ((i + 1) % 16 <= 8)
// 				{
// 					printf(" ");
// 				}
// 				for (j = (i + 1) % 16; j < 16; ++j)
// 				{
// 					printf("   ");
// 				}
// 				printf("|  %s \n", ascii);
// 			}
// 		}
// 	}
// }

// test 1
// int	main(void)
// {
// char	zone_expected[30] = {0};
// char	zone_actual[30] = {0};
// char	*p1_expected;
// char	*p2_expected;
// char	*p3_expected;
// char	*p1_actual;
// char	*p2_actual;
// char	*p3_actual;

// p1_expected = zone_expected;
// p2_expected = zone_expected + 10;
// p3_expected = zone_expected + 20;
// memmove(p2_expected, "lorem ipsum dolor sit amet", 8);
// memmove(p1_expected, p2_expected, 7);
// memmove(p3_expected, p2_expected, 7);
// DumpHex(zone_expected, 30);
// printf("\n");
// p1_actual = zone_actual;
// p2_actual = zone_actual + 10;
// p3_actual = zone_actual + 20;
// ft_memmove(p2_actual, "lorem ipsum dolor sit amet", 8);
// ft_memmove(p1_actual, p2_actual, 7);
// ft_memmove(p3_actual, p2_actual, 7);
// DumpHex(zone_actual, 30);
// }

// test 2
// int	main(void)
// {
// 	char expected_string[] = "lorem ipsum dolor sit amet";
// 	char *expected_dest = expected_string + 1;
// 	char actual_string[] = "lorem ipsum dolor sit amet";
// 	char *actual_dest = actual_string + 1;
// 	memmove(expected_string, expected_dest, 8);
// 	ft_memmove(actual_string, actual_dest, 8);
// 	DumpHex(expected_dest, 20);
// 	DumpHex(actual_dest, 20);
// }

// // test 3
// int	main(void)
// {
// 	char expected_string[] = "lorem ipsum dolor sit amet";
// 	char *expected_dest;
// 	char *actual_dest;
// 	void *ptr_expected = memmove(expected_dest, expected_string, 0);
// 	printf("string: %p dest: %p ptr: %p\n", expected_string, expected_dest,
// 		ptr_expected);
// 	void *ptr_actual = ft_memmove(actual_dest, expected_string, 0);
// 	printf("string: %p dest: %p ptr: %p\n", expected_string, actual_dest,
// 		ptr_actual);
// }
