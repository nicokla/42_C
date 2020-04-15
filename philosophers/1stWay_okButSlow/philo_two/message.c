/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:23:20 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/01/31 14:39:22 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	message(t_philosopher *philo, int a)
{
	sem_wait(params->message);
	if (params->last_message){
		sem_post(params->message);
		return;
	}
	ft_putnbr_fd(get_time(), 1);
	write(1, "\t", 1);
	ft_putstr(philo->name);
	ft_putstr(messages[a]);
	sem_post(params->message);
}

void	message_last(t_philosopher *philo, int a)
{
	sem_wait(params->message);
	if (params->last_message){
		sem_post(params->message);
		return;
	}
	params->last_message = 1;
	ft_putnbr_fd(get_time(), 1);
	write(1, "\t", 1);
	ft_putstr(philo->name);
	ft_putstr(messages[a]);
	sem_post(params->message);
}


void	message2_last(char *s)
{
	sem_wait(params->message);
	params->last_message = 1;
	ft_putstr(s);
	sem_post(params->message);
}

