/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:35 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/24 15:53:58 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list *list, void *data)
{
	t_elt *elmt;

	if (list == 0)
		return ;
	elmt = ft_eltnew(data);
	elmt->next = list->first;
	list->first = elmt;
	if (list->last == NULL)
		list->last = elmt;
	list->size++;
}
