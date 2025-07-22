#include "../include/minishell.h"

int	check_overflow(char *str)
{
	int					i;
	int					sign;
	unsigned long long	num;
	unsigned long long	limit;

    i = 0;
    sign = 1;
    num = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	if (sign == -1)
		limit = (unsigned long long)LLONG_MAX + 1;
	else
		limit = LLONG_MAX;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (num > (limit - (str[i] - '0')) / 10)
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

void    ft_exit(t_token *head)
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
