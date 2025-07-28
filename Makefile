NAME = minishell

# Directories
SRC_DIR = src
PARSE_DIR = parse
LIBFT_DIR = libft
OBJ_DIR = obj
INCLUDE_DIR = includes

# Sources
SRC := \
	builtins.c \
	command.c \
	debug.c \
	fork.c \
	free.c \
	init.c \
	list.c \
	main.c \
	parse.c \
	path.c \
	redirection.c \
	signals.c \
	utils.c \

PARSE := \
	parsing.c \
	readline.c \
	signals.c \
	syntax.c \
	parsing_utils.c \
	open_quotes.c \
	#name of files

#Path to sources
VPATH = $(SRC_DIR) $(PARSE_DIR)

# Objects
OBJ_FILES := $(addprefix $(OBJ_DIR)/$(SRC_DIR)/, $(SRC:.c=.o)) \
	$(addprefix $(OBJ_DIR)/$(PARSE_DIR)/, $(PARSE:.c=.o)) \
# Compilation
CC := gcc
CFLAGS := -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

#Libraries
LIBFT = $(LIBFT_DIR)/libft.a

#Objects directory
OBJDIRS := $(sort $(dir $(OBJ_FILES)))

# Rules
all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(OBJ_FILES) -o $(NAME) -L$(LIBFT_DIR) -lft -lreadline

$(OBJ_DIR)/%.o: %.c | $(OBJDIRS)
	$(CC) $(CFLAGS) -c $< -o $@

#Create object directory if doesn't exist
$(OBJDIRS):
	@mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug : CFLAGS += -g3 -D PROMPT="\"\\033[1;36mdebugshell \$ \033[1;34m\""
debug : re

.PHONY: all clean fclean re debug