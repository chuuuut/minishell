/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:31:57 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/22 20:02:00 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// - simples et doubles quotes verif bien fermees

// qu'est-ce qu'un expand ?
//  remplace la variable d'environnement par le chemin absolu
// "" -> expand
// '' -> pas d'expand

// • Handle single quote -> prevent shell from interpreting the			Chloe
// metacharacters in the quoted sequence.

// • Handle double quotes -> prevents shell from interpreting the		Chloe
// metacharacters in the quoted sequence except for $.

// structure où on sait quand on est dans une single quote avec un booléen
//<3<3<3

char	first_quote(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			if (line[i] == '\'')
				return ('\'');
			else if (line[i] == '\"')
				return ('\"');
		}
		i++;
	}
	return (0);
}

int	quotes_status(char *line, t_quotes *quotes, char c)
{
	int	i;

	i = 1;
	if (c == '\"')
		quotes->open_d_quote = true;
	else
		quotes->open_s_quote = true;
	while (line[i] != c && line[i])
		i++;
	if (line[i] == c && line[i])
	{
		if (c == '\"')
			quotes->open_d_quote = false;
		else
			quotes->open_s_quote = false;
		i++;
	}
	return (i);
}

char	is_quote_closed(t_quotes *quotes, char *line, int end)
{
	int	i;

	i = 0;
	while (line[i] && i < end)
	{
		if (first_quote(&line[i]) == '\"' && line[i] == '\"')
			i += quotes_status(&line[i], quotes, '\"');
		else if (first_quote(&line[i]) == '\'' && line[i] == '\'')
			i += quotes_status(&line[i], quotes, '\'');
		i++;
	}
	if (quotes->open_d_quote == true)
		return ('\"');
	else if (quotes->open_s_quote == true)
		return ('\'');
	return (0);
}

