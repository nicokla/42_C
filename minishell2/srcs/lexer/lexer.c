#include "ftsh.h"
#include "errors.h"
#include "lexer.h"

static int	error_unsupported_token(t_token *token, int return_val)
{
	if (!token)
		return (return_val);
	ft_dprintf(2, "%s: `%s' is not supported.\n", SHELL_NAME, token->content);
	free_token_list(token);
	return (return_val);
}

/*
** add_token_to_list
** 1. check syntax (if start with '&&', or 2 '&&' are following)
** 3. create a token_list or append it with the given token
*/

static int	add_token_to_list(t_token *current_token, t_token *prev_token,
	t_token **token_head)
{
	if (current_token->type == tk_unsupported)
		return (error_unsupported_token(current_token, 0));
	if (token_list_start_with_ctrl_op(prev_token, current_token)
		|| is_two_ctrlop_or_redir_following(prev_token, current_token)
		|| is_ctrl_op_following_a_redir_token(prev_token, current_token))
		return (0);
	if (!(*token_head))
		*token_head = current_token;
	else
	{
		if (prev_token)
		{
			while (prev_token->next)
				prev_token = prev_token->next;
			prev_token->next = current_token;
		}
	}
	return (1);
}

/*
** init_lexer
** set the variables the lexer needs
*/

static void	init_lexer(t_operation **op_chart, t_token **token_head,
	t_token **prev_token)
{
	*op_chart = get_op_chart();
	*token_head = NULL;
	*prev_token = NULL;
}

static int	lexer_final_check(t_token *current_token, t_token *prev_token)
{
	if (is_logic_or_pipe(current_token)
		|| (is_logic_or_pipe(prev_token) && current_token
				&& current_token->type == tk_eat))
		return (lex_cont_read);
	else if (prev_token && is_redir_token(prev_token)
		&& (!current_token->type || is_redir_token(current_token)))
	{
		syntax_error_near(current_token);
		return (lex_fail);
	}
	return (lex_success);
}

/*
** lexer
** - run through the cmdline and tokenize it
** - return LEX_CONT_READ when the cmdline is not complete, so handle_input()
** continue reading and append the new input to cmdline
** - return LEX_FAIL and output the message accordignly if the cmdline isn't
** valid
** - return LEX_SUCCES otherwise, so handle_input can continue
*/

int			lexer(char *cmdline, t_token **token_head, t_vars *vars)
{
	t_token			*current_token;
	t_operation		*op_chart;
	t_token			*prev_token;
	t_lexer_state	ret;

	(void)ret;
	(void)vars;
	current_token = NULL;
	prev_token = NULL;
	init_lexer(&op_chart, token_head, &prev_token);
	while (cmdline && *cmdline)
	{
		if (!(current_token = get_token(&cmdline, op_chart)))
			return (lex_cont_read);
		if (!prev_token && current_token->type == tk_eat)
		{
			free_token_list(current_token);
			continue ;
		}
		if (!(add_token_to_list(current_token, prev_token, token_head)))
			return (lex_fail);
		if (current_token->type != tk_eat)
			prev_token = current_token;
	}
	return (lexer_final_check(current_token, prev_token));
}
