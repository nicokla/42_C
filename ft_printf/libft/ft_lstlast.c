/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:33 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/11 18:33:42 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *begin_list)
{
	t_list *old_elt;

	old_elt = 0;
	while (begin_list != 0)
	{
		old_elt = begin_list;
		begin_list = begin_list->next;
	}
	return (old_elt);
}
