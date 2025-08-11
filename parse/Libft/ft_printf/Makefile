#Turn in files
	#Makefile, *.h, */*.h, *.c, */*.c
#Makefile
	#NAME, all, clean, fclean, re
#External functs.
	#malloc, free, write, va_start, va_arg, va_copy, va_end
#Libft authorized
	#Yes
#Description
	#Write a library that contains ft_printf(), a function that will
	#mimic the original printf()

#.INCLUDE : file1 file2 ...

#name of the executable
NAME = libftprintf.a

#compiler
CC = cc

#compilation flags
CFLAGS = -Wall -Wextra -Werror
#../Libft/libft.a

#sources of prog
SRCS = ft_printf.c ft_printf_percent.c ft_printf_upper_x.c \
ft_printf_d_i.c ft_printf_lower_x.c ft_printf_s.c ft_printf_c.c \
ft_printf_p.c ft_printf_u.c ft_itoa.c ft_strlen.c
#ft_printf.c
#*.c

#compiling rule : compiles objects (= *.o)
OBJ = $(SRCS:.c=.o)

AR = ar
AR_FLAGS = -rcs

#all : 1st rule to execute
all: $(NAME)

#object name : dependance (compiles only the new .o)
#$(NAME) (libft.a) as for prerequisites every .o object made from the files
#in $(SRCS). Each call to $(NAME) looks for each of its prerequisites.
#By doing so, each *.o will be recompiled if its source in .c format is newer.
$(NAME): $(OBJ)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJ)
#ar -rcs : archiving

#clean *.o creates from the OBJ
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

#phony : commands that are not files
.PHONY: all clean fclean re




#I think something a bit like this might do it:


#SUBDIRS = projectX projectY

#all: $(SUBDIRS)

#$(SUBDIRS):
#	$(MAKE) -C $@

#.PHONY: $(SUBDIRS)



#EDIT: That's not quite the example asked for. It will try to build
#two projects in sub directories projectX and projectY from the current
#project in the current directory.

#EDIT: Fixed to use moorecm's invocation command
#Last edited on Sep 24, 2010 at 2:59pm

#In a top-level makefile, just use something like:
#$(MAKE) -C dir

#The -C option changes the directory before invoking the make. The $(MAKE)
#variable will use the same make executable as the top-level makefile. man
#make for more information.
