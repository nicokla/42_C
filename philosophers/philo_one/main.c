/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:18:24 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/02/06 18:46:21 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

uint64_t g_start;
t_params *g_params;

void	philo_eat(t_philosopher *philo)
{
	// take forks
	pthread_mutex_lock(philo->left_fork);
	message(philo, MESSAGE_FORK);
	pthread_mutex_lock(philo->right_fork);
	message(philo, MESSAGE_FORK);
	// eat
	pthread_mutex_lock(&philo->is_eating);
	philo->last_time_started_to_eat = get_time_abs_us();
	message(philo, MESSAGE_EAT);
	wait_us(philo->last_time_started_to_eat, g_params->time_to_eat_us);
	pthread_mutex_unlock(&philo->is_eating);
	// put back the forks
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	// check if has eaten enough times
	philo->times_has_eaten++;
	if (philo->times_has_eaten ==
		g_params->number_of_times_each_philosopher_must_eat)
		pthread_mutex_unlock(&philo->enough_times);
}


void	philo_sleep(t_philosopher *philo)
{
	message(philo, MESSAGE_SLEEP);
	usleep(g_params->time_to_sleep_us);
}

void	philo_think(t_philosopher *philo)
{
	message(philo, MESSAGE_THINK);
}

void	*philosopher_life(void *philo_)
{
	t_philosopher *philo;
	pthread_t	tid;

	philo = (t_philosopher*)philo_;
	if (pthread_create(&tid, NULL, &monitor, philo) != 0)
		return (void*)1;
	pthread_detach(tid);
	while (1)
	{
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	t_params	params_;
	pthread_t	tid;
	int			i;

	g_params = &params_;
	init(argc, argv);
	if (pthread_create(&tid, NULL,
		&wait_for_everybody_to_have_eaten_enough_times, NULL) != 0)
		return (1);
	pthread_detach(tid);
	i = 0;
	while (i < g_params->n)
	{
		if (pthread_create(&tid, NULL, &philosopher_life,
				&g_params->philosophers[i]) != 0)
			return (1);
		pthread_detach(tid);
		usleep(20);
		i++;
	}
	pthread_mutex_lock(&g_params->somebody_dead);
	pthread_mutex_unlock(&g_params->somebody_dead);
	clean();
	return (0);
}
