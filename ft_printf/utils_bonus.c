/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:04:10 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/24 14:24:07 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	add_zeros_if_needed(t_params *p, char **ps)
{
	char			*zeros;
	size_t			zeros_count;

	if (p->precision > (int)ft_strlen(*ps))
	{
		zeros_count = p->precision - ft_strlen(*ps);
		zeros = ft_strnew(zeros_count);
		ft_memset(zeros, '0', zeros_count);
		ft_str_append_prefix(zeros, ps);
		free(zeros);
	}
}

void	put_zeros_if_prefix(t_params *p, char **ps, int pos)
{
	char			*zeros;
	size_t			zeros_count;

	if ((p->precision > (int)ft_strlen(*ps) - pos)
		|| ((p->min_width > (int)ft_strlen(*ps)) && p->zero))
	{
		zeros_count = p->precision - ft_strlen(*ps) + pos;
		if (p->zero)
			zeros_count = ft_max(zeros_count,
				p->min_width - ft_strlen(*ps));
		zeros = ft_strnew(zeros_count);
		ft_memset(zeros, '0', zeros_count);
		*ps = ft_str_insert(*ps, zeros, pos);
		free(zeros);
	}
}

void	prepare_string_sub(t_params *p, char **ps, long n)
{
	char c[2];

	c[0] = '+';
	c[1] = '\0';
	if (n == 0 && p->precision_seen && (p->precision == 0))
	{
		free(*ps);
		*ps = ft_strdup("");
	}
	if (n >= 0)
	{
		if (p->space)
			c[0] = ' ';
		if (p->space || p->plus)
		{
			ft_str_append_prefix(c, ps);
			put_zeros_if_prefix(p, ps, 1);
		}
		else
			add_zeros_if_needed(p, ps);
	}
}

void	prepare_string(t_params *p, char **ps, long n)
{
	if (p->type == 'p')
	{
		if (n == 0 && p->precision_seen && (p->precision == 0))
		{
			free(*ps);
			*ps = ft_strdup("0x");
		}
		put_zeros_if_prefix(p, ps, 2);
	}
	else if (n < 0)
		put_zeros_if_prefix(p, ps, 1);
	else
		prepare_string_sub(p, ps, n);
}
