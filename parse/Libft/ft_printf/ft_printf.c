/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:34:59 by chdoe             #+#    #+#             */
/*   Updated: 2024/12/09 17:47:42 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Program name
	libftprintf.a
Turn in files*/
//	Makefile, *.h, */*.h, *.c, */*.c
/*
Makefile
	NAME, all, clean, fclean, re
External functs.
	malloc, free, write, va_start, va_arg, va_copy, va_end
Libft authorized
	Yes
Description
	Write a library that contains ft_printf(), a function that will mimic
	the original printf()
	You have to recode the printf() function from libc.
Prototype
	int ft_printf(const char *, ...);

Here are the requirements:
• Don’t implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().
• You must use the command ar to create your library.
Using the libtool command is forbidden.
• Your libftprintf.a has to be created at the root of your repository.

You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.

• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/

#include "libftprintf.h"

static int	is_printable(int c)
{
	char	*set;
	int		i;

	i = 0;
	set = "cspdiuxX%";
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	printf_retval(char c, va_list args)
{
	int	retval;

	retval = 0;
	if (c == 'c')
		retval = ft_printf_c((char)va_arg(args, int));
	else if (c == 's')
		retval = ft_printf_s((char *)va_arg(args, const char *));
	else if (c == 'd' || c == 'i')
		retval = ft_printf_d_i((int)va_arg(args, int));
	else if (c == 'u')
		retval = ft_printf_u((unsigned int)va_arg(args, unsigned int));
	else if (c == 'p')
		retval = ft_printf_p(va_arg(args, unsigned long));
	else if (c == 'x')
		retval = ft_printf_lower_x((unsigned int)va_arg(args, unsigned int));
	else if (c == 'X')
		retval = ft_printf_upper_x((unsigned int)va_arg(args, unsigned int));
	else if (c == '%')
		retval = ft_printf_percent();
	return (retval);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		retval;

	i = 0;
	retval = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] != 0)
		{
			if (is_printable(s[i + 1]) == 1)
				retval += printf_retval(s[i + 1], args) - 2;
			i++;
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (i + retval);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*str1 = "UN";
	char	*str2 = "DEUX";
	char	*str3 = malloc(1024);
	char	*str4 = NULL;
	char	*str5 = "";
	unsigned int		nb1 = 123456;
	unsigned int		nb2 = UINT_MAX;
	int		nb3 = 654321;
	int		nb4 = INT_MIN;
	int		retval1;
	int		retval2;
	int		retval1b;
	int		retval2b;
	int		retval3;
	int		retval4;
	int		retval5;
	int		retval6;
	int		retval7;
	int		retval8;
	int		retval9;
	int		retval10;
	int		retval11;
	int		retval12;
	int		retval13;
	int		retval14;
	int		retval15;
	int		retval16;

	printf("##########    s    ##########\n");
	retval1 = ft_printf("ft_ | s1 : %s, s2 : %s", str1, str2);
	retval1b = ft_printf(", null : %s, vide : %s.\n", str4, str5);
	retval2 = printf("man | s1 : %s, s2 : %s", str1, str2);
	retval2b = printf(", null : %s, vide : %s.\n", str4, str5);
	printf("retval ft_ = %d + %d\n", retval1, retval1b);
	printf("retval man = %d + %d\n", retval2, retval2b);

	printf("##########    X    ##########\n");
	retval3 = ft_printf("ft_ | 123456 : %X, UINT_MAX : %X.\n", nb1, nb2);
	retval4 = printf("man | 123456 : %X, UINT_MAX : %X.\n", nb1, nb2);
	printf("retval ft_ = %d\n", retval3);
	printf("retval man = %d\n", retval4);

	printf("##########    x    ##########\n");
	retval3 = ft_printf("ft_ | 123456 : %x, UINT_MAX : %x.\n", nb1, nb2);
	retval4 = printf("man | 123456 : %x, UINT_MAX : %x.\n", nb1, nb2);
	printf("retval ft_ = %d\n", retval3);
	printf("retval man = %d\n", retval4);

	printf("##########    p    ##########\n");
	retval5 = ft_printf("ft_ | ptr1 : %p, ptr2 : %p, ", str1, str2);
	retval6 = ft_printf("ptr3 : %p, NULL : %p.\n", str3, str4);
	retval7 = printf("man | ptr1 : %p, ptr2 : %p, ", str1, str2);
	retval8 = printf("ptr3 : %p, NULL : %p.\n", str3, str4);
	printf("retval ft_ = %d + %d\n", retval5, retval6);
	printf("retval man = %d + %d\n", retval7, retval8);
	free(str3);

	printf("##########    d    ##########\n");
	retval9 = ft_printf("ft_ | 123456 : %d, INT_MIN : %d.\n", nb3, nb4);
	retval10 = printf("man | 123456 : %d, INT_MIN : %d.\n", nb3, nb4);
	printf("retval ft_ = %d\n", retval9);
	printf("retval man = %d\n", retval10);

	printf("##########    i    ##########\n");
	retval11 = ft_printf("ft_ | 654321 : %i, INT_MIN : %i.\n", nb3, nb4);
	retval12 = printf("man | 654321 : %i, INT_MIN : %i.\n", nb3, nb4);
	printf("retval ft_ = %d\n", retval11);
	printf("retval man = %d\n", retval12);

	printf("##########    c    ##########\n");
	retval13 = ft_printf("ft_ | trois : %c%c%c%c%c.\n", 'T', 'r', 'o', 'i', 's');
	retval14 = printf("man | trois : %c%c%c%c%c.\n", 'T', 'r', 'o', 'i', 's');
	printf("retval ft_ = %d\n", retval13);
	printf("retval man = %d\n", retval14);

	printf("##########    percent    ##########\n");
	retval15 = ft_printf("ft_ | percent : %%.\n");
	retval16 = printf("man | percent : %%.\n");
	printf("retval ft_ = %d\n", retval13);
	printf("retval man = %d\n", retval14);

	printf("##########    printf(0)    ##########\n");
	ft_printf("%d\n", ft_printf(0));
	printf("%d\n", printf(0));
}
*/

//||||||||||||	HOW TO USE va_arg
//	declare va_list = args; : init of the list
//	args contains all variadic args
//	va_start(args, format {last arg before variadic args [here : s]})
//	va_arg(args, type) : to move from arg to arg
//	va_end(args) : fin de la liste

/*
|||||||||||||		BONUS

Bonus list:
• Manage any combination of the following flags: ’-0.’ and the field
minimum width under all conversions.
• Manage all the following flags: ’# +’ (Yes, one of them is a space)

If you plan to complete the bonus part, think about the
implementation of your extra features from the start. This way,
you will avoid the pitfalls of a naive approach.

'+'		Sign of number always O/P.
' '		Positive values begin with a blank.
'#'		Various uses:
	  %#x (Hex)   0x prefix added to non-zero values.
	  %#X (Hex)   0X prefix added to non-zero values.
*/
