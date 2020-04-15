/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:57:58 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/20 14:28:03 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		open_cmd_files(t_cmd *cmd)
{
	if (cmd->in->file)
		if ((cmd->in->fd = open(cmd->in->file, O_RDONLY)) == -1)
		{
			print_error("no such file");
			return (0);
		}
	if (cmd->out->file)
	{
		if (!(cmd->out->fd = open(cmd->out->file, O_CREAT | O_RDWR | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)))
		{
			print_error("no such file");
			return (0);
		}
	}
	else if (cmd->out_dbl->file)
		if (!(cmd->out_dbl->fd = open(cmd->out_dbl->file, O_CREAT | O_RDWR |
			O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH |
			S_IWOTH)))
		{
			print_error("no such file");
			return (0);
		}
	return (1);
}

void	dup_cmd_files(t_cmd *cmd)
{
	if (cmd->in->file)
		dup2(cmd->in->fd, STDIN_FILENO);
	if (cmd->out->file)
		dup2(cmd->out->fd, STDOUT_FILENO);
	else if (cmd->out_dbl->file)
		dup2(cmd->out_dbl->fd, STDOUT_FILENO);
}

void	close_cmd_files(t_cmd *cmd)
{
	if (cmd->in->file)
		close(cmd->in->fd);
	if (cmd->out->file)
		close(cmd->out->fd);
	else if (cmd->out_dbl->file)
		close(cmd->out_dbl->fd);
}

void	handle_rdir(t_cmd *cmd)
{
	int		pid;

	if (!open_cmd_files(cmd))
		return ;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		dup_cmd_files(cmd);
		exec_pipe_rdir_cmd(cmd);
	}
	else if (pid < 0)
		print_error("fork failed");
	else
		wait4(pid, get_exit_status(), 0, 0);
	close_cmd_files(cmd);
	wait(NULL);
}

int		has_rdir(t_cmd *cmd)
{
	get_argv(cmd);
	if (cmd->in->file || cmd->out->file || cmd->out_dbl->file)
		return (1);
	return (0);
}
