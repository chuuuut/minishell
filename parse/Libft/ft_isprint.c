/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:56:46 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:05:59 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	isprint() checks for any printable character including space.

#include <ctype.h>
#include <stdio.h>
int	main(void)
{
		printf("ft = %d, man = %d\n", ft_isprint('~'), isprint('~'));
		printf("ft = %d, man = %d\n", ft_isprint(' '), isprint(' '));
		printf("ft = %d, man = %d\n", ft_isprint('C'), isprint('C'));
		printf("ft = %d, man = %d\n", ft_isprint('f'), isprint('f'));
		printf("ft = %d, man = %d\n", ft_isprint('6'), isprint('6'));
}

*/
#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32 && c < 127))
		return (16384);
	return (0);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= 127)
// 	{
// 		printf("test %d = %d\n", i, (isprint(i) == ft_isprint(i)));
// 		i++;
// 	}
// }
