#include "input.h"
#include "signals.h"

/*
**	SIGINT
**	Puts a \x03 at the beginning of txt.
**	Sets the last cmd_value to 1 (error)
**	Prints a newline on terminal
*/

void			sigint_handler(int signo)
{
	t_st_cmd	*st_cmd;
	t_vars		*vars;

	(void)signo;
	if (!(st_cmd = get_st_cmd(NULL)))
		return ;
	st_cmd = get_last_st_cmd(st_cmd);
	if ((vars = get_vars(NULL)))
		vars->cmd_value = 130;
	if (st_cmd->st_txt->txt)
		*st_cmd->st_txt->txt = '\x03';
	reset_copy_vars(vars);
	vars->interrupted = 1;
	st_cmd->st_txt->tracker = st_cmd->st_txt->data_size;
}

/*
**	SIGWINCH
**	Simply writes back the st_cmd on screen
*/

void			sigwinch_handler(int signo)
{
	t_st_cmd		*current_cmd;

	(void)signo;
	signal(SIGWINCH, SIG_IGN);
	if (!(current_cmd = get_st_cmd(NULL)))
		return ;
	current_cmd = get_last_st_cmd(current_cmd);
	signal(SIGWINCH, sigwinch_handler);
}

/*
**	SIGCONT
**	Setups terminal settings, and writes back the st cmd.
*/

void			sigcont_handler(int signo)
{
	t_st_cmd	*st_cmd;

	(void)signo;
	if (!(st_cmd = get_st_cmd(NULL)))
		return ;
	sigwinch_handler(signo);
}
