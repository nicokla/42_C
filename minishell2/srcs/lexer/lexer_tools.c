#include "ftsh.h"
#include "errors.h"

/*
**	Control operators:
**	|| ! && & ; ;; | |& ( )
**	List terminators:
**	; &
**	logical operators:
**	&& || !
**	pipe operators:
**	| |&
*/

int		is_logic_or_pipe(t_token *token)
{
	if (token && token->type && (token->type == tk_or
		|| token->type == tk_and || token->type == tk_pipe))
		return (1);
	return (0);
}

int		is_two_ctrlop_or_redir_following(t_token *prev_token,
	t_token *current_token)
{
	if (!prev_token)
		return (0);
	if ((is_redir_token(prev_token)
			&& is_redir_token(current_token))
		|| (prev_token->type >= tk_pipe && current_token->type >= tk_pipe))
	{
		syntax_error_near(current_token);
		ft_memdel((void*)&current_token->content);
		ft_memdel((void*)&current_token);
		return (1);
	}
	return (0);
}

int		is_redir_token(t_token *token)
{
	if (!token)
		return (0);
	if (token->type > tk_dq_str && token->type <= tk_heredoc)
		return (1);
	return (0);
}

int		token_list_start_with_ctrl_op(t_token *prev_token,
	t_token *current_token)
{
	if (!prev_token && current_token->type >= tk_pipe)
	{
		syntax_error_near(current_token);
		ft_memdel((void*)&current_token->content);
		ft_memdel((void*)&current_token);
		return (1);
	}
	return (0);
}

/*
** create_token
** malloc the token,
** strndup(cmdline, size) into ->content,
** set ->size and ->type
** then return the token
*/

t_token	*create_token(char *cmdline, size_t size, t_token_type type)
{
	t_token	*new_token;

	if (!(new_token = (t_token*)malloc(sizeof(t_token))))
	{
		clean_exit(1, MALLOC_ERR);
		return (NULL);
	}
	new_token->size = size;
	new_token->type = type;
	new_token->next = NULL;
	if (!(new_token->content = ft_strndup(cmdline, size)))
	{
		ft_memdel((void*)&new_token);
		clean_exit(1, MALLOC_ERR);
		return (NULL);
	}
	return (new_token);
}
