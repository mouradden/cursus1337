/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:13:42 by mdenguir          #+#    #+#             */
/*   Updated: 2023/07/25 11:34:05 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_behavior(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->shared->print);
	printf("%ld %d %s\n", get_time() - p->starting_time, p->id, str);
	pthread_mutex_unlock(&p->shared->print);
}

void	*routine(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	if (p->id % 2 != 0 && p->shared->nb_philos != 1)
		usleep(200);
	while (p->shared->is_alive)
	{
		print_behavior(p, "is thinking");
		pthread_mutex_lock(&p->shared->forks[p->right_fork]);
		print_behavior(p, "has taken a fork");
		pthread_mutex_lock(&p->shared->forks[p->left_fork]);
		print_behavior(p, "has taken a fork");
		print_behavior(p, "is eating");
		pthread_mutex_lock(&p->shared->mutex);
		p->last_meal = get_time() - p->starting_time;
		p->nbr_meals++;
		pthread_mutex_unlock(&p->shared->mutex);
		ft_usleep(p->shared->time_to_eat);
		pthread_mutex_unlock(&p->shared->forks[p->right_fork]);
		pthread_mutex_unlock(&p->shared->forks[p->left_fork]);
		print_behavior(p, "is sleeping");
		ft_usleep(p->shared->time_to_sleep);
	}
	return (NULL);
}
