/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:31 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/24 16:08:39 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list *list, void *data)
{
	t_elt *elmt;

	if (list == 0)
		return ;
	elmt = ft_eltnew(data);
	if (list->last != 0)
		list->last->next = elmt;
	list->last = elmt;
	if (list->first == NULL)
		list->first = elmt;
	list->size++;
}
