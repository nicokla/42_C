/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:58:09 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/01/31 14:18:33 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	clean(void)
{
	int i;

	i = 0;
	while (i < g_params->n)
	{
		pthread_mutex_destroy(&g_params->forks[i]);
		pthread_mutex_destroy(&g_params->philosophers[i].enough_times);
		// pthread_mutex_destroy(&g_params->philosophers[i].is_eating);
		free(g_params->philosophers[i].name);
		i++;
	}
	pthread_mutex_destroy(&g_params->message);
	pthread_mutex_destroy(&g_params->somebody_dead);
	free(g_params->forks);
	free(g_params->philosophers);
}
