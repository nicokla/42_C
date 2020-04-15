#include "builtins.h"
#include "hashmap.h"
#include "signals.h"
#include "jobs.h"
#include "input.h"
#include "newstuff.h"

int				g_isatty;
int				g_can_exit;

int			is_full_of_whitespaces(const char *input)
{
	int		i;

	if (!input)
		return (1);
	i = -1;
	while (input[++i])
	{
		if (!ft_is_white_space(input[i]))
			return (0);
	}
	return (1);
}

/*
**	Initialize variables, read input with input_loop.
**	If reading input fails or first byte of input is 0, exits.
**	Else, calls handle_input for lexing, creating and executing the AST.
**	On exit, writes history and frees everything that was previously allocated.
*/

int			main(int argc, char **argv, char **env)
{
	t_st_cmd		*st_cmd;
	t_vars			vars;
	t_cmd cmd;

	init_shell();
	if (init_vars(&vars, argc, argv, env) == 1)
		return (EXIT_FAILURE);
	st_cmd = init_st_cmd((const char **)vars.env_vars);
	get_st_cmd(&st_cmd);
	while (42)
	{
		prompt(&cmd);
		ft_complete_cmd(&cmd);
		st_cmd->st_txt->txt = cmd.get_line;
		if (!ft_strequ(st_cmd->st_txt->txt, "") && 
			!is_full_of_whitespaces(st_cmd->st_txt->txt))
			vars.cmd_value = handle_input(st_cmd, &vars);
		do_job_notification(0, DEFAULT);
		st_cmd = reset_st_cmd(st_cmd, &vars);
	}
	return (0);
}
