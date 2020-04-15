/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:16:49 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/26 14:02:35 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct	s_elem
{
	char			content[BUFFER_SIZE + 1];
	struct s_elem	*next;
}				t_elem;

typedef struct	s_string
{
	struct s_elem	*first;
	struct s_elem	*last;
	size_t			size;
	size_t			size_all;
}				t_string;

int				free_and_leave(t_string *l, int fd);
size_t			ft_strlen2(const char *s, char c1, char c2);
t_string		str_new();
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strchr(const char *s, int c_int);
int				sub_function(t_string *l, char **line, int fd);
void			str_dup(t_string s, char **line);
void			str_clear(t_string *ps);
void			str_append_buf(t_string *ps, char *buf);
int				prepare_next_function_call(t_string *lines,
									char **line,
									int fd);
int				get_next_line(const int fd, char **line);

#endif
