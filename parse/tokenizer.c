/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:16:57 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/27 18:43:38 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// char	**tokenizer(const char *line)
// {
// 	char		**tokens;
// 	const char	*start;
// 	int			i;
// 	int			len;

// 	tokens = safe_malloc(sizeof(char *) * (count_tokens(line) + 1));
// 	i = 0;
// 	while (*line)
// 	{
// 		while (*line && is_space(*line))
// 			line++;
// 		if (!*line)
// 			break ;
// 		start = line;
// 		while (*line && !is_space(*line))
// 			line++;
// 		len = line - start;
// 		tokens[i] = ft_strndup(start, len);
// 		i++;
// 	}
// 	tokens[i] = NULL;
// 	return (tokens);
// }


// 		compter le nombre de tokens dont besoin en prenant en compre les quotes
//		/!\	les quotes simples ' n'expand pas
// 		echo "Hello $USER" | grep 'Hello' > out.txt

size_t	count_tokens(t_quotes *quotes, char *line)
{
	size_t	i;
	size_t	j;
	size_t	is_token;
	size_t	nb_token;

	i = 0;
	nb_token = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		is_token = 0;
		j = i;
		while (line[i] && !is_space(line[i]) && !is_quote_closed(quotes, &line[j], i))		//pas d'espace et pas de quotes
		{
			is_token += 1;
			i++;
		}
		if (is_token)
			nb_token += 1;
		is_token = 0;
		j = i;
		while (line [i] && is_quote_closed(quotes, &line[j], i) == '\"')	// boucle inf
		{
			is_token += 1;
			i++;
		}
		if (is_token)
			nb_token += 1;
		is_token = 0;
		j = i;
		while (line [i] && is_quote_closed(quotes, &line[j], i) == '\'')
		{
			is_token += 1;
			i++;
		}
		if (is_token)
			nb_token += 1;
		j = i;
		while (line[i] && is_space(line[i]) && !is_quote_closed(quotes, &line[j], i))		//pas d'espace et pas de quotes
			i++;
	}
	return (nb_token);
//		faire un count qui compte le nombre de mots
// 		en prenant en compte les "" et ''
}



// char	**tokenizer(t_quotes *quotes, char *line)
// {
// 	size_t	i;
// 	char	**tokens;

// 	i = 0;
// 	if (!line)
// 		return (NULL);
// 	tokens = (char **)ft_calloc(sizeof(char *), count_tokens(quotes, line) + 1);
// 	if (!tokens)
// 		return (ft_free_tab(tokens), ft_strdup(""));
// 	while (line[i])
// 	{
// 		while (is_space(line[i]))
// 			i++;

// 			while (!is_quote_closed(quotes, line, i) && !is_space(line[i]))

// 	}
// }
//		echo bon"jour "$USER'mec'

//		mot a chaque espace + les quotes
//		pour les quotes, un 


// void	ft_free(char **tab, size_t i)
// {
// 	size_t	j;

// 	j = 0;
// 	while (j < i)
// 		free(tab[j++]);
// 	free(tab);
// }

// static size_t	count_w(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	is;
// 	size_t	count;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		is = 0;
// 		while (s[i] != c && s[i])
// 		{
// 			is += 1;
// 			i++;
// 		}
// 		if (is > 0)
// 			count++;
// 		while (s[i] == c && s[i])
// 			i++;
// 	}
// 	return (count);
// }

// static size_t	len_w(char const *s, char c, size_t i)
// {
// 	size_t	j;

// 	j = 0;
// 	while (s[i] != c && s[i])
// 	{
// 		i++;
// 		j++;
// 	}
// 	return (j);
// }

// static char	*word(char const *s, char c, size_t i)
// {
// 	size_t	j;
// 	char	*sub;

// 	j = 0;
// 	sub = (char *)ft_calloc(sizeof(char), (len_w(s, c, i) + 1));
// 	if (!sub)
// 		return (NULL);
// 	while (s[i] != c && s[i])
// 	{
// 		sub[j] = s[i];
// 		i++;
// 		j++;
// 	}
// 	sub[j] = 0;
// 	return (sub);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**sep;
// 	size_t	i;
// 	size_t	j;

// 	if (!s)
// 		return (NULL);
// 	sep = (char **)ft_calloc(sizeof(char *), (count_w(s, c) + 1));
// 	if (!sep)
// 		return ((char **)ft_strdup(""));
// 	i = 0;
// 	j = 0;
// 	while (s[i] && j < count_w(s, c))
// 	{
// 		while (s[i] == c && s[i])
// 			i++;
// 		sep[j] = (word(s, c, i));
// 		if (!sep[j++])
// 			return (ft_free(sep, j), NULL);
// 		while (s[i] != c && s[i])
// 			i++;
// 	}
// 	return (sep);
// }

