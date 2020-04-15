/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:57:53 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/20 14:09:31 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*pwd(void)
{
	char *dir;

	if (!(dir = malloc(MAXPATHLEN + 1)))
		fatal_error(strerror(errno));
	getcwd(dir, MAXPATHLEN);
	return (dir);
}

void	exec_pwd(t_cmd *cmd)
{
	int		len;
	char	*p;

	len = arr_len(cmd->argv);
	if (len != 1)
	{
		ft_putendl_fd("pwd: too many arguments", 1);
		*get_exit_status() = 1;
	}
	else
	{
		p = pwd();
		ft_putendl_fd(p, 1);
		free(p);
		*get_exit_status() = 0;
	}
}

void	update_pwd(void)
{
	char	*p;

	p = pwd();
	env_set_value("PWD", p);
	free(p);
}
