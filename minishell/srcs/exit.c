/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:47:52 by cyhuet            #+#    #+#             */
/*   Updated: 2019/11/25 12:47:54 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_exit(t_cmd *cmd)
{
	int len;

	len = arr_len(cmd->argv);
	if (len == 1)
		exit(*get_exit_status());
	else if (len == 2)
		exit(ft_atoi(cmd->argv[1]));
	else
	{
		ft_putendl("exit: too many arguments");
		*get_exit_status() = 1;
	}
}
