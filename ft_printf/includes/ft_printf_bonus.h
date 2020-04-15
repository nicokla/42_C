/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:34:29 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/24 14:23:19 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE_BUF 64

typedef struct	s_params
{
	char	*str;
	va_list	va;
	size_t	length;
	char	zero;
	char	minus;
	char	plus;
	char	space;
	char	precision_seen;
	int		min_width;
	int		precision;
	char	type;
	int		padding;
	char	c;
}				t_params;

void			parse_flags(t_params *p);
void			parse_min_width(t_params *p);
void			parse_precision(t_params *p);
void			parse_type(t_params *p);
void			reinit_parser(t_params *p);

void			print_string(t_params *p);
void			print_char(t_params *p);
void			padding(t_params *p, int should_pad_after);
void			padding_simple(t_params *p, char c, size_t size);

void			print_string_with_padding(t_params *p, char *s, size_t len);
void			print_pointer(t_params *p);
void			print_int(t_params *p);
void			print_uint(t_params *p);
void			print_hexa(t_params *p, int is_maj);
void			print_octal(t_params *p);

void			print_buffer(t_params *p, void *s, size_t size);
void			print_gen(t_params *p);
void			parse_and_print(t_params *p);
int				ft_printf(const char *format, ...);
void			prepare_string(t_params *p, char **ps, long n);
void			modify_if_needed(t_params *p);
void			add_zeros_if_needed(t_params *p, char **ps);

#endif
