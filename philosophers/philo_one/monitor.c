/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:16:25 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/02/06 18:42:54 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	*monitor(void *philo_)
{
	t_philosopher *philo = (t_philosopher*)philo_;

	while(1){
		pthread_mutex_lock(&philo->is_eating);
		if ((get_time_abs_us() - philo->last_time_started_to_eat)
					>= g_params->time_to_die_us)
		{
			message_last(philo, MESSAGE_DIE);
			pthread_mutex_unlock(&philo->is_eating);
			pthread_mutex_unlock(&g_params->somebody_dead);
			return 0;
		}
		pthread_mutex_unlock(&philo->is_eating);
		usleep(1000);
	}
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
