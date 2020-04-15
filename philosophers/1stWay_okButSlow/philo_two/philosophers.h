#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>

// #define THINK 0
// #define EAT 1
// #define SLEEP 2

#define SEM_NAME_MESSAGES "messages"
#define SEM_NAME_SOMEBODY_DEAD "somebodyDead"
#define SEM_NAME_FORKS "fourchettes"
#define SEM_NAME_HAS_EATEN_ENOUGH "hasEatenEnough"


#define MESSAGE_FORK 0
#define MESSAGE_EAT 1
#define MESSAGE_SLEEP 2
#define MESSAGE_THINK 3
#define MESSAGE_DIE 4


typedef struct s_philosopher{
	// int state;
	uint64_t last_time_started_to_eat;
	char *name;
	uint64_t times_has_eaten;
	sem_t *has_eaten_enough_times;
} t_philosopher;

typedef struct s_params{
	sem_t *forks;
	t_philosopher *philosophers;
	int n;
	uint64_t time_to_die;
	uint64_t time_to_eat;
	uint64_t time_to_sleep;
	// uint64_t time_to_think;
	uint64_t time_to_die_us;
	uint64_t time_to_eat_us;
	uint64_t time_to_sleep_us;
	uint64_t time_to_die_us_2;
	// uint64_t time_to_think_us;
	uint64_t number_of_times_each_philosopher_must_eat;
	sem_t *somebody_dead;
	sem_t *message;
	int last_message;
} t_params;


extern uint64_t start;
extern t_params *params;
extern char *messages[];

uint64_t	ft_atoi(char *str);
int		ft_strlen(char *s);
void	error(char *s);
char	*ft_itoa(int nb);
void ft_putnbr_fd(uint64_t n, int fd);
void ft_putstr(char *s);
void message(t_philosopher *philo, int a);
uint64_t get_time_abs(void);
uint64_t get_time(void);
void message2_last(char *s);
sem_t *ft_sem_open(char const *name, int value);
char *getName(char *buf, char *s, int n);
void message_last(t_philosopher *philo, int a);

#endif