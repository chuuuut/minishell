/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:57:03 by chdoe             #+#    #+#             */
/*   Updated: 2025/07/15 12:56:26 by chdoe            ###   ########.fr       */
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

#endif