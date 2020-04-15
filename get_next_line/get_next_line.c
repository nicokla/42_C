/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:16:49 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/30 13:12:12 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	str_append_buf(t_string *ps, char *buf)
{
	if (ps->size_all)
	{
		ps->last->next = malloc(sizeof(t_elem));
		ps->last->next->next = NULL;
		ps->last = ps->last->next;
	}
	ft_memcpy(ps->last->content, buf, BUFFER_SIZE + 1);
	ps->size_all += ft_strlen2(buf, '\0', '\0');
	ps->size += ft_strlen2(buf, '\0', '\n');
}

void	str_clear(t_string *ps)
{
	t_elem	*e;
	t_elem	*tmp;

	e = ps->first;
	while (e != ps->last)
	{
		tmp = e->next;
		free(e);
		e = tmp;
	}
	ps->first = ps->last;
	ps->size = 0;
	ps->size_all = 0;
}

void	str_dup(t_string s, char **line)
{
	t_elem	*tmp;
	size_t	i;
	size_t	len;

	*line = malloc(s.size + 1);
	if (*line == NULL)
		return ;
	tmp = s.first;
	i = 0;
	while (1)
	{
		len = ft_strlen2(tmp->content, '\0', '\n');
		ft_memcpy((*line) + i, tmp->content, len);
		i += len;
		if (tmp == s.last)
			break ;
		else
			tmp = tmp->next;
	}
	(*line)[i] = '\0';
}

int		prepare_next_function_call(t_string *l,
									char **line,
									int fd)
{
	size_t		i;
	size_t		j;

	str_dup(l[fd], line);
	str_clear(&(l[fd]));
	i = ft_strlen2(l[fd].last->content, '\0', '\n');
	if (l[fd].last->content[i] == '\0')
		return (free_and_leave(l, fd));
	i++;
	j = 0;
	while (1)
	{
		l[fd].first->content[j] = l[fd].first->content[i + j];
		if (l[fd].first->content[j++] == '\0')
			break ;
	}
	l[fd].size = ft_strlen2(l[fd].first->content, '\0', '\n');
	l[fd].size_all = ft_strlen2(l[fd].first->content, '\0', '\0');
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_string	lines[255];
	char			buf[BUFFER_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	if (lines[fd].first == NULL)
		lines[fd] = str_new();
	if (!ft_strchr(lines[fd].last->content, '\n'))
	{
		while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[ret] = '\0';
			str_append_buf(&(lines[fd]), buf);
			if (ft_strchr(buf, '\n'))
				break ;
		}
		if (ret < 0)
			return (-1);
	}
	return (prepare_next_function_call(lines, line, fd));
}
