/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:16:25 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/02/06 12:05:05 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philosopher_waiting_to_die(void *philo_)
{
	t_philosopher *philo;
	uint64_t timestart;

	philo = (t_philosopher*)philo_;
	timestart = philo->last_time_started_to_eat;
	usleep(g_params->time_to_die_us_2);
	// pthread_mutex_lock(&philo->is_eating);
	if (philo->last_time_started_to_eat == timestart)
	{
		// (get_time_abs_us() - philo->last_time_started_to_eat) >= params->time_to_die_us){
		message_last(philo, MESSAGE_DIE);
		pthread_mutex_unlock(&g_params->somebody_dead);
	}
	// pthread_mutex_unlock(&philo->is_eating);
	return (NULL);
}

void	*wait_for_everybody_to_have_eaten_enough_times(void *rien)
{
	int		i;

	(void)rien;
	i = 0;
	while (i < g_params->n)
	{
		pthread_mutex_lock(&g_params->philosophers[i].enough_times);
		i++;
	}
	i = 0;
	while (i < g_params->n)
	{
		pthread_mutex_unlock(&g_params->philosophers[i].enough_times);
		i++;
	}
	message2_last("Everybody has eaten enough times.\n");
	pthread_mutex_unlock(&g_params->somebody_dead);
	return (NULL);
}
