/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:43:01 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/17 16:29:33 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *begin_list;

	if (lst != NULL)
		begin_list = *lst;
	else
		return ;
	while (begin_list != NULL)
	{
		tmp = begin_list->next;
		if (begin_list->content != NULL)
			(*del)(begin_list->content);
		free(begin_list);
		begin_list = tmp;
	}
	if (lst != NULL)
		*lst = NULL;
}
