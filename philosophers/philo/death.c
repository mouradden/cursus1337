/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:24:42 by mdenguir          #+#    #+#             */
/*   Updated: 2023/07/25 15:01:47 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_death(t_philo *philo, int ac)
{
	int		i;

	i = 0;
	while (i < philo->shared->nb_philos)
	{
		if (ac == 6 && philo[i].nbr_meals > philo[i].max_meals)
			return ;
		if ((get_time() - philo[i].starting_time - philo[i].last_meal)
			>= philo[i].shared->time_to_die)
		{
			pthread_mutex_lock(&philo[i].shared->mutex);
			philo[i].shared->is_alive = 0;
			pthread_mutex_unlock(&philo[i].shared->mutex);
			pthread_mutex_lock(&philo[i].shared->print);
			printf("%ld %d %s\n", get_time() - philo[i].starting_time,
				philo[i].id, "died");
			return ;
		}
		i++;
		if (i == philo->shared->nb_philos)
			i = 0;
	}
}
