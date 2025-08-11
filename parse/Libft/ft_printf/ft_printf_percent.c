/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:58:47 by chdoe             #+#    #+#             */
/*   Updated: 2024/12/01 18:58:48 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• %% Prints a percent sign.
*/

#include "libftprintf.h"

int	ft_printf_percent(void)
{
	return (write(1, "%", 1));
}
/*
#include <stdio.h>
int	main(void)
{
	int	retval;

	retval = ft_printf_percent();
	printf("%d\n", retval);
	return (0);
}
*/
