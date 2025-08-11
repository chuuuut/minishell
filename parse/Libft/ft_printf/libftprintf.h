/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:29:04 by chdoe             #+#    #+#             */
/*   Updated: 2024/12/13 17:58:06 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

int		ft_printf(const char *s, ...);
int		ft_printf_c(int c);
int		ft_printf_s(char *s);
int		ft_printf_d_i(int n);
int		ft_printf_u(int n);
int		ft_printf_lower_x(unsigned int n);
int		ft_printf_upper_x(unsigned int n);
int		ft_printf_p(unsigned long p);
int		ft_printf_percent(void);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

#endif
