/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:57:03 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/22 17:32:58 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "./Libft/libft.h"

typedef struct	s_cmd
{
	char			*cmd;
	char			**args;
	char			**infile; 
	char			**outfile;
	struct s_cmd	*next;
	// On met un char ** car il y a besoin de tout les fichiers IN et OUT
	// pour bien gerer les erreurs durant l'execution
}	t_cmd;

typedef struct	s_quotes
{
	int		i;
	bool	odd_d_quote;
	bool	odd_s_quote;
	bool	open_s_quote;
	bool	open_d_quote;
	int		first_quote;
	bool	char_quote;
}	t_quotes;

typedef struct	s_inout_ope
{
	bool	is_file;
	bool	is_cmd;
}	t_inout_ope;

//				READLINE
int		is_prompt_space(char *line);
//				SIGNALS
void    sh_ctrlc_behave(int signal);
void	get_signal(void);
//				PIPES
int		is_char_space(char *line);
int		nb_of_pipes(char *line);
int		check_empty_pipes(char *line);
//				PARSING UTILS
void	ft_free_tab(char **str);
int		ft_tablen(char **tab);
int		is_space(char c);
int		is_bad_redirect(char c);

//				OPEN QUOTES
char	first_quote(char *line);
int		quotes_status(char *line, t_quotes *quotes, char c);
char	is_quote_closed(t_quotes *quotes, char *line, int end);
//				PARSING ERRORS
int		syntax_error(char *line, t_quotes *quotes);
//				REDIRECT
//		faire une fonction protectrice au cas-où la str est vide
int		triple_in(char *line, t_quotes *quotes);
int		triple_out(char *line, t_quotes *quotes);
int		redirect_inout(char *line, t_quotes *quotes);
int		append_inout(char *line, t_quotes *quotes);
//				EXPAND_QUOTES
size_t	ft_len_expand(char *line, t_quotes *quotes, char **env);
size_t	is_end_expand(char c);
char	*expand_quotes(char *line, t_quotes *quotes, char **env);
size_t		len_expand_var(size_t i, char *line, char **env, size_t start);
//				INIT_VAR
void	init_inout(t_inout_ope *inout);
void	init_quotes(t_quotes *quotes);

#endif
