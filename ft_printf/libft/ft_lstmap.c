/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:44:01 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/11 19:21:27 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list *result;
	t_list *result_first;

	if (lst == NULL)
		return (NULL);
	result = f(lst);
	result_first = result;
	while (lst != 0)
	{
		lst = lst->next;
		result->next = f(lst);
		result = result->next;
	}
	result->next = NULL;
	return (result_first);
}
