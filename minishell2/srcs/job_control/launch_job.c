#include "signals.h"
#include "jobs.h"

static int	return_value_of_job(t_job *j, int foreground)
{
	if (!g_isatty)
		return (wait_for_job(j, 0));
	else if (foreground)
		return (put_job_in_foreground(j, 0));
	else
	{
		put_job_in_background(j, 0);
		if (j->forked)
			return (wait_for_job(j, 0));
		return (0);
	}
}

int			launch_job(t_job *j, int foreground)
{
	t_process	*p;
	int			ret;
	int			mypipe[2];
	int			fds[2];

	g_can_exit = 0;
	fds[0] = STDIN_FILENO;
	ft_bzero(mypipe, sizeof(int) * 2);
	p = j->first_process;
	fork_and_launch_process(j, fds, mypipe, foreground);
	ret = return_value_of_job(j, foreground);
	if (WIFSIGNALED(ret))
	{
		if (WTERMSIG(ret) == SIGPIPE && j)
			ret = last_process_status(j->first_process);
		else if ((j->forked || j->fg) && WTERMSIG(ret) != SIGINT)
			ft_dprintf(2, "%s\n", get_signal_str(ret));
	}
	return (ret);
}
