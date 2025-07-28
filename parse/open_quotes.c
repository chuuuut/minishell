/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:31:57 by chdoe             #+#    #+#             */
/*   Updated: 2025/07/28 18:38:40 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
// - simples et doubles quotes verif bien fermees

// qu'est-ce qu'un expand ?
//  remplace la variable d'environnement par le chemin absolu
// "" -> expand
// '' -> pas d'expand

/*
"'		-> " open
'"		-> ' open
""'		-> ' open
''"		-> " open
"'"'	-> ' open
'"'"	-> " open
"'"'"	-> ' open
'"'"'	-> " open
*/

void	init_quotes(t_quotes *quotes)
{
	quotes->open_d_quot = false;
	quotes->open_s_quot = false;
	quotes->odd_s_quot = false;
	quotes->odd_d_quot = false;
}

char	first_quote(char *str)
{
	// strchr (34)
	// strchr (39)
	// strlen du strchr 34
	// strlen du strchr 39
	// comparer les len et le plus long est le premier
}

char	is_quote_closed(t_quotes *quotes, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 39)
		{
			if (quotes->open_s_quot == false)
				quotes->open_s_quot == true;
			if (quotes->open_s_quot == true)
				quotes->open_s_quot == false;
		}
		if (str[i] == 34)
		{
			if (quotes->open_d_quot == false)
				quotes->open_d_quot == true;
			if (quotes->open_d_quot == true)
				quotes->open_d_quot == false;
		}
		i++;	
	}
		if (quotes->odd_d)
	return (39);		//	'
	return (34);		//	"
	return (NULL);
//		code erreur : 127 quand je ferme avec quote
//		code erreur : 2 quand Ctrl + D
}


