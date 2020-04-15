/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:32:06 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/14 18:51:02 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_long(long n)
{
	int		num_digits;
	char	*answer;

	num_digits = ft_get_number_of_digits(n, 10);
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
