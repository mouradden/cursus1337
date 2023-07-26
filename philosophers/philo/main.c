/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:26:17 by mdenguir          #+#    #+#             */
/*   Updated: 2023/07/25 11:34:33 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	pthread_t	*p;
	t_philo		*philo;
	int			i;

	check(ac, av);
	p = malloc(sizeof(pthread_t) * ft_atoi(av[1]));
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	init(philo, av);
	philo->shared->nb_philos = ft_atoi(av[1]);
	i = 0;
	while (i < philo->shared->nb_philos)
	{
		pthread_mutex_lock(&philo[i].shared->mutex);
		pthread_create(&p[i], NULL, routine, &philo[i]);
		pthread_mutex_unlock(&philo[i].shared->mutex);
		usleep(5);
		i++;
	}
	check_death(philo, ac);
	i = 0;
	while (i < philo->shared->nb_philos)
		pthread_detach(p[i++]);
	cleanup(philo);
	exit(0);
}
