/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:36:53 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/09 09:37:00 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*list;
	t_list	*temp;

	if (!lst || !f)
		return (0);
	res = NULL;
	list = lst;
	while (list)
	{
		if (!(temp = ft_lstnew(f(list->content))))
		{
			ft_lstclear(&res, del);
			return (0);
		}
		ft_lstadd_back(&res, temp);
		list = list->next;
	}
	return (res);
}
