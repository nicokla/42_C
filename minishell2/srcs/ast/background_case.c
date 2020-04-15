#include "jobs.h"
#include "cmd_parsing.h"

static int	background_exec(t_ast *root, t_vars *vars)
{
	t_job	*j;

	if (!root)
		return (0);
	j = append_job(&g_first_job, create_job(root, 0,
				get_last_num(g_first_job) + 1));
	return (parse_cmdline(root, vars, 0));
	return (0);
}

int			background_case(t_ast *root, t_vars *vars, int fg)
{
	if (!root || !root->left)
		return (1);
	if (root->left->token->type == tk_amp)
		background_case(root->left, vars, 0);
	else
		background_exec(root->left, vars);
	if (fg)
		exec_ast(root->right, vars, 1);
	else
		background_exec(root->right, vars);
	return (0);
}
