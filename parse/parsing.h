/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:57:03 by chdoe             #+#    #+#             */
/*   Updated: 2025/07/29 18:53:18 by chdoe            ###   ########.fr       */
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

typedef struct s_quotes
{
	int		i;
	bool	odd_d_quote;
	bool	odd_s_quote;
	bool	open_s_quote;
	bool	open_d_quote;
	int		first_quote;
	bool	char_quote;
}	t_quotes;

//				READLINE
int		is_prompt_space(char *line);
//				SIGNALS
void    sh_ctrlc_behave(int signal);
void	get_signal(void);
//				SYNTAX
int		is_char_space(char *line);
int		nb_of_pipes(char *line);
int		check_empty_pipes(char *line);
//				PARSING UTILS
void	ft_free_tab(char **str);
int		ft_tablen(char **tab);
//				OPEN QUOTES
void	init_quotes(t_quotes *quotes);
char	first_quote(char *str);
int		quotes_status(char *str, t_quotes *quotes, char c);
char	is_quote_closed(t_quotes *quotes, char *str);
//				PARSING ERRORS
int		syntax_error(char *line, t_quotes *quotes);

#endif
