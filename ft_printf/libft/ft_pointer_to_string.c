/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_to_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:32:06 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/14 18:53:00 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_get_number_of_digits_unsigned(unsigned long n,
										int base_length)
{
	int i;

	if (n == 0)
		return (1);
	i = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		n /= base_length;
		i++;
	}
	return (i);
}

char	*ft_pointer_to_string(void *p)
{
	int				num_digits;
	char			*answer;
	const char		*base = "0123456789abcdef";
	unsigned long	n;

	n = (unsigned long)p;
	num_digits = 2 + ft_get_number_of_digits_unsigned(n, 16);
	answer = malloc(num_digits + 1);
	if (answer == NULL)
		return (NULL);
	answer[num_digits] = '\0';
	answer[0] = '0';
	answer[1] = 'x';
	answer[--num_digits] = base[n % 16];
	n /= 16;
	while (n > 0)
	{
		answer[--num_digits] = base[n % 16];
		n /= 16;
	}
	return (answer);
}
