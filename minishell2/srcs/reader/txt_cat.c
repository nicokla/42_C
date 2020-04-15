#include "input.h"
#include "cmd_parsing.h"

static void	clean_and_check(t_st_cmd *st_cmd, char *tmp, char **input)
{
	if (!ft_strequ(st_cmd->st_txt->txt, tmp))
		ft_dprintf(1, "%s", st_cmd->st_txt->txt);
	if (!(*input = ft_strjoin_free_left(*input, st_cmd->st_txt->txt)))
		clean_exit(1, MALLOC_ERR);
	ft_strdel(&tmp);
}

/*
**	Returns a string containing all string contents in the st_cmd list.
*/

char		*concatenate_txt(t_st_cmd *st_cmd, int mode)
{
	char	*input;
	char	*tmp;

	if (!st_cmd)
		return (NULL);
	st_cmd = get_first_st_cmd(st_cmd);
	if (!(input = ft_strdup("")))
		clean_exit(1, MALLOC_ERR);
	while (st_cmd)
	{
		if (!(tmp = ft_strdup(st_cmd->st_txt->txt)))
			clean_exit(1, MALLOC_ERR);
		if (g_isatty && mode == 1)
		{
			free(input);
			if (!(input = ft_strnew(0)))
				clean_exit(1, MALLOC_ERR);
			ft_strdel(&tmp);
			return (input);
		}
		clean_and_check(st_cmd, tmp, &input);
		st_cmd = st_cmd->next;
	}
	return (input);
}

