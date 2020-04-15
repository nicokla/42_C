#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdlib.h>

typedef struct			s_vars
{
	char				**env_vars;
	char				**shell_vars;
	char				**env_save;
	char				**env_exported;
	struct s_hashmap	*hashmap;
	char				**assign_tab;
	char				*copy;
	size_t				select_start;
	size_t				select_end;
	int					select_mode;
	int					is_cr_sqt;
	int					interrupted;
	int					cmd_value;
	int					verbose;
	char				pad[4];
}						t_vars;

#endif
