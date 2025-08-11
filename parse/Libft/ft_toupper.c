/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:11:54 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:30:33 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
		toupper - convert uppercase or lowercase

SYNOPSIS
		#include <ctype.h>

		int toupper(int c);

DESCRIPTION
  These functions convert lowercase letters to uppercase, and vice versa.

  If c is a lowercase letter, toupper() returns its uppercase equivalent,
  if an uppercase representation exists in the current locale. Otherwise,
  it returns c.

  If c is neither an unsigned char value nor EOF, the behavior of these
  functions is undefined.

RETURN VALUE
  The value returned is that of the converted letter, or c if the conversion
  was not possible.
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	c;

	c = 'a';
	if (c != ft_toupper(c))
	{
		printf("ft_ : %c devient %c\n", c, ft_toupper(c));
		printf("man : %c devient %c\n", c, toupper(c));
	}
	if (c >= 65 && c <= 90)
	{
		printf("ft_ : %c est deja en majuscule\n", ft_toupper(c));
		printf("man : %c est deja en majuscule\n", toupper(c));
	}
}
*/
