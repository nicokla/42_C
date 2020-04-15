/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:44:01 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/24 16:19:31 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*))
{
	t_list	*res;
	t_elt	*elt;

	if (lst == NULL)
		return (NULL);
	res = ft_lstnew();
	elt = lst->first;
	while (elt != 0)
	{
		ft_lstadd_back(res, f(elt->content));
		elt = elt->next;
	}
	return (res);
}
