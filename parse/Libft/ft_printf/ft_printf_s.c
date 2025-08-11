/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:57:20 by chdoe             #+#    #+#             */
/*   Updated: 2024/12/01 18:57:21 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• %s Prints a string (as defined by the common C convention).
*/

#include "libftprintf.h"

int	ft_printf_s(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}
/*
#include <stdio.h>
int	main(void)
{
	int	retval;

	retval = ft_printf_s("test");
	printf("%d\n", retval);
	return (0);
}
*/
