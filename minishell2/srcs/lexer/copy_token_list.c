#include "lexer.h"

t_token	*append_token(t_token **token_head, t_token *append)
{
	t_token *probe;

	if (!(*token_head))
		*token_head = append;
	else
	{
		probe = *token_head;
		while (probe->next)
			probe = probe->next;
		probe->next = append;
	}
	return (append);
}

t_token	*copy_tokens(t_token *token_head)
{
	t_token *probe;
	t_token	*cpy;
	t_token	*last_token;
	t_token	*new_token;

	if (!(probe = token_head))
		return (NULL);
	cpy = create_token(probe->content, probe->size, probe->type);
	probe = probe->next;
	last_token = cpy;
	while (probe)
	{
		new_token = create_token(probe->content, probe->size, probe->type);
		last_token->next = new_token;
		last_token = new_token;
		probe = probe->next;
	}
	return (cpy);
}
