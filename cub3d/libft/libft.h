/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:21:29 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/11/02 13:18:29 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
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

typedef struct	s_elt
{
	char			*content;
	struct s_elt	*next;
}				t_elt;

typedef struct	s_list
{
	t_elt	*first;
	t_elt	*last;
	int		size;
}				t_list;

int				ft_isalnum(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *ptr, int value, size_t num);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *destination, const void *source, size_t num);
void			*ft_memchr(const void *ptr, int value, size_t num);
int				ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void			*ft_calloc(size_t num, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
unsigned int	ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *str, int character);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *str, int character);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_elt			*ft_eltnew(void const *content);
t_list			*ft_lstnew(void);
void			ft_eltclear(t_elt *el);
void			ft_lstclear(t_list *lst);
void			ft_lstadd_back(t_list *list, void *data);
void			ft_lstadd_front(t_list *list, void *data);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *));
char			**ft_lst_to_staticlst(t_list *lst, int *pheight);

int				ft_isspace(int a);
int				ft_atoi_base(char *str, char *base);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strjoin2(int size, char **strs, char *sep);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnew(size_t size);
char			**ft_split2(char *str, char *charset);
int				ft_abs(int a);

int				free_and_leave(t_string *l, int fd);
size_t			ft_strlen2(const char *s, char c1, char c2);
t_string		str_new();
int				sub_function(t_string *l, char **line, int fd);
void			str_dup(t_string s, char **line);
void			str_clear(t_string *ps);
void			str_append_buf(t_string *ps, char *buf);
int				prepare_next_function_call(t_string *lines,
									char **line,
									int fd);
int				get_next_line(const int fd, char **line);

#endif
