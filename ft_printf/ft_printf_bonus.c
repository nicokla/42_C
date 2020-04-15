/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:33:48 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/24 13:55:31 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	modify_if_needed(t_params *p)
{
	if (ft_strchr("xuidp", p->type) && (p->precision_seen == 1))
	{
		p->c = ' ';
		p->zero = 0;
	}
}

void	print_buffer(t_params *p, void *s, size_t size)
{
	write(1, (char*)s, size);
	p->length += size;
}

void	print_gen(t_params *p)
{
	if (p->type == 's')
		print_string(p);
	else if (p->type == 'c')
		print_char(p);
	else if (p->type == 'p')
		print_pointer(p);
	else if (p->type == 'd' || p->type == 'i')
		print_int(p);
	else if (p->type == 'u')
		print_uint(p);
	else if (p->type == 'x')
		print_hexa(p, 0);
	else if (p->type == 'X')
		print_hexa(p, 1);
	else if (p->type == '%')
		print_string_with_padding(p, "%%", 1);
	else if (p->type == 'o')
		print_octal(p);
}

void	parse_and_print(t_params *p)
{
	p->str++;
	reinit_parser(p);
	parse_flags(p);
	parse_min_width(p);
	parse_precision(p);
	parse_type(p);
	if (p->type != 0)
	{
		modify_if_needed(p);
		print_gen(p);
	}
}

int		ft_printf(const char *format, ...)
{
	t_params	params;
	t_params	*p;

	p = &params;
	ft_memset(p, 0, sizeof(t_params));
	p->str = (char *)format;
	va_start(p->va, format);
	while (*(p->str) != '\0')
	{
		if (*(p->str) != '%')
		{
			write(1, p->str, 1);
			p->str++;
			p->length++;
		}
		else
			parse_and_print(p);
	}
	va_end(p->va);
	return (p->length);
}
