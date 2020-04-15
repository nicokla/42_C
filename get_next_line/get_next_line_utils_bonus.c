/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:16:49 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/30 13:34:46 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			free_and_leave(t_string *l, int fd)
{
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
	int			i;

	a.first = malloc(sizeof(t_elem));
	a.first->next = NULL;
	i = -1;
	while (++i < BUFFER_SIZE + 1)
		a.first->content[i] = '\0';
	a.size = 0;
	a.size_all = 0;
	a.last = a.first;
	return (a);
}

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*pdest;
	char	*psrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	pdest = (char*)dest;
	psrc = (char*)src;
	i = 0;
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}

char		*ft_strchr(const char *s, int c_int)
{
	char c;

	c = (char)c_int;
	while (*s != c && *s != '\0')
		s++;
	if (*s == '\0' && c != '\0')
		return (NULL);
	return ((char *)s);
}
