#include "../include/minishell.h"

char	*ft_readline(void)
{
	char *input;

	input = readline(RED"➜  "RESET CYAN"~ "RESET);
	if (!input)
		return (NULL);
	if (input)
		add_history(input);
	return (input);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char *input;
	t_token **head;

	while(1)
	{
		input = ft_readline();
		if (!input)
		{
			printf("exit\n");
			//free whats has been alloced so far
			return (0);
		}
		if (*input)
		{
			if(!unclosed_quotes(input))
			{
				printf("unclosed quotes\n");
				free(input);
				return 0;
			}
			head = split_input(input);
			check_command(*head);
			//break;
		}
		free(input);
	}
	//printf("%s\n", (*head)->next->token);
	return (0);
}