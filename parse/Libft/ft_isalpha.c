/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:54:13 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:09:51 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
isalpha()
  checks for an alphabetic character; in the standard "C" locale, it is
  equivalent to (isupper(c) || islower(c)). In some locales, there may be
  additional characters for which isalpha() is true—letters which are neither
  uppercase nor lowercase.
*/
#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1024);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	printf("c = %d\n", ft_isalpha('c'));
	printf("c = %d\n", isalpha('c'));
	printf("2 = %d\n", ft_isalpha('2'));
	printf("2 = %d\n", isalpha('2'));
	printf("$ = %d\n", ft_isalpha('$'));
	printf("$ = %d\n", isalpha('$'));
}
*/
