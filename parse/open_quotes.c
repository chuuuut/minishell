/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:31:57 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/05 18:22:28 by chdoe            ###   ########.fr       */
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

void	init_quotes(t_quotes *quotes)
{
	quotes->open_d_quote = false;
	quotes->open_s_quote = false;
	quotes->odd_s_quote = false;
	quotes->odd_d_quote = false;
}

char	first_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			if (str[i] == '\'')
				return ('\'');
			else if (str[i] == '\"')
				return ('\"');
		}
		i++;
	}
	return (0);
}

int	quotes_status(char *str, t_quotes *quotes, char c)
{
	int	i;

	i = 1;
	if (c == '\"')
		quotes->open_d_quote = true;
	else
		quotes->open_s_quote = true;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == c && str[i])
	{
		if (c == '\"')
			quotes->open_d_quote = false;
		else
			quotes->open_s_quote = false;
		i++;
	}
	return (i);
}

char	is_quote_closed(t_quotes *quotes, char *str, int end)
{
	int	i;

	i = 0;
	while (str[i] && i < end)
	{
		if (first_quote(&str[i]) == '\"' && str[i] == '\"')
			i += quotes_status(&str[i], quotes, '\"');
		else if (first_quote(&str[i]) == '\'' && str[i] == '\'')
			i += quotes_status(&str[i], quotes, '\'');
		i++;
	}
	if (quotes->open_d_quote == true)
		return ('\"');
	else if (quotes->open_s_quote == true)
		return ('\'');
	return (0);
}

// int	main(void)
// {
// 	t_quotes	*quotes;

// 	quotes = malloc(sizeof(t_quotes));
// 	if (!quotes)
// 		return (errno);
// 	init_quotes(quotes);
// 	printf("%c\n", is_quote_closed(quotes, ""));
// 	free(quotes);
// 	return (0);
// }