/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:38:52 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/23 20:05:31 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(t_params *p)
{
	while (*(p->str) == '0' || *(p->str) == '-'
		|| *(p->str) == ' ' || *(p->str) == '+')
	{
		if (*(p->str) == '0')
			p->zero = 1;
		if (*(p->str) == '-')
			p->minus = 1;
		if (*(p->str) == '+')
			p->plus = 1;
		if (*(p->str) == ' ')
			p->space = 1;
		p->str++;
	}
	if (p->minus)
		p->zero = 0;
	if (p->plus)
		p->space = 0;
	if (p->zero)
		p->c = '0';
	else
		p->c = ' ';
}

void	parse_min_width(t_params *p)
{
	if (*(p->str) == '*')
	{
		p->str++;
		p->min_width = va_arg(p->va, int);
		if (p->min_width < 0)
		{
			p->min_width = -p->min_width;
			p->minus = 1;
			p->zero = 0;
		}
		return ;
	}
	while (*(p->str) >= '0' && *(p->str) <= '9')
	{
		p->min_width *= 10;
		p->min_width += *(p->str) - '0';
		p->str++;
	}
}

void	parse_precision(t_params *p)
{
	if (*(p->str) == '.')
	{
		p->precision_seen = 1;
		p->str++;
		if (*(p->str) == '*')
		{
			p->str++;
			p->precision = va_arg(p->va, int);
			if (p->precision < 0)
			{
				p->precision_seen = 0;
				p->precision = 0;
			}
			return ;
		}
		while (*(p->str) >= '0' && *(p->str) <= '9')
		{
			p->precision *= 10;
			p->precision += *(p->str) - '0';
			p->str++;
		}
	}
}

void	parse_type(t_params *p)
{
	if (*(p->str) == '\0')
		return ;
	if (ft_strchr("cspdiuxXo%%", *(p->str)))
	{
		p->type = *(p->str);
		p->str++;
	}
}

void	reinit_parser(t_params *p)
{
	p->zero = 0;
	p->minus = 0;
	p->plus = 0;
	p->space = 0;
	p->min_width = 0;
	p->precision = 0;
	p->precision_seen = 0;
	p->type = 0;
	p->padding = 0;
}
