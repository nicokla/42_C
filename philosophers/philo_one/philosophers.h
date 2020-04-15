#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MESSAGE_FORK 0
# define MESSAGE_EAT 1
# define MESSAGE_SLEEP 2
# define MESSAGE_THINK 3
# define MESSAGE_DIE 4

typedef struct	s_philosopher
{
	uint64_t			last_time_started_to_eat;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	char				*name;
	uint64_t			times_has_eaten;
	pthread_mutex_t		enough_times;
	pthread_mutex_t is_eating;
}				t_philosopher;

typedef struct	s_params
{
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
	int				n;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		time_to_die_us;
	uint64_t		time_to_eat_us;
	uint64_t		time_to_sleep_us;
	uint64_t		time_to_die_us_2;
	uint64_t		number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	somebody_dead;
	pthread_mutex_t	message;
	int last_message;
}				t_params;

extern uint64_t g_start;
extern t_params *g_params;

uint64_t	ft_atoi(char *str);
int			ft_strlen(char *s);
void		error(char *s);
char		*ft_itoa(int nb);
void		ft_putnbr_fd(uint64_t n, int fd);
void		ft_putstr(char *s);
void		message(t_philosopher *philo, int a);
uint64_t	get_time_abs(void);
uint64_t	get_time(void);
void		message2_last(char *s);
void		clean();
void		init(int argc, char **argv);
uint64_t	get_time_abs_us(void);
uint64_t	get_time_abs(void);
uint64_t	get_time(void);
void		*monitor(void *rien);
void		*wait_for_everybody_to_have_eaten_enough_times(void *rien);
void		message_last(t_philosopher *philo, int a);
void wait_us(uint64_t start, uint64_t duration);

#endif