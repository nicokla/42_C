/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:57:54 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/01/28 20:11:23 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

uint64_t	get_time_abs(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

uint64_t	get_time(void)
{
	return (get_time_abs() - g_start);
}

uint64_t	get_time_abs_us(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (uint64_t)(tv.tv_sec * 1000000 + tv.tv_usec);
}
