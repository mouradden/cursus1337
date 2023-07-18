#ifndef PHILO_H
#define PHILO_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// typedef struct s_mutex
// {
//     pthread_mutex_t *forks;
// }   t_mutex;

typedef struct s_shared
{
        pthread_mutex_t *forks;
}       t_shared;

typedef struct s_philo
{
    int id;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    long starting_time;
    long last_meal;
    int is_alive;
    pthread_mutex_t *mutex;
    // pthread_mutex_t   *right_fork;
    // pthread_mutex_t   *left_fork;
    int   right_fork;
    int   left_fork;
    t_shared    *shared;
    // pthread_mutex_t *forks;
}   t_philo;

int	ft_atoi(char *str);

#endif