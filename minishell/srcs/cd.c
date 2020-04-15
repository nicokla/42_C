/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:56:50 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/20 14:02:20 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cd(t_cmd *cmd)
{
	int	len;

	len = arr_len(cmd->argv);
	*get_exit_status() = 0;
	if (len > 2)
	{
		ft_putendl_fd("cd: too many arguments", 1);
		*get_exit_status() = 1;
	}
	else if (len == 1)
	{
		if ((chdir(env_get_value("HOME"))) == -1)
			print_error("cd");
	}
	else if (len == 2)
	{
		if ((chdir(cmd->argv[1])) == -1)
			print_error("cd");
	}
	update_pwd();
}
