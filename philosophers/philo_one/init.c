/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:58:15 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/02/06 18:43:33 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init2(void)
{
	int			i;
	uint64_t	tmp;

	pthread_mutex_init(&g_params->message, NULL);
	pthread_mutex_init(&g_params->somebody_dead, NULL);
	pthread_mutex_lock(&g_params->somebody_dead);
	g_params->philosophers = malloc(sizeof(t_philosopher) * g_params->n);
	i = 0;
	while (i < g_params->n)
	{
		pthread_mutex_init(&g_params->forks[i], NULL);
		g_params->philosophers[i].left_fork = &g_params->forks[i];
		g_params->philosophers[i].right_fork =
			&g_params->forks[(i + 1) % g_params->n];
		g_params->philosophers[i].name = ft_itoa(i + 1);
		g_params->philosophers[i].times_has_eaten = 0;
		pthread_mutex_init(&g_params->philosophers[i].enough_times, NULL);
		pthread_mutex_lock(&g_params->philosophers[i++].enough_times);
		pthread_mutex_init(&g_params->philosophers[i].is_eating, NULL);
	}
	tmp = get_time_abs_us();
	i = 0;
	while (i < g_params->n)
		g_params->philosophers[i++].last_time_started_to_eat = tmp;
	g_start = tmp / 1000;
}

void	init(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		error("Usage: ./philosophers number_of_philosophers \
time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]");
	g_params->last_message = 0;
	g_params->n = ft_atoi(argv[1]);
	g_params->time_to_die = ft_atoi(argv[2]);
	g_params->time_to_eat = ft_atoi(argv[3]);
	g_params->time_to_sleep = ft_atoi(argv[4]);
	g_params->time_to_die_us = 1000 * g_params->time_to_die;
	g_params->time_to_eat_us = 1000 * g_params->time_to_eat;
	g_params->time_to_sleep_us = 1000 * g_params->time_to_sleep;
	g_params->time_to_die_us_2 =
		g_params->time_to_die_us - g_params->time_to_eat_us;
	if (argc == 6)
		g_params->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		g_params->number_of_times_each_philosopher_must_eat = UINT64_MAX;
	g_params->forks = malloc(sizeof(pthread_mutex_t) * g_params->n);
	init2();
}
