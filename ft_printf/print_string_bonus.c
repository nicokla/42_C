/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:39:56 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/24 14:23:55 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_string(t_params *p)
{
	char	*s;
	size_t	len;
	int		need_free;

	s = va_arg(p->va, char *);
	need_free = 0;
	if (s == NULL)
	{
		s = malloc(7);
		ft_strlcpy(s, "(null)", 7);
		need_free = 1;
	}
	if (p->precision_seen)
		len = ft_min(ft_strlen(s), p->precision);
	else
		len = ft_strlen(s);
	print_string_with_padding(p, s, len);
	if (need_free)
		free(s);
}

void	print_char(t_params *p)
{
	char	s[2];

	s[0] = (char)va_arg(p->va, int);
	s[1] = '\0';
	print_string_with_padding(p, s, 1);
}

void	padding(t_params *p, int should_pad_after)
{
	if (p->padding)
	{
		if ((p->minus && should_pad_after)
			|| (!p->minus && !should_pad_after))
			while (p->padding--)
				print_buffer(p, &(p->c), 1);
	}
}

void	padding_simple(t_params *p, char c, size_t size)
{
	while (size--)
		print_buffer(p, &c, 1);
}

void	print_string_with_padding(t_params *p, char *s, size_t len)
{
	p->padding = ft_max(0, (p->min_width - len));
	padding(p, 0);
	print_buffer(p, s, len);
	padding(p, 1);
}
