/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 21:09:31 by mdenguir          #+#    #+#             */
/*   Updated: 2023/07/25 10:55:36 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_shared
{
	int					nb_philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		mutex;
	pthread_mutex_t		print;
	int					is_alive;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
}	t_shared;

typedef struct s_philo
{
	int				id;
	long			starting_time;
	long			last_meal;
	int				right_fork;
	int				left_fork;
	t_shared		*shared;
	int				nbr_meals;
	int				max_meals;
}	t_philo;

int		ft_atoi(char *str);
void	*routine(void *arg);
void	init(t_philo *philo, char **av);
void	init_philos(t_philo *philo, t_shared *shared, char **av, int n);
long	get_time(void);
void	ft_usleep(useconds_t time);
void	print_behavior(t_philo *p, char *str);
void	check_death(t_philo *philo, int ac);
void	check(int ac, char **av);
int		check_args(char **args);
int		check_values(char **av);
void	cleanup(t_philo *philo);

#endif