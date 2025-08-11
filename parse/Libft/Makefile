#name of the executable
NAME = libft.a

#compiler
CC = cc

#compilation flags
CFLAGS = -Wall -Wextra -Werror

#sources of prog
SRCS = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c ft_calloc.c \
ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c ft_isalnum.c \
ft_memchr.c ft_putendl_fd.c ft_striteri.c ft_strncmp.c ft_toupper.c ft_isalpha.c \
ft_memcmp.c ft_putnbr_fd.c ft_strjoin.c ft_strnstr.c ft_isascii.c ft_memcpy.c \
ft_putstr_fd.c ft_strlcat.c ft_strrchr.c ft_lstnew.c ft_lstadd_back.c ft_lstsize.c

#compiling rule : compiles objects (= *.o)
OBJ = $(SRCS:.c=.o)

#sources_bonus of prog

AR = ar
AR_FLAGS = -rcs

#all : 1st rule to execute
all: $(NAME)

#object name : dependance (compiles only the new .o)
#$(NAME) (libft.a) as for prerequisites every .o object made from
#the files in $(SRCS). Each call to $(NAME) looks for each of its prerequisites.
#By doing so, each object file will be recompiled if its source in .c format is newer.

#ar -rcs : archiving
$(NAME): $(OBJ)
	$(AR) $(AR_FLAGS) $(NAME) $(OBJ)

#clean *.o creates from the OBJ
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

#phony : commands that are not files
.PHONY: all clean fclean re


#1e etape : creation des .o -> compilation
#2e etape : linking -> .a (si main.c -> cree un programme)

#all, re, ... : rule
#fclean : clean -> prerequirements
#down a rule = recipe
#rcs : replace if exist, create if not, index the files in the archive
#pour utiliser ar -t libft.a

#creeates a  variable : .c .o
#all == execute NAME
#clean delete *.o
#fclean (= fullclean) deletes *.o + *.a
#re fclean evrything + re
