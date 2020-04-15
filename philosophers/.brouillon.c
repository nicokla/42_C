
// ------------
// pthread
# include <pthread.h>

pthread_t	tid;
if (pthread_create(&tid, NULL, &function, argument) != 0)
		return ((void*)1);
	pthread_detach(tid);

// ------------
// mutex
pthread_mutex_t
pthread_mutex_lock(myPointer);
...
pthread_mutex_unlock(myPointer)
pthread_mutex_init(myPointer, NULL);
pthread_mutex_destroy(myPointer)

// ------------
// time
# include <sys/time.h>

usleep(1000);
uint64_t get_time(void){
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

// ----------
// semaphore

# include <semaphore.h>

sem_t *ft_sem_open(char const *name, int value){
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}
sem_unlink("mySemName");
ft_sem_open("mySemName", 3);
sem_wait(myPointer); (comme lock --> wait for it to be non empty)
sem_post(myPointer); (comme unlock --> add one, set it free)

// --------------
// fork

pid_t pid;
pid = fork();
if (pid < 0)
	return (1);
else if (pid == 0) {
	...
	exit(0);
}
wait(NULL);


kill(pid, SIGKILL);



// -----
// divers

if (f1(...) || f2(&state) || f3(&state))
	return (clear() && error("message"));
