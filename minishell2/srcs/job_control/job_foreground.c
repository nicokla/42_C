#include "jobs.h"
#include <signals.h>
#include <stdio.h>
#include <errno.h>

static void	put_error(char *str)
{
	ft_dprintf(2, SHELL_NAME " : %s\n", str);
}

static int	wait_and_reset(t_job *j)
{
	int			ret;
	t_process	*p;

	p = j->first_process;
	while (p)
	{
		p->stopped = 0;
		p = p->next;
	}
	j->notified = 0;
	j->fg = 1;
	j->bg = 0;
	ret = wait_for_job(j, WUNTRACED);
	return (ret);
}

int			put_job_in_foreground(t_job *j, int cont)
{
	if (cont)
	{
		if (kill(-j->pgid, SIGCONT) < 0)
			put_error("error with sending continue signal");
	}
	return (wait_and_reset(j));
}
