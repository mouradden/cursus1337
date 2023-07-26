/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:23:36 by mdenguir          #+#    #+#             */
/*   Updated: 2023/07/25 15:00:03 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("ERROR : number of arguments is not correct\n");
		exit(1);
	}
	if (ac == 6 && ft_atoi(av[5]) == 0)
	{
		printf("ERROR : number of meals must be higher than 0\n");
		exit(1);
	}
	if (!check_args(av))
	{
		printf("ERROR : only digits & positive numbers\n");
		exit(1);
	}
	if (!check_values(av))
	{
		printf("ERROR : something wrong with the values inserted\n");
		exit(1);
	}
}

int	check_args(char **args)
{
	int		i;
	int		j;

	i = 1;
	while (args[i])
	{
		j = 0;
		if (args[i][0] == '+' && (args[i][1] >= '0' || args[i][1] <= '9'))
			j = 1;
		while (args[i][j])
		{
			if (args[i][j] == '-' && args[i][j + 1] == '\0')
				return (0);
			if (args[i][j] == '+' && args[i][j + 1] == '\0')
				return (0);
			if (args[i][j] < '0' || args[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_values(char **av)
{
	int		i;

	i = 2;
	if (ft_atoi(av[1]) > 200 || ft_atoi(av[1]) < 1)
		return (0);
	while (i == 2 || i == 3 || i == 4)
	{
		if (ft_atoi(av[i]) < 60)
			return (0);
		i++;
	}
	return (1);
}
