/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:13:48 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:30:29 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
		toupper, tolower, toupper_l, tolower_l - convert uppercase or lowercase

SYNOPSIS
		#include <ctype.h>

		int tolower(int c);

DESCRIPTION
  These functions convert lowercase letters to uppercase, and vice versa.

  If c is an uppercase letter, tolower() returns its lowercase equivalent,
  if a lowercase representation exists in the current locale. Otherwise, it
  returns c.

  If c is neither an unsigned char value nor EOF, the behavior of these
  functions is undefined.

RETURN VALUE
  The value returned is that of the converted letter, or c if the conversion
  was not possible.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 'C';
	if (c != ft_tolower(c))
	{
		printf("ft_ : %c devient %c\n", c, ft_tolower(c));
		printf("man : %c devient %c\n", c, tolower(c));
	}
	if (c >= 97 && c <= 122)
	{
		printf("ft_ : %c est deja en minuscule\n", ft_tolower(c));
		printf("man : %c est deja en minuscule\n", tolower(c));
	}
}
*/
