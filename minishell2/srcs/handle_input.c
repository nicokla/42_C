#include "lexer.h"
#include "ast.h"
#include "cmd_parsing.h"
#include "execution.h"

static int		handle_execution(t_st_cmd *st_cmd, t_token *token_head,
	t_vars *vars)
{
	int			ret;
	t_ast		*ast_root;

	(void)st_cmd;
	ast_root = create_ast(token_head);
	ret = exec_ast(ast_root, vars, 1);
	free_ast(ast_root);
	return (exit_status(ret));
}

/*
** handle_input
** 1. get token_list from input
** 2. store input to history
** 3. get ast from token_list
** 4. execute ast
** 5. free ast
*/

int				handle_input(t_st_cmd *st_cmd, t_vars *vars)
{
	t_token			*tk;
	int				lexer_ret;
	int				ret;
	char			*input;

	tk = NULL;
	if (!(input = concatenate_txt(st_cmd, 1)))
		return (1);
	if (is_full_of_whitespaces(input))
	{
		ft_strdel(&input);
		return (0);
	}
	lexer_ret = lexer(input, &tk, vars);
	ft_strdel(&input);
	if (lexer_ret >= lex_fail)
	{
		free_token_list(tk);
		return (lexer_ret);
	}
	ret = handle_execution(st_cmd, tk, vars);
	return (ret == 254 ? 1 : ret);
}
