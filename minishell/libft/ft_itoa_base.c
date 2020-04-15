/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:43:13 by cyhuet            #+#    #+#             */
/*   Updated: 2019/10/17 12:44:51 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	ft_size_num(long n, int base)
{
	int	size;

	size = 1;
	while ((long)ft_pow_long(base, size) <= n)
		size++;
	return (size);
}

char		*ft_itoa_base(long n, int base, int upp)
{
	int			size;
	char		*str;

	if (base == 10)
		return (ft_itoa(n));
	size = ft_size_num(n, base);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	str[size--] = '\0';
	while (size >= 0)
	{
		if (base > 10 && (n % base >= 10) && upp)
			str[size] = (n % base) - 10 + 'A';
		else if (base > 10 && (n % base >= 10))
			str[size] = (n % base) - 10 + 'a';
		else
			str[size] = (n % base) + '0';
		n /= base;
		size--;
	}
	return (str);
}
