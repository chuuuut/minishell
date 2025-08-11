/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:22:22 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:00:52 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
SYNOPSIS
		#include <stdlib.h>

		int atoi(const char *nptr);

DESCRIPTION
  The atoi() function converts the initial portion of the string pointed to by
  nptr to int.

RETURN VALUE
		The converted value or 0 on error.
*/

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	if (ft_isdigit(nptr[i]) == 0)
		return (0);
	while (nptr[i] && ft_isdigit(nptr[i]) > 0)
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * num);
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char s1[] = " \t\v-123456";
// 	char s2[] = " +----++-++--123456";
// 	char s3[] = "+42lyon";
// 	char s4[] = "-    a123456";
// 	char s5[] = "\t\n\r\v\f  469 \n";
// 	char s6[] = "-123456a";

// 	printf("atoi_ft = %d | atoi_man = %d\n", ft_atoi(s1), atoi(s1));
// 	printf("atoi_ft = %d | atoi_man = %d\n", ft_atoi(s2), atoi(s2));
// 	printf("atoi_ft = %d | atoi_man = %d\n", ft_atoi(s3), atoi(s3));
// 	printf("atoi_ft = %d | atoi_man = %d\n", ft_atoi(s4), atoi(s4));
// 	printf("atoi_ft = %d | atoi_man = %d\n", ft_atoi(s5), atoi(s5));
// 	printf("atoi_ft = %d | atoi_man = %d\n", ft_atoi(s6), atoi(s6));
// }
