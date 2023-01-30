/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:34:15 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/30 22:14:19 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_and_check_sorted(char **args, t_stack **sa)
{
	int		count;

	count = 0;
	while (args[count])
		count++;
	count--;
	while (count >= 0)
		ft_push(sa, ft_atoi(args[count--]));
	free_split(args);
	if (check_sorted(sa))
	{
		free_stack(sa);
		exit(0);
	}			
}

char	**get_args(char **av, char *join)
{
	int		i;
	char	**args;

	i = 1;
	while (av[i])
	{
		if (!ft_strlen(av[i]) || check_empty(av[i]))
		{
			free(join);
			write(2, "Error\n", 6);
			exit(1);
		}
		join = ft_strjoin(join, av[i]);
		join = ft_strjoin(join, " ");
		i++;
	}
	args = ft_split(join, ' ');
	free(join);
	return (args);
}

void	are_args_valid(char **args)
{
	if (!check_args(args) || !check_duplicate(args))
	{
		free_split(args);
		write(2, "Error\n", 6);
		exit(1);
	}
	if (!args[1])
	{
		free_split(args);
		exit(0);
	}
}

int	check_args(char **args)
{
	int		i;
	int		j;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '-' && args[i][1] == '\0')
			return (0);
		if (ft_atoi(args[i]) > 2147483647 || ft_atoi(args[i]) < -2147483648)
			return (0);
		j = 0;
		if (args[i][0] == '-')
			j = 1;
		while (args[i][j])
		{
			if (args[i][j] == '-' && args[i][j + 1] == '\0')
				return (0);
			if (args[i][j] < '0' || args[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicate(char **args)
{
	int		i;
	int		j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			while (args[j] && ft_atoi(args[i]) != ft_atoi(args[j]))
				j++;
			if (args[j] && args[i] && ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
		}
		i++;
	}
	return (1);
}
