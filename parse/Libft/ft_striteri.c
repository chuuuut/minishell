/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:01:45 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:19:25 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_striteri
Prototype
	void ft_striteri(char *s, void (*f)(unsigned int, char*));
Parameters
	s: The string on which to iterate.
	f: The function to apply to each character.
Return value
	None
External functs.
	None
Description
	Applies the function ’f’ on each character of the string passed as argument,
	passing its index as first argument. Each character is passed by address
	to ’f’ to be modified if necessary.
*/

#include "libft.h"

/*
void	f_putchar(unsigned int i, char *s)
{
	i = 0;
	write(1, &s[i], 1);
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	ft_striteri("coucou", &f_putchar);
	return (0);
}
*/
