/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:56:45 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/20 14:07:18 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_builtin(t_cmd *cmd)
{
	const char	*builtins[7] = {"echo", "pwd", "cd", "export", "unset",
		"env", "exit"};
	int			i;

	i = -1;
	while (++i < 7)
		if (ft_strcmp(cmd->argv[0], builtins[i]) == 0)
			return (1);
	return (0);
}

void	exec_env(t_cmd *cmd)
{
	int		len;
	int		i;

	len = arr_len(cmd->argv);
	if (len != 1)
	{
		ft_putendl_fd("env: too many arguments", 1);
		*get_exit_status() = 1;
	}
	else
	{
		i = -1;
		while (get_env()->a[++i])
			ft_putendl_fd(get_env()->a[i], 1);
		*get_exit_status() = 0;
	}
}

void	exec_builtin(t_cmd *cmd)
{
	if (ft_strcmp(cmd->argv[0], "echo") == 0)
		exec_echo(cmd);
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		exec_pwd(cmd);
	else if (ft_strcmp(cmd->argv[0], "cd") == 0)
		exec_cd(cmd);
	else if (ft_strcmp(cmd->argv[0], "export") == 0)
		exec_export(cmd);
	else if (ft_strcmp(cmd->argv[0], "unset") == 0)
		exec_unset(cmd);
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		exec_env(cmd);
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		exec_exit(cmd);
}
