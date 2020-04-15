#include "input.h"

t_st_cmd		*append_st_cmd(t_st_cmd *st_cmd, const char *txt,
				t_st_prompt *prompt)
{
	t_st_cmd	*new;

	if (!(new = (t_st_cmd*)malloc(sizeof(*new))))
		clean_exit(1, MALLOC_ERR);
	new->st_txt = init_st_txt((const char*)txt);
	new->st_prompt = prompt;
	new->keep = st_cmd->keep;
	new->cr = st_cmd->cr;
	st_cmd->next = new;
	new->prev = st_cmd;
	new->next = NULL;
	return (new);
}

static void		init_values(t_st_cmd *st_cmd, t_vars *vars)
{
	st_cmd->keep = 1;
	st_cmd->cr = 0;
	st_cmd->is_cr_sqt = 0;
	vars->interrupted = 0;
}

t_st_cmd		*reset_st_cmd(t_st_cmd *old_st_cmd, t_vars *vars)
{
	t_st_cmd	*st_cmd;
	t_st_cmd	*left_cmd;

	if (!(st_cmd = (t_st_cmd*)malloc(sizeof(*st_cmd))))
		clean_exit(1, MALLOC_ERR);
	st_cmd->st_txt = init_st_txt(NULL);
	st_cmd->st_prompt = init_st_prompt(STD_PROMPT, STD_PROMPT, vars->cmd_value);
	init_values(st_cmd, vars);
	old_st_cmd = get_first_st_cmd(old_st_cmd);
	while (old_st_cmd)
	{
		left_cmd = old_st_cmd;
		old_st_cmd = old_st_cmd->next;
		free_st_cmd(left_cmd);
	}
	st_cmd->next = NULL;
	st_cmd->prev = NULL;
	get_st_cmd(&st_cmd);
	return (st_cmd);
}

/*
**	Function to initialize st_cmd
*/

t_st_cmd		*init_st_cmd(const char **env)
{
	t_st_cmd	*st_cmd;

	(void)env;
	if (!(st_cmd = (t_st_cmd*)malloc(sizeof(*st_cmd))))
		clean_exit(1, MALLOC_ERR);
	st_cmd->st_txt = init_st_txt(NULL);
	st_cmd->st_prompt = init_st_prompt(STD_PROMPT, STD_PROMPT, 0);
	st_cmd->is_cr_sqt = 0;
	st_cmd->keep = 1;
	st_cmd->cr = 0;
	st_cmd->next = NULL;
	st_cmd->prev = NULL;
	return (st_cmd);
}
