#include "../include/minishell.h"

t_token *create_token(const char *str)
{
    t_token *token = malloc(sizeof(t_token));
    if (!token)
        return NULL;
    token->token = strdup(str);  // MUST use strdup to copy string
    if (!token->token)
    {
        free(token);
        return NULL;
    }
    token->next = NULL;
    return token;
}

t_token	*ft_lstlast(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	insert_token(t_token **lst, t_token *new)
{
	t_token *last;

	if (!lst || !new)
		return ;
	last = ft_lstlast(*lst);
	if (*lst)
	{
		last->next = new;
		new->prev = last;
	}
	else
		*lst = new;
}

int	count_input(char *input)
{
	int i;
	int k;
	int l;
	char countspace;
	
	countspace = 0;
	i = 0;
	k = 1;
	l = 0;
	while(input[i])
	{
		if(input[i] == '\"')
		{
			l++;
		}
		if(input[i] == ' ' && countspace)
		{
			k++;
			countspace = 0;
			while(input[i] == ' ')
				i++;
		}
		else
		{
			countspace = 1;
			i++;
		}
	}
	if(i == 0 || input[--i] == ' ')
		k--;
	l /= 2;
	return k + l;
}

void append_token(t_token **head, t_token *new_tok)
{
    if (!*head)
    {
        *head = new_tok;
        return;
    }
    t_token *curr = *head;
    while (curr->next)
        curr = curr->next;
    curr->next = new_tok;
}

void do_absolutely_nothing()
{
	//nothing
}

t_token *split_input(char *input)
{
    t_token *head = NULL;
    char *word;
    char *rest = input;

    while ((word = strtok_r(rest, " ", &rest)))
    {
        t_token *new_tok = create_token(word);
        if (!new_tok)
            continue;
        append_token(&head, new_tok);
    }
    return head;
}


int unclosed_quotes(char *input)
{
	int i;
	int d_count;
	int s_count;
	
	s_count = 0;
	d_count = 0;
	i = 0;
	while(input[i])
	{
		if(input[i] == '\"')
		{
			i++;
			d_count++;
			while(input[i] && input[i] != '\"')
				i++;
			if(input[i])
				d_count++;
			else
				return (0);
		}
		if(input[i] == '\'')
                {
			i++;
                        s_count++;
                        while(input[i] && input[i] != '\'')
                                i++;
                        if(input[i])
			       	s_count++;
                        else
                                return (0);
                }
		i++;
	}
	if(s_count || d_count)
	{
		if(((s_count % 2) != 0) || ((d_count % 2) != 0))
			return (0);
	}
	return (1);
}
