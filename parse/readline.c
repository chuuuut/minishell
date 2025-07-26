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

	get_signal();
	while((line = readline("> ")) != NULL)
	{
		if (is_prompt_space(line))
			continue ;
		printf("result : %s\n", line);
		printf("%d\n", check_empty_pipes(line));
		add_history(line);
		free(line);
	}
	rl_clear_history();
	return (0);
}