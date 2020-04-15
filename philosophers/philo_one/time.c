/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:57:54 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/02/06 12:30:31 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void wait_us(uint64_t start, uint64_t duration){
	uint64_t target = start + duration;
	while(get_time_abs_us() < target){
		usleep(1000);
	}
}

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
