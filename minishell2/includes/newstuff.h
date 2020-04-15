#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "input.h"

#define GET_C_BUFF_SIZE 1024
#define BUFF_SIZE 1024
#define SIZE 100

typedef struct		s_comms
{
	char			**user_comm;
	char			*get_line;
}					t_cmd;

void	prompt(t_cmd *cmd);
void	ft_complete_cmd(t_cmd *cmd);
void			free_st_cmd(t_st_cmd *st_cmd);
void			free_all_st_cmds(t_st_cmd **st_cmd);
