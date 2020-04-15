/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:20:46 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/01/28 19:21:26 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int			ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int			ft_isspace(int a)
{
	int answer;

	answer = (a == ' ')
		|| (a == '\n')
		|| (a == '\t')
		|| (a == '\v')
		|| (a == '\f')
		|| (a == '\r');
	return (answer);
}

long		check_cas_extreme(const char *str, long res, long signe)
{
	unsigned char	max;
	long			sortie;

	max = 8;
	sortie = -1;
	if (signe < 0)
	{
		max = 9;
		sortie = 0;
	}
	if (res == 922337203685477580)
	{
		if (*str - '0' >= max)
			return (sortie);
		else
			return (1);
	}
	else if (res > 922337203685477580)
		return (sortie);
	else
		return (1);
}

uint64_t	calculer_nombre2(const char *str, uint64_t res, uint64_t signe)
{
	int				i;
	uint64_t		tmp;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			tmp = check_cas_extreme(str + i, res, signe);
			if (tmp <= 0)
				return (tmp);
			res *= 10;
			res += str[i] - '0';
		}
		else
			break ;
		i++;
	}
	return (res * signe);
}

uint64_t	ft_atoi(char *str)
{
	uint64_t	res;
	uint64_t	signe;
	int			i;
	int			plus_and_minus_seen;

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
