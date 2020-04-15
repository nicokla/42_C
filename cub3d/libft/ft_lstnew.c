/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:37 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/04 14:57:06 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_elt		*ft_eltnew(void const *content)
{
	t_elt	*my_element;

	my_element = malloc(sizeof(t_elt));
	if (my_element == NULL)
		return (NULL);
	my_element->content = (void*)content;
	my_element->next = NULL;
	return (my_element);
}

t_list		*ft_lstnew(void)
{
	t_list	*my_list;

	my_list = malloc(sizeof(t_list));
	if (my_list == NULL)
		return (NULL);
	my_list->size = 0;
	my_list->first = NULL;
	my_list->last = NULL;
	return (my_list);
}
