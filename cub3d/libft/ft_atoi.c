/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:15:55 by nklarsfe          #+#    #+#             */
/*   Updated: 2019/10/14 22:30:33 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	calculer_nombre2(const char *str, long res, long signe)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			res *= 10;
			res += str[i] - '0';
			if ((res * signe) > 2147483647)
				return (-1);
			if ((res * signe) < -2147483648)
				return (0);
		}
		else
			break ;
		i++;
	}
	return (res * signe);
}

int		ft_atoi(const char *str)
{
	long	res;
	long	signe;
	int		i;
	int		plus_and_minus_seen;

	res = 0;
	signe = 1;
	i = 0;
	plus_and_minus_seen = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= (-1);
		i++;
		plus_and_minus_seen++;
		if (plus_and_minus_seen > 1)
			return (0);
	}
	res = calculer_nombre2(str + i, res, signe);
	return ((int)res);
}
