/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:31:20 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/25 17:41:30 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_len_expand(char *line, t_quotes *quotes, char **env)
{
	size_t	i;
	size_t	len_exp;
	size_t	start;

	i = 0;
	if (!line)
		return (0);
	len_exp = ft_strlen(line);
	while (i < ft_strlen(line))
	{
		while (line[i] && line[i] != '$')
			i++;
		if (line[i])
			i++;
		start = i;
		while (line[i] && !(is_quote_closed(quotes, line, i) == '\'') \
			&& !is_stop_exp(line[i]))
			i++;
		if ((is_quote_closed(quotes, &line[i], ft_strlen(&line[i])) != '\''))
			len_exp += (len_var(i, line, env, start));
		i++;
	}
	return (len_exp);
}

size_t	len_var(size_t i, char *line, char **env, size_t start)
{
	size_t	j;
	char	*exp;
	char	*exp_first;
	size_t	len_exp;

	j = 0;
	len_exp = 0;
	while (line[i + j] && line[i + j] != '$' && is_stop_exp(line[i + j]) \
		&& i + j < ft_strlen(line))
		j++;
	exp_first = ft_substr(line, start, j);
	if (!exp_first)
		return (-1);
	exp = ft_strjoin(exp_first, "=");
	free (exp_first);
	if (!exp)
		return (-1);
	j = 0;
	while (env[j] && line[i])
	{
		if (ft_strnstr(env[j], exp, ft_strlen(exp)))
			len_exp = len_exp + (ft_strlen(env[j]) - (ft_strlen(exp) * 2));
		j++;
	}
	free(exp);
	return (len_exp);
}

int	is_stop_exp(char c)
{
	int			i;
	static char	*check;

	i = 0;
	check = " \"$'[]%=/0123456789><\0";
	while (i != 22)
	{
		if (check[i] == c || (c >= 97 && c <= 122))
			return (0);
		i++;
	}
	return (1);
}

size_t	expand_var(char *line, char *exp, char **env)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*exp_var;
	char		*exp_first;

	i = 0;
	k = 0;
	while (line[i] && is_stop_exp(line[i]))
		i++;
	exp_first = ft_substr(line, 0, i);
	if (!exp_first)
		return (-1);
	exp_var = ft_strjoin(exp_first, "=");
	free(exp_first);
	if (!exp_var)
		return (-1);
	j = 0;
	while (env[j])
	{
		if (ft_strnstr(env[j], exp_var, ft_strlen(exp_var)))
			break ;
		j++;
	}
	if (!env[j])
	{
		free (exp_var);
		return (0);
	}
	i++;
	while (env[j][i])
	{
		exp[k] = env[j][i];
		i++;
		k++;
	}
	free(exp_var);
	return (k);
}

char	*expand_quotes(char *line, t_quotes *quotes, char **env)
{
	size_t	i;
	size_t	j;
	size_t	len_exp;
	char	*exp;

	i = 0;
	j = 0;
	len_exp = ft_len_expand(line, quotes, env);
	exp = NULL;
	if (len_exp)
		exp = malloc(sizeof(char) * (len_exp + 1));
	if (!exp)
		return (NULL);
	while (i < ft_strlen(line))
	{
		while (line[i] && (line[i] != '$' \
			|| is_quote_closed(quotes, &line[i], ft_strlen(&line[i])) == '\''))
		{
			exp[j] = line[i];
			i++;
			j++;
		}
		if (line[i])
			i++;
		j += expand_var(&line[i], &exp[j], env);
		while (line[i] && is_stop_exp(line[i]))
			i++;
	}
	exp[len_exp] = 0;
	if (exp)
		return (exp);
	return (line);
}
