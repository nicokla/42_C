/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nklarsfe <nklarsfe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:22:32 by nklarsfe          #+#    #+#             */
/*   Updated: 2020/01/31 14:44:03 by nklarsfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

uint64_t start;
t_params *params;
char *messages[] = 
{" has taken a fork\n", " is eating\n", " is sleeping\n",
" is thinking\n", " died\n"};

uint64_t get_time_abs(void){
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

uint64_t get_time(void){
	return (get_time_abs() - start);
}

uint64_t get_time_abs_us(void){
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (uint64_t)(tv.tv_sec * 1000000 + tv.tv_usec);
}

void init(int argc, char **argv){
	int i = 0;
	uint64_t tmp;
	char buf[100];
	if (argc < 5 || argc > 6)
		error("Usage: ./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]");
	params->last_message = 0;
	params->n = ft_atoi(argv[1]);
	params->time_to_die = ft_atoi(argv[2]);
	params->time_to_eat = ft_atoi(argv[3]);
	params->time_to_sleep = ft_atoi(argv[4]);
	// params->time_to_think = params->time_to_die - params->time_to_eat - params->time_to_sleep;
	params->time_to_die_us = 1000 * params->time_to_die;
	params->time_to_eat_us = 1000 * params->time_to_eat;
	params->time_to_sleep_us = 1000 * params->time_to_sleep;
	params->time_to_die_us_2 =
		params->time_to_die_us - params->time_to_eat_us;
	// params->time_to_think_us = 1000 * params->time_to_think;
	if (argc == 6)
		params->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		params->number_of_times_each_philosopher_must_eat = UINT64_MAX;
	params->message = ft_sem_open(SEM_NAME_MESSAGES, 1);
	params->somebody_dead = ft_sem_open(SEM_NAME_SOMEBODY_DEAD, 0);
	params->forks = ft_sem_open(SEM_NAME_FORKS, params->n);
	params->philosophers = malloc(sizeof(t_philosopher) * params->n);
	for(i = 0; i < params->n; i++){
		// params->philosophers[i].state = THINK;
		params->philosophers[i].name = ft_itoa(i + 1);
		params->philosophers[i].times_has_eaten = 0;
		params->philosophers[i].has_eaten_enough_times =
			ft_sem_open(getName(buf, SEM_NAME_HAS_EATEN_ENOUGH, i), 0);
	}
	tmp = get_time_abs_us();
	for(i = 0; i < params->n; i++){
		params->philosophers[i].last_time_started_to_eat = tmp;
	}
	start = tmp / 1000;
}

void clean(){
	int i;
	char buf[100];

	for(i = 0; i < params->n; i++){ 
		sem_unlink(getName(buf, SEM_NAME_HAS_EATEN_ENOUGH, i));
		free(params->philosophers[i].name);
	}
	sem_unlink(SEM_NAME_FORKS);
	sem_unlink(SEM_NAME_MESSAGES);
	sem_unlink(SEM_NAME_SOMEBODY_DEAD);
	free(params->philosophers);
}


void *philosopherWaitingToDie(void *philo_){
	t_philosopher *philo = (t_philosopher*) philo_;
	uint64_t timestart = philo->last_time_started_to_eat;
	usleep(params->time_to_die_us_2);
	if (philo->last_time_started_to_eat == timestart) {
		message_last(philo, MESSAGE_DIE);
		sem_post(params->somebody_dead);
	}
	return NULL;
}

void philo_eat(t_philosopher *philo){
	sem_wait(params->forks);
	message(philo, MESSAGE_FORK);
	sem_wait(params->forks);
	// start eating
	message(philo, MESSAGE_FORK);
	message(philo, MESSAGE_EAT);
	philo->last_time_started_to_eat = get_time_abs_us();
	usleep(params->time_to_eat_us);
	// finish eating
	sem_post(params->forks);
	sem_post(params->forks);
	philo->times_has_eaten++;
	if(philo->times_has_eaten == params->number_of_times_each_philosopher_must_eat)
		sem_post(philo->has_eaten_enough_times);
}


void philo_sleep(t_philosopher *philo){
	pthread_t	tid;
	message(philo, MESSAGE_SLEEP);
	if (pthread_create(&tid, NULL, &philosopherWaitingToDie, philo) != 0)
		return ;
	pthread_detach(tid);
	usleep(params->time_to_sleep_us);
}

void philo_think(t_philosopher *philo){
	message(philo, MESSAGE_THINK);
}

void *waitForEverybodyToHaveEatenEnoughTimes(void *rien){
	(void)rien;
	int i;
	for(i = 0; i < params->n; i++){
		sem_wait(params->philosophers[i].has_eaten_enough_times);
	}
	for(i = 0; i < params->n; i++){
		sem_post(params->philosophers[i].has_eaten_enough_times);
	}
	message2_last("Everybody has eaten enough times.\n");
	sem_post(params->somebody_dead);
	return NULL;
}

void *philosopherLife(void *philo_){
	t_philosopher *philo;

	philo = (t_philosopher*) philo_;
	while(1){
		philo_think(philo);
		philo_eat(philo);
		philo_sleep(philo);
	}
	return NULL;
}

// ./philosophers 7 20000 1000 1000
int main(int argc, char **argv){
	t_params params_;
	pthread_t	tid;
	int i;

	params = &params_;
	init(argc, argv);
	if (pthread_create(&tid, NULL, &waitForEverybodyToHaveEatenEnoughTimes, NULL) != 0)
		return 1;
	pthread_detach(tid);
	for(i = 0; i < params->n; i++){ 
		if (pthread_create(&tid, NULL, &philosopherLife, &params->philosophers[i]) != 0)
			return 1;
		pthread_detach(tid);
		usleep(10);
	}
	sem_wait(params->somebody_dead);
	sem_post(params->somebody_dead);
	clean();
	return 0;
}
