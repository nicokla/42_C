/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:15:55 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/01/31 14:28:14 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static char *g_messages[] =
{
	" has taken a fork\n",
	" is eating\n",
	" is sleeping\n",
	" is thinking\n",
	" died\n"
};

void	message(t_philosopher *philo, int a)
{
	pthread_mutex_lock(&g_params->message);
	if (g_params->last_message){
		pthread_mutex_unlock(&g_params->message);
		return;
	}
	ft_putnbr_fd(get_time(), 1);
	write(1, "\t", 1);
	ft_putstr(philo->name);
	ft_putstr(g_messages[a]);
	pthread_mutex_unlock(&g_params->message);
}

void	message_last(t_philosopher *philo, int a)
{
    pthread_mutex_lock(&g_params->message);
	if (g_params->last_message){
		pthread_mutex_unlock(&g_params->message);
		return;
	}
	g_params->last_message = 1;
    uint64_t time = get_time();
    ft_putnbr_fd(time, 1);
    write(1,"\t",1);
    ft_putstr(philo->name);
    ft_putstr(g_messages[a]);
    pthread_mutex_unlock(&g_params->message);
}


void	message2_last(char *s)
{
	pthread_mutex_lock(&g_params->message);
	g_params->last_message = 1;
	ft_putstr(s);
	pthread_mutex_unlock(&g_params->message);
}
