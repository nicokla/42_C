/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:57:45 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/20 16:05:55 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	pipe_files(int *fds, int i, int len, char **cmds)
{
	int j;

	if (*(cmds + 1))
		if (dup2(fds[i + 1], 1) < 0)
			print_error("dup2 failure");
	if (i != 0 && i != (len * 2))
		if (dup2(fds[i - 2], 0) < 0)
			print_error("dup2 failure");
	j = -1;
	while (++j < 2 * len)
		close(fds[j]);
}

void		fork_pipe(char **cmds, int *fds, int len, int i)
{
	pid_t	pid;
	t_cmd	*cmd;

	if (!(cmd = malloc(sizeof(t_cmd))))
		fatal_error(strerror(errno));
	cmd->str = ft_strdup(*cmds);
	init_file_cmd(cmd);
	get_argv(cmd);
	pid = fork();
	open_cmd_files(cmd);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		pipe_files(fds, i, len, cmds);
		dup_cmd_files(cmd);
		exec_pipe_rdir_cmd(cmd);
	}
	else if (pid < 0)
		print_error("fork failure");
	close_cmd_files(cmd);
	free(cmd->str);
	free_cmd(cmd);
}

void		handle_pipes(char **cmds)
{
	int	i[4];
	int status;
	int	len;
	int	fds[2 * arr_len(cmds)];

	len = arr_len(cmds);
	ft_memset(i, 0, 4 * sizeof(int));
	i[0] = -1;
	while (++i[0] < len)
		if (pipe(fds + (i[0] * 2)) < 0)
			print_error("pipe failure");
	while (*cmds)
	{
		fork_pipe(cmds, fds, len, i[1]);
		cmds++;
		i[1] += 2;
	}
	while (++i[2] < len * 2)
		close(fds[i[2]]);
	while (++i[3] < len + 1)
	{
		wait(&status);
		if (WIFEXITED(status))
			*get_exit_status() = WEXITSTATUS(status);
	}
}

int			has_pipes(t_cmd *cmd)
{
	char **argv;

	argv = ft_split(cmd->str, '|');
	if (arr_len(argv) == 1)
	{
		free_arr(argv);
		return (0);
	}
	cmd->argv = argv;
	return (1);
}
