/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:31 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/18 16:01:55 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **begin_list, t_list *new)
{
	t_list *old_elt;
	t_list *current;

	if (begin_list == 0)
		return ;
	current = *begin_list;
	old_elt = current;
	while (current != 0)
	{
		old_elt = current;
		current = current->next;
	}
	if (old_elt != 0)
		old_elt->next = new;
	else
		(*begin_list) = new;
}
