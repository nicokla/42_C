/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:57:15 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/20 15:47:17 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			swap_hash(t_hash_lst *lst)
{
	char	*key;
	char	*value;

	key = lst->key;
	value = lst->value;
	lst->key = lst->next->key;
	lst->value = lst->next->value;
	lst->next->value = value;
	lst->next->key = key;
}

static t_hash_lst	*lst_sort(t_hash_lst *lst)
{
	t_hash_lst	*ptr;
	t_hash_lst	*ptr2;

	ptr = lst;
	while (ptr)
	{
		ptr2 = lst;
		while (ptr2->next)
		{
			if (ft_strcmp(ptr2->key, ptr2->next->key) > 0)
				swap_hash(ptr2);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
	return (lst);
}

static void			display_export(void)
{
	t_hash_lst	*sort;

	sort = lst_sort(get_env()->l);
	while (sort)
	{
		ft_putstr(sort->key);
		ft_putstr("=");
		ft_putstr(sort->value);
		ft_putstr("\n");
		sort = sort->next;
	}
}

void				exec_export(t_cmd *cmd)
{
	int			i;
	t_hash_lst	*tmp;
	int			eq;

	*get_exit_status() = 0;
	i = 1;
	if (!cmd->argv[1])
		display_export();
	else
	{
		while (cmd->argv[i])
		{
			if (!(tmp = malloc(sizeof(t_hash_lst))))
				fatal_error(strerror(errno));
			eq = ft_get_index(cmd->argv[i], '=');
			tmp->key = ft_substr(cmd->argv[i], 0, eq);
			tmp->value = ft_substr(cmd->argv[i], eq + 1,
								ft_strlen(cmd->argv[i]) - eq);
			tmp->next = NULL;
			lstadd_back(&get_env()->l, tmp);
			i++;
		}
		free_arr(get_env()->a);
		create_env_array();
	}
}
