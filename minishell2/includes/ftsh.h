#ifndef FTSH_H
# define FTSH_H

# include "structures.h"
# include "libft.h"
# include <sys/types.h>

# define SHELL_NAME "minishell"
# define SHELL_COLOR "\x1b[38;5;226m"
# define DIR_COLOR "\x1b[38;5;84m"
# define STATUS_COLOR "\x1b[38;5;196m"

typedef enum		e_exit
{
	EXIT,
	MALLOC_ERR,
	FORCE,
	NORESET
}					t_exit;

extern int				g_isatty;
extern int				g_can_exit;
/*
**	t_vars utility functions
*/

t_vars		*get_vars(t_vars *new_vars);
void		free_vars(t_vars *vars);
int			init_vars(t_vars *vars, int argc, char **argv, char **env);
void		reset_copy_vars(t_vars *vars);
void		ft_memdel_ntab(char ***ntab);

/*
**	File descriptors funcs
*/

void		save_reset_stdfd(int mode);

/*
**	String tool
*/

void		print_introduction(void);
int			is_full_of_whitespaces(const char *input);
void		clean_exit(int exitno, t_exit reason);

char		*ft_strjoin_free_left(char *s1, const char *s2);
#endif
