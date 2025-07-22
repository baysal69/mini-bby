#include "../include/minishell.h"

void echo(t_token *head)
{
	t_token *word;
	char *s;
	int nl_flag;

	if (!head)
	{
		printf("invalid\n");
		return ;
	}
	//	int count;
	s = malloc(token_len(head));
	s[0] = '\0';
	nl_flag = check_nl(head);
//	count = count_redirect(head);
	word = check_redirect(head);
	if (nl_flag)
		head = head->next;
	if (word)
	{
		redirect_occur(head, word, s, nl_flag);
	}
	else
	{
   		while (head)
		{
			printf("%s", head->token);
	   	 	if (head->next)
				putchar(' ');
			head = head->next;
		}
		if (nl_flag == 0)
			putchar('\n');
	}
	free(s);
}

void pwd(t_token *head) // should accept no arguments
{
	char *s;
	t_token *word;

	s = getcwd(NULL,0); // protect this
	word  = check_redirect(head);
	if (word)
	{
		if (redirect_type(word) == 1)
			echo_file(head, s, 0);
		else if (redirect_type(word) == 2)
			append_file(head, s, 0);
	}
	else
		printf("%s\n", s);
}

void cd(t_token *head)
{
	char *path;

	if (head->next == NULL)
	{
		path = getenv("HOME");
		if (!path)
		{
			printf("cd: HOME not set\n");
			return ;
		}
	}
	else
		path = head->next->token;
	if (chdir(path))
		perror("cd");
	//printf(RED"Invalid director or path isn't relative or absolute\n"RESET);
}
