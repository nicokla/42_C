/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:56:56 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/20 13:56:57 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_echo(t_cmd *cmd)
{
	int i;
	int	j;

	*get_exit_status() = 0;
	j = 0;
	i = 1;
	if (cmd->argv[1] && ft_strcmp(cmd->argv[1], "-n") == 0)
	{
		i++;
		j++;
	}
	while (cmd->argv[i])
	{
		ft_putstr(cmd->argv[i]);
		i++;
		if (cmd->argv[i])
			ft_putstr(" ");
	}
	if (!j)
		ft_putchar('\n');
}
