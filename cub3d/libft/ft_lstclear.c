/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:43:01 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/04 16:29:18 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_eltclear(t_elt *el)
{
	if (el != NULL)
	{
		if (el->content != NULL)
			free(el->content);
		free(el);
	}
}

void	ft_lstclear(t_list *lst)
{
	t_elt *tmp;
	t_elt *tmp2;

	if (lst == NULL)
		return ;
	tmp = lst->first;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		ft_eltclear(tmp);
		tmp = tmp2;
	}
	lst->size = 0;
	lst->first = NULL;
	lst->last = NULL;
}

char	**ft_lst_to_staticlst(t_list *lst, int *pheight)
{
	t_elt	*tmp;
	t_elt	*tmp2;
	char	**lst2;
	int		i;

	if (lst == NULL)
		return (NULL);
	*pheight = lst->size;
	if (!(lst2 = malloc(sizeof(char*) * lst->size)))
		return (NULL);
	tmp = lst->first;
	i = -1;
	while ((++i >= 0) && tmp != NULL)
	{
		tmp2 = tmp->next;
		if (tmp != NULL)
		{
			lst2[i] = tmp->content;
			free(tmp);
			lst->first = tmp2;
			lst->size--;
		}
		tmp = tmp2;
	}
	return (lst2);
}
