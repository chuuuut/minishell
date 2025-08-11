/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:57:39 by chdoe             #+#    #+#             */
/*   Updated: 2024/12/09 17:44:23 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
*/

#include "libftprintf.h"

int	ft_printf_d_i(int n)
{
	int		nb;
	char	*str;

	str = ft_itoa(n);
	nb = write(1, str, ft_strlen(str));
	free(str);
	return (nb);
}
/*
#include <stdio.h>
int	main(void)
{
	int	n = -123456;
	int	retval;

	retval = ft_printf_d_i(n);
	printf("%d\n", ft_printf_d_i(n));
	return (0);
}
*/
