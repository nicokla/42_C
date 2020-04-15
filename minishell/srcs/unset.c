/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:58:07 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/20 15:32:35 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lst_remove_if(t_hash_lst **lst, char *key)
{
	t_hash_lst	*tmp;
	t_hash_lst	*i;

	while (*lst && ft_strcmp(key, (*lst)->key) == 0)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	i = *lst;
	while (i && i->next)
	{
		if (ft_strcmp(key, i->next->key) == 0)
		{
			tmp = i->next;
			i->next = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
		if (i->next)
			i = i->next;
	}
}

void	exec_unset(t_cmd *cmd)
{
	int		i;

	i = 1;
	if (!cmd->argv[1])
	{
		ft_putendl_fd("unset: not enough arguments", 1);
		*get_exit_status() = 1;
	}
	else
	{
		while (cmd->argv[i])
		{
			lst_remove_if(&get_env()->l, cmd->argv[i]);
			i++;
		}
		free_arr(get_env()->a);
		create_env_array();
		*get_exit_status() = 0;
	}
}
