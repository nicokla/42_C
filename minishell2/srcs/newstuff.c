#include "newstuff.h"


void	*ft_realloc2(void *ptr, size_t len)
{
	void	*real;

	real = (void *)malloc(len);
	if (real)
	{
		memset(real, 0, len);
		memcpy(real, ptr, strlen(ptr));
	}
	free(ptr);
	return (real);
}


int	ft_getchar(const int fd)
{
	static char	buff[GET_C_BUFF_SIZE];
	static char	*chr;
	static int	pos = 0;
	static int	ret = 0;

	if (pos >= ret)
	{
		if ((ret = read(fd, buff, GET_C_BUFF_SIZE)) > 0)
		{
			chr = buff;
			pos = 0;
			return (*(chr + pos++));
		}
		else
		{
			return (0);
		}
	}
	else
	{
		return (*(chr + pos++));
	}
}

int	ft_get_line_helper(char *text, int buf_size, char **line, const int fd)
{
	int		position;
	int		c;

	position = 0;
	while (1)
	{
		c = ft_getchar(fd);
		if (c == 0 || c == '\n')
		{
			text[position] = '\0';
			*line = text;
			return (1);
		}
		else
			text[position] = c;
		position++;
		if (position >= buf_size)
		{
			buf_size += BUFF_SIZE;
			text = ft_realloc2(text, buf_size);
			if (!text)
				return (-1);
		}
	}
	return (1);
}

int	get_next_line2(const int fd, char **line)
{
	char	*text;
	int		buf_size;

	buf_size = BUFF_SIZE;
	text = (char *)malloc(sizeof(char) * buf_size);
	if (fd < 0 || !text || !line)
		return (-1);
	return (ft_get_line_helper(text, buf_size, line, fd));
}

char	*ft_get_current_dir(void)
{
	char	*cwd;
	int		i;
	char	*home;
	char	*dir;

	cwd = NULL;
	home = getenv("HOME");
	cwd = getcwd(NULL, 0);
	dir = ft_memalloc(ft_strlen(cwd) + 1);
	ft_memset(dir, 0, ft_strlen(cwd) + 1);
	if (ft_strequ(cwd, home))
		ft_strcpy(cwd, "~");
	i = ft_strlen(cwd);
	while (i)
	{
		if (cwd[i--] == '/')
		{
			i += 2;
			break ;
		}
	}
	ft_strcpy(dir, cwd + i);
	free(cwd);
	return (dir);
}

void	ft_cmd_prompt(void)
{
	char	*dir;

	dir = ft_get_current_dir();
	ft_putstr("\33[2K\r");
	ft_putstr(GREEN);
	ft_putstr("[");
	ft_putstr(CYAN);
	ft_putstr(dir);
	ft_putstr(GREEN);
	ft_putstr("]$ ");
	ft_putstr(RESET);
	free(dir);
}

int		ft_uneven(char *str)
{
	int	countsingle;
	int	countdouble;

	countsingle = 0;
	countdouble = 0;
	while (*str)
	{
		if (*str == '\"')
			countdouble++;
		if (*str == '\'')
			countsingle++;
		str++;
	}
	if ((countdouble % 2 == 0) && (countsingle % 2 == 0))
		return (0);
	else
		return (1);
}

void	prompt(t_cmd *cmd)
{
	cmd->get_line = ft_memalloc(BUFF_SIZE);
	ft_memset(cmd->get_line, 0, BUFF_SIZE);
	ft_cmd_prompt();
	get_next_line2(0, &cmd->get_line);
}

void	ft_check_eof(int read_value, t_cmd *cmd)
{
	if (read_value == 0)
	{
		ft_putendl("minishell: unexpected EOF while looking for matching `\"'");
		ft_putendl("minishell: syntax error: unexpected end of file");
		cmd->get_line = "";
		return ;
	}
}

void	ft_complete_cmd(t_cmd *cmd)
{
	char	complete[BUFF_SIZE];
	char	line[SIZE];
	int		retvalue;

	ft_memset(complete, 0, BUFF_SIZE);
	ft_memset(line, 0, SIZE);
	if (ft_uneven(cmd->get_line))
	{
		ft_putstr("> ");
		ft_strcpy(complete, cmd->get_line);
		while ((retvalue = read(0, line, SIZE)))
		{
			ft_strcat(complete, "\n");
			ft_strncat(complete, line, ft_strlen(line) - 1);
			ft_memset(line, 0, SIZE);
			if (!ft_uneven(complete))
				break ;
			ft_putstr("> ");
		}
		ft_strcpy(cmd->get_line, complete);
		ft_check_eof(retvalue, cmd);
	}
}
