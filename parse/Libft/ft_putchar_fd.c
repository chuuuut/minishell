/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:02:08 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:13:39 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_putchar_fd
Prototype
	void ft_putchar_fd(char c, int fd);
Parameters
	c: The character to output.
	fd: The file descriptor on which to write.
Return value
	None
External functs.
	write
Description
	Outputs the character ’c’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <fcntl.h>

int	main(void)
{
	char	c;
	int		fd;

	c = 'u';
	fd = open("char.txt", O_WRONLY | O_CREAT | O_APPEND, 0700);
	if (fd == -1)
		return (1);
	ft_putchar_fd(c, fd);
	close(fd);
	return (0);
}
*/
