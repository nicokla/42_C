/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:57:05 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/12/11 19:08:20 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_executable(char *path)
{
	struct stat	path_stat;

	ft_memset(&path_stat, 0, sizeof(struct stat));
	if ((stat(path, &path_stat) == 0) && (path_stat.st_mode & S_IXUSR)
		&& !(path_stat.st_mode & S_IFDIR))
		return (1);
	return (0);
}

void	exec_cmd(t_cmd *cmd)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		execve(cmd->argv[0], cmd->argv, get_env()->a);
	}
	else if (pid < 0)
		print_error("fork failed");
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			*get_exit_status() = WEXITSTATUS(status);
	}
}

void	dispatch_cmd(char *command)
{
	t_cmd	*cmd;

	if (!(cmd = malloc(sizeof(t_cmd))))
		fatal_error(strerror(errno));
	cmd->str = command;
	init_file_cmd(cmd);
	if (has_pipes(cmd))
		handle_pipes(cmd->argv);
	else if (has_rdir(cmd))
		handle_rdir(cmd);
	else
		run_single_cmd(cmd);
	free_cmd(cmd);
}

void	exec_pipe_rdir_cmd(t_cmd *cmd)
{
	char *exec;

	if (is_builtin(cmd))
	{
		exec_builtin(cmd);
		exit(EXIT_SUCCESS);
	}
	else if ((exec = ft_build_exec(cmd->argv[0])))
	{
		cmd->argv[0] = exec;
		if (execve(cmd->argv[0], cmd->argv, get_env()->a) == -1)
			exit(EXIT_FAILURE);
	}
	else if (is_executable(cmd->argv[0]))
		execve(cmd->argv[0], cmd->argv, get_env()->a);
	else
	{
		ft_putstr("command not found: ");
		ft_putendl_fd(cmd->argv[0], 1);
		exit(EXIT_FAILURE);
	}
}

void	run_single_cmd(t_cmd *cmd)
{
	char	*exec;

	if (is_builtin(cmd) == 1)
		exec_builtin(cmd);
	else if ((exec = ft_build_exec(cmd->argv[0])))
	{
		free(cmd->argv[0]);
		cmd->argv[0] = exec;
		exec_cmd(cmd);
	}
	else if (is_executable(cmd->argv[0]))
		exec_cmd(cmd);
	else
	{
		ft_putstr("command not found: ");
		*get_exit_status() = 127;
		ft_putendl_fd(cmd->argv[0], 1);
	}
}
