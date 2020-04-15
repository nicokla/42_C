/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number_of_digits.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:32:06 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/13 23:54:45 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_number_of_digits(long n, int base_length)
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
