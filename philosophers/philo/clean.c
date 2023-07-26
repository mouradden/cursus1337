/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:14:39 by mdenguir          #+#    #+#             */
/*   Updated: 2023/07/25 11:00:52 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->shared->nb_philos)
	{
		pthread_mutex_destroy(&philo[i].shared->mutex);
		i++;
	}
	i = 0;
	while (i < philo->shared->nb_philos)
	{
		pthread_mutex_destroy(&philo[i].shared->forks[i]);
		i++;
	}
	free(philo->shared->forks);
	free(philo->shared);
}
