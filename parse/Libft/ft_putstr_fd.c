/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:02:24 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:13:55 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_putstr_fd
Prototype
	void ft_putstr_fd(char *s, int fd);
Parameters
	s: The string to output.
	fd: The file descriptor on which to write.
Return value
	None
External functs.
	write
Description
	Outputs the string ’s’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
/*
#include <fcntl.h>

int	main(void)
{
	char	s[] = "str";
	int		fd;

	fd = open("str.txt", O_WRONLY | O_APPEND | O_CREAT, 0700);
	if (fd == -1)
		return (1);
	ft_putstr_fd(s, fd);
	close(fd);
	return (0);
}
*/
