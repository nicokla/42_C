/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 09:49:15 by cyhuet            #+#    #+#             */
/*   Updated: 2019/11/21 11:30:09 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <unistd.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s, char const *set);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strnstr(const char *big, const char *little,
	size_t len);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_calloc(size_t nmenb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *list);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *));

char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int n);
char				*ft_itoa_base(long n, int base, int upp);
int					ft_pow(int n, int power);
long				ft_pow_long(long n, long power);
void				ft_strrev(char *str);
int					ft_get_index(char *str, char c);
int					ft_strequ(char const *s1, char const *s2);
void				ft_putendl(char const *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t size);

#endif