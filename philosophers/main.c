
#include "philo.h"

// void pick_forks(t_philo *p)
// {
//     if (pthread_mutex_lock(&p->mutex->forks[p->id]) == 0)
//         printf("%d picked right fork\n", p->id);
		
//     if(pthread_mutex_lock(&p->mutex->forks[(p->id + 1 % 5)]) == 0)
//         printf("%d picked left fork\n", p->id);

// }

// void put_forks(t_philo p)
// {
//     if (pthread_mutex_unlock(&p.mutex->forks[p.id]) == 0)
//         printf("%d puted right fork\n", p.id);
		
//     if(pthread_mutex_unlock(&p.mutex->forks[(p.id + 1 % 5)]) == 0)
//         printf("%d puted left fork\n", p.id);
	
// }

// long get_time(t_philo *philo)
// {
// 	struct timeval current_time;

// 	gettimeofday(&current_time, NULL);
// 	return (current_time.tv_usec - philo->starting_time);
// }
long    get_time(void)
{
    struct timeval    t;
    long            time;

    gettimeofday(&t, NULL);
    time = t.tv_sec * 1000 + t.tv_usec / 1000;
    return (time);
}
void print_behavior(t_philo *p, char *str)
{
	pthread_mutex_lock(p->mutex);
	printf("%09ld ms |%d| %s\n", get_time() - p->starting_time, p->id, str);
	pthread_mutex_unlock(p->mutex);
}
void *tflsf(void* arg)
{
	t_philo* p = (t_philo*)arg;
	// printf("seconds : %ld\nmicro seconds : %ld",current_time.tv_sec, current_time.tv_usec);
	if (p->id % 2 == 0)
	   usleep(100);
	while (1)
	{
		// gettimeofday(&current_time, NULL);

		print_behavior(p, "is thinking");
		pthread_mutex_lock(p->left_fork);
		print_behavior(p, "has taken a fork");
		pthread_mutex_lock(p->right_fork);
		print_behavior(p, "has taken a fork");
		print_behavior(p, "is eating");
		usleep(p->time_to_eat * 1000);
		pthread_mutex_unlock(p->right_fork);
		pthread_mutex_unlock(p->left_fork);
		print_behavior(p, "is sleeping");
		usleep(p->time_to_sleep * 1000);
		// pick_forks(p);
		// printf("philo %d is eating", p->id);
		// put_forks(*p);
	}
	return NULL;
}

int main(int ac, char **av)
{
	
	pthread_t *p;
	t_philo *philo;
	pthread_mutex_t *forks;
	pthread_mutex_t m;
	int     i;
	
	p =  malloc(sizeof(pthread_t *) * 6);
	philo =  malloc(sizeof(t_philo *) * 6);
	forks = malloc(sizeof(pthread_mutex_t *) * 6);
	i = 0;
	pthread_mutex_init(&m, NULL);
	while (i < 6)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	long start_time = get_time();
	while (i < 6)
	{
		philo[i].time_to_die = ft_atoi(av[1]);
		philo[i].time_to_eat = ft_atoi(av[2]);
		philo[i].time_to_sleep = ft_atoi(av[3]);
		philo[i].starting_time = start_time;
		philo[i].mutex = &m;
		philo[i].id = i;
		philo[i].right_fork = &forks[i];
		philo[i].left_fork = &forks[(i + 1) % 6];
		pthread_create(&p[i], NULL, tflsf, &philo[i]);
		// pthread_join(p[i], NULL);
		i++;
	}
	while(1);
	exit(0);
}