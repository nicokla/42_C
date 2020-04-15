/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:41:03 by nicolas           #+#    #+#             */
/*   Updated: 2019/10/24 13:48:32 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_params *p)
{
	int				n;
	char			*s;

	n = va_arg(p->va, int);
	s = ft_itoa(n);
	prepare_string(p, &s, (long)n);
	print_string_with_padding(p, s, ft_strlen(s));
	free(s);
}

void	print_hexa(t_params *p, int is_maj)
{
	unsigned int	n;
	char			*s;

	n = va_arg(p->va, unsigned int);
	if (is_maj)
		s = ft_itoa_base((long)n, "0123456789ABCDEF");
	else
		s = ft_itoa_base((long)n, "0123456789abcdef");
	prepare_string(p, &s, (long)n);
	print_string_with_padding(p, s, ft_strlen(s));
	free(s);
}

void	print_octal(t_params *p)
{
	unsigned int	n;
	char			*s;

	n = va_arg(p->va, unsigned int);
	s = ft_itoa_base((long)n, "01234567");
	prepare_string(p, &s, (long)n);
	print_string_with_padding(p, s, ft_strlen(s));
	free(s);
}

void	print_uint(t_params *p)
{
	unsigned int	n;
	char			*s;

	n = va_arg(p->va, unsigned int);
	s = ft_itoa_long((long)n);
	prepare_string(p, &s, (long)n);
	print_string_with_padding(p, s, ft_strlen(s));
	free(s);
}

void	print_pointer(t_params *p)
{
	void			*pointer;
	char			*s;

	pointer = va_arg(p->va, void*);
	s = ft_pointer_to_string(pointer);
	prepare_string(p, &s, (long)pointer);
	print_string_with_padding(p, s, ft_strlen(s));
	free(s);
}
