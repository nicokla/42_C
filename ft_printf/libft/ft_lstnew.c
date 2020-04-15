/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:37 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/18 15:53:45 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void *content)
{
	t_list	*my_element;

	my_element = malloc(sizeof(t_list));
	if (my_element == NULL)
		return (NULL);
	my_element->content = content;
	my_element->next = NULL;
	return (my_element);
}
