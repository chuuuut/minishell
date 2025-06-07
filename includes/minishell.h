/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 18:30:16 by tcali             #+#    #+#             */
/*   Updated: 2025/06/07 18:13:22 by tcali            ###   ########.fr       */
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

typedef struct s_data
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd1;
	char	*cmd2;
	char	**envp;
	char	*file1;
	char	*file2;
	int		nb_tokens;
}		t_data;

//parse.c
char	**parse_line(const char *line);

//command.c
void	split_cmd(char *command, char **env, char ***args, char **path);
void	execute_command(char *command, char **env);
char	*get_command_path(char *cmd, char **env);
char	*find_command(char *cmd, char **path);

//signals.c
void	handle_sigint(int sig);

//init.c
void	init_data(t_data *data, char **tokens, char **env);

//utils.c
void	free_array(char **array);

char	*ft_str_threejoin(char const *s1, char const *s2, char const *s3);;
#endif