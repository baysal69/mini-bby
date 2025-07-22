#include "../include/minishell.h"

int redirect_type(t_token *head)
{
	if (!head || !head->token)
		return (0);
	if (head->token[0] == '>')
	{
		if (head->token[1] == '>')
			return (2);
		return (1);
	}
	else if (head->token[0] == '<')
	{
		if (head->token[1] == '<')
			return (4);
		return (3);
	}
	return (0);
}

int redirect_occur(t_token *head, t_token *word, char *s, int nl_flag)
{
	t_token *tmp;
	
	tmp = head;
	if (word && (redirect_type(word) == 1))
	{
		while (tmp != word)//word is redir
		{
			ft_strcat(s, tmp->token);
			if (tmp->next != word)
				ft_strcat(s," ");
			tmp = tmp->next;
		}
		outfile(head, s, nl_flag);
		return (1);
	}
	else if (word && (redirect_type(word) == 2))
	{
		while (tmp != word)
		{
			ft_strcat(s, tmp->token);
			if (tmp->next != word)
				ft_strcat(s," ");
			tmp = tmp->next;
		}
		append_file(head, s, nl_flag);
		return (1);
	}
	else if (word && (redirect_type(word) == 3))
	{
		while (tmp != word)
		{
			ft_strcat(s, tmp->token);
			if (tmp->next != word)
				ft_strcat(s," ");
			tmp = tmp->next;
		}
		infile(head, s, nl_flag);
		return (1);
	}
	else if (word && (redirect_type(word) == 4))
	{
		while (tmp != word)
		{
			ft_strcat(s, tmp->token);
			if (tmp->next != word)
				ft_strcat(s," ");
			tmp = tmp->next;
		}
		heredoc(head, s, nl_flag);
		return (1);
	}
	return (0);
}

void outfile(t_token *head, char *s, int flag)  // input '>'
{
	t_token *tmp;
	int fd;

	while (head)
	{
		tmp = check_redirect(head);
		if (tmp)
		{
			fd = open(tmp->next->token, O_CREAT | O_RDWR | O_TRUNC, 0644);
			ft_putstr_fd(s, fd);
			head = head->next;
			if (!flag)
				ft_putstr_fd("\n", fd);
		}
		head = head->next;
	}
}

void heredoc(t_token *head, char *s, int flag)
{
	t_token *tmp;
	int fd;

	tmp = check_redirect(head);
	if (tmp && tmp->next)
	{
		fd = ft_atoi(tmp->next->token);
		if (fd == -1)
		{
			perror("invalid heredoc fd");
			return (1);
		}
		ft_putstr_fd(s,fd);
		if (!flag)
			ft_putstr_fd("\n",fd);
	}
	head = head->next;
}

void infile(t_token *head, char *s, int flag)
{
	t_token *tmp;
	int fd;

	tmp = check_redirect(head);
	if (tmp && tmp->next)
	{
		fd = open(tmp->next->token, O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			return (1);
		}
		ft_putstr_fd(s,fd);
		if (!flag)
			ft_putstr_fd("\n",fd);
	}
	head = head->next;
}

void append_file(t_token *head, char *s, int flag)  // append ">>"
{
	t_token *tmp;
	int fd;

	tmp = check_redirect(head);
	if (tmp && tmp->next)
	{
		fd = open(tmp->next->token, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd == -1)
		{
			perror("open");
			return (1);
		}
		ft_putstr_fd(s,fd);
		if (!flag)
			ft_putstr_fd("\n",fd);
	}
	head = head->next;
}
