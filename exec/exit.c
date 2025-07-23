#include "../include/minishell.h"

void	ft_exit(t_token *head)
{
	char *arg;

	printf("exit\n");
	if (head->next && head->next->next)
	{
		write(2, "bash: exit: too many arguments\n", 31);
		return ;//exit(1);
	}
	arg = head->next->token;
	if (check_overflow(arg) == 0)
	{
		write(2, "bash: exit: ", 12);
		write(2, arg, ft_strlen(arg));
		write(2, ": numeric argument required\n", 28);
		exit(2);
	}
	exit(0);
}
