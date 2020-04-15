/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:32:06 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/14 18:51:52 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		base_est_ok(const char *base, int n)
{
	int i;
	int j;

	i = 0;
	if (n <= 1)
		return (0);
	while (i < n)
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i <= n - 2)
	{
		j = i + 1;
		while (j <= n - 1)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	negative_case(char *answer, long *pn)
{
	if (*pn < 0)
	{
		*pn = -(*pn);
		answer[0] = '-';
	}
}

char	*ft_itoa_base(long n, const char *base)
{
	int		num_digits;
	char	*answer;
	int		base_length;

	base_length = ft_strlen(base);
	if (!base_est_ok(base, base_length))
		return (NULL);
	num_digits = ft_get_number_of_digits(n, base_length);
	answer = malloc(num_digits + 1);
	if (answer == NULL)
		return (NULL);
	answer[num_digits] = '\0';
	negative_case(answer, &n);
	answer[--num_digits] = base[n % base_length];
	n /= base_length;
	while (n > 0)
	{
		answer[--num_digits] = base[n % base_length];
		n /= base_length;
	}
	return (answer);
}
