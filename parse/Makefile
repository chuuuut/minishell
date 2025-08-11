# Program name
#	minishell
# Turn in files
#	Makefile, *.h, *.c
# Makefile
#	NAME, all, clean, fclean, re
# Arguments
# External functs.
#	readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay,
#	add_history, printf, malloc, free, write, access, open, read, close,
#	fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset,
#	sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve,
#	dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty,
#	ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
#	tgetnum, tgetstr, tgoto, tputs
# Libft authorized
#     Yes
# Description
#	Write a shell

#name of the executable
NAME = minishell

#compiler
CC = cc

#compilation flags
CFLAGS = -Wall -Wextra -Werror -g3
#DEBUGFLAGS = -g3

ODIR = Objects/

LIBFT = ./Libft/libft.a

FT_PRINTF = ./Libft/ft_printf/libftprintf.a

#sources of prog
SRCS = open_quotes.c parsing_errors.c parsing_utils.c \
parsing.c pipes.c readline.c redirect.c signals.c \
expand_quotes.c init_var.c main.c \

#compiling rule : compiles objects (= *.o)
OBJ = $(SRCS:%.c=$(ODIR)%.o)

#all : 1st rule to execute
all: lib $(NAME)

$(ODIR)%.o:%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C ./Libft

ft_printf:
	make -C ./Libft/ft_printf

lib: libft ft_printf

#object name : dependance (compiles only the new .o)
#$(NAME) (libft.a) as for prerequisites every .o object made from the files
#in $(SRCS). Each call to $(NAME) looks for each of its prerequisites.
#By doing so, each *.o will be recompiled if its source in .c format is newer.

$(NAME): $(OBJ) $(ODIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF) -lreadline -lm
#ar -rcs : archiving

#clean *.o creates from the OBJ
clean:
	rm -f $(OBJ)
	rmdir $(ODIR)
	make clean -C ./Libft
	make clean -C ./Libft/ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C ./Libft
	make fclean -C ./Libft/ft_printf

re: fclean all

#phony : commands that are not files
.PHONY: all clean fclean re lib libft ft_printf
