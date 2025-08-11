/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:03:33 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:13:50 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_putnbr_fd
Prototype
	void ft_putnbr_fd(int n, int fd);
Parameters
	n: The integer to output.
	fd: The file descriptor on which to write.
Return value
	None
External functs.
	write
Description
	Outputs the integer ’n’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int long	nb;

	nb = n;
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		if (nb < 10)
			ft_putchar_fd(nb + '0', fd);
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putchar_fd(nb % 10 + '0', fd);
		}
	}
}

// #include <fcntl.h>

// int	main(void)
// {
// 	int	n;
// 	int	fd;

// 	n = -123456;
// 	fd = open("putnbr.txt", O_WRONLY | O_APPEND | O_CREAT, 0700);
// 	if (fd == -1)
// 		return (1);
// 	// ft_putnbr_fd(n, fd);
// 	// ft_putchar_fd('\n', fd);
// 	// ft_putnbr_fd(-n, fd);
// 	// ft_putchar_fd('\n', fd);
// 	ft_putnbr_fd(INT_MIN, fd);
// 	ft_putchar_fd('\n', fd);
// 	close(fd);
// 	return (0);
// }
