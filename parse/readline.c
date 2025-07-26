#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../includes/minishell.h"


int	is_prompt_space(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			len++;
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}

int	main(void)
{
	char	*line;

	using_history();
	while((line = readline("> ")) != NULL)
	{
		if (is_prompt_space(line))
			continue ;
		printf("result : %s\n", line);
		add_history(line);
		free(line);
	}
	clear_history();
	return (0);
}