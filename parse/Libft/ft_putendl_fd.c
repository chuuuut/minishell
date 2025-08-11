/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:03:17 by chdoe             #+#    #+#             */
/*   Updated: 2024/11/30 04:13:46 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function name
	ft_putendl_fd
Prototype
	void ft_putendl_fd(char *s, int fd);
Parameters
	s: The string to output.
	fd: The file descriptor on which to write.
Return value
	None
External functs.
	write
Description
	Outputs the string ’s’ to the given file descriptor followed by a newline.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
#include <fcntl.h>

int	main(void)
{
	char	s[] = "chloe doe";
	int		fd;

	fd = open("lisa.txt", O_WRONLY | O_CREAT | O_APPEND, 0700);
	if (fd == -1)
		return (1);
	ft_putendl_fd(s, fd);
	close(fd);
	return (0);
}
*/
