/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:25:52 by mdenguir          #+#    #+#             */
/*   Updated: 2023/07/25 15:02:08 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_philo *philo, char **av)
{
	int				i;
	int				n;
	t_shared		*shared;

	i = 0;
	n = ft_atoi(av[1]);
	shared = malloc(sizeof(t_shared) * 1);
	shared->forks = malloc(sizeof(pthread_mutex_t) * n);
	while (i < n)
	{
		pthread_mutex_init(&shared->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&shared->mutex, NULL);
	pthread_mutex_init(&shared->print, NULL);
	init_philos(philo, shared, av, n);
}

void	init_philos(t_philo *philo, t_shared *shared, char **av, int n)
{
	int				i;
	long			start_time;

	i = 0;
	start_time = get_time();
	while (i < n)
	{
		shared->time_to_die = ft_atoi(av[2]);
		shared->time_to_eat = ft_atoi(av[3]);
		shared->time_to_sleep = ft_atoi(av[4]);
		shared->is_alive = 1;
		philo[i].starting_time = start_time;
		philo[i].id = i + 1;
		philo[i].shared = shared;
		philo[i].last_meal = get_time() - philo[i].starting_time;
		philo[i].nbr_meals = 0;
		if (av[5])
			philo[i].max_meals = ft_atoi(av[5]);
		else
			philo[i].max_meals = -1;
		philo[i].right_fork = i;
		philo[i].left_fork = (i + n - 1) % n;
		i++;
	}
}
