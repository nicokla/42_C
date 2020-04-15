/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:16:49 by nicolas           #+#    #+#             */
/*   Updated: 2019/11/04 16:29:34 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			free_and_leave(t_string *l, int fd)
{
	if (l[fd].first)
		free(l[fd].first);
	l[fd].first = NULL;
	l[fd].last = NULL;
	l[fd].size = 0;
	l[fd].size_all = 0;
	return (0);
}

size_t		ft_strlen2(const char *s, char c1, char c2)
{
	int i;

	i = 0;
	while (s[i] != c1 && s[i] != c2)
		i++;
	return (i);
}

t_string	str_new(void)
{
	t_string	a;

	a.size = 0;
	a.size_all = 0;
	a.first = malloc(sizeof(t_elem));
	a.last = a.first;
	if (a.first == NULL)
		return (a);
	a.first->next = NULL;
	a.first->content[0] = '\0';
	return (a);
}
