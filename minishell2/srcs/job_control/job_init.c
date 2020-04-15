#include "jobs.h"
#include "signals.h"
#include <sys/types.h>

void	init_shell(void)
{
	g_first_job = NULL;
	g_isatty = isatty(STDIN_FILENO);
	g_can_exit = 0;
	if (g_isatty)
	{
		signals_setup();
	}
	g_isatty = 0;
}
