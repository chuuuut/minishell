/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:57:03 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/11 17:30:18 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

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
char	first_quote(char *str);
int		quotes_status(char *str, t_quotes *quotes, char c);
char	is_quote_closed(t_quotes *quotes, char *str, int end);
//				PARSING ERRORS
int		syntax_error(char *line, t_quotes *quotes);
//				REDIRECT
//		faire une fonction protectrice au cas-où la str est vide
int		redirect_in(char *str);
int		redirect_out(char *str);
int		redirect_app_in(char *str);
int		redirect_app_out(char *str);
//				EXPAND_QUOTES

//				INIT_VAR
void	init_inout(t_inout_ope *inout);
void	init_quotes(t_quotes *quotes);

#endif
