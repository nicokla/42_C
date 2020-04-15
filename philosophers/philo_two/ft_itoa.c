/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:22:10 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/01/28 19:22:22 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_string_size(int n)
{
	int i;

	if (n == 0)
		return (1);
	i = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int		num_digits;
	char	*answer;
	long	n;

	n = nb;
	num_digits = get_string_size(n);
	answer = malloc(num_digits + 1);
	if (answer == NULL)
		return (NULL);
	answer[num_digits] = '\0';
	if (n < 0)
	{
		n = -n;
		answer[0] = '-';
	}
	answer[--num_digits] = n % 10 + '0';
	n /= 10;
	while (n > 0)
	{
		answer[--num_digits] = n % 10 + '0';
		n /= 10;
	}
	return (answer);
}
