/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:57:08 by chdoe             #+#    #+#             */
/*   Updated: 2024/12/09 17:37:30 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• %c Prints a single character.
*/

#include "libftprintf.h"

int	ft_printf_c(int c)
{
	return (write(1, &c, 1));
}
/*
#include <stdio.h>
int	main(void)
{
	int	retval;

	retval = ft_printf_c('u');
	printf("%d\n", retval);
	return (0);
}
*/
