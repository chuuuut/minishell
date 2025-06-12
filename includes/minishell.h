/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:30:16 by tcali             #+#    #+#             */
/*   Updated: 2025/06/12 14:06:42 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <stdbool.h>

typedef enum e_tkn_code
{
	CMD,
	ARG,
	IN,
	OUT,
	APPEND,
	HEREDOC,
	PIPE,
	AND,
	OR,
	SEP,
}		t_tkn_code;

typedef struct s_token
{
	char			*str;
	int				pos;
	t_tkn_code		type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_data
{
	int		pipe_fd[2];
	pid_t	pid;
	pid_t	pid2;
	char	*line;
	char	**tokens;
	t_token	*token;
	char	**envp;
	char	*file1;
	char	*file2;
	int		nb_tokens;
}		t_data;

//parse.c
char	**parse_line(const char *line);
bool	is_redirection(char *str);
void	identify_tokens(t_data *data);

//path.c
char	*find_cmd_path(char *cmd, char **path);
char	*get_cmd_path(char *cmd, char **env);

//command.c
int		split_cmd(char *command, char **env, char ***args, char **path);
void	execute_command(char *command, char **env);

//signals.c
void	handle_sigint(int sig);

//init.c
void	init_data(t_data *data, char **env);

//utils.c
void	free_minishell(t_data *data);
void	free_array(char **array);
void	free_list(t_token **lst);
void	check_type(t_token *token);

//list.c
t_token	*new_token(char *str, int i);
void	token_add_back(t_token **lst, t_token *new);
void	create_add_token(t_data *data);

//builtins.c
int		exec_builtin(t_token *token, t_data *data);
int		is_builtin(char *cmd);
int		builtin_echo(t_token *token);
int		builtin_exit(t_data *data);
int		builtin_pwd(void);

//lbft
char	*ft_str_threejoin(char const *s1, char const *s2, char const *s3);

//debug.c
void	print_token(t_data *data);

#endif