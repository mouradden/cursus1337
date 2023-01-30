/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:55:26 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/10 12:01:21 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_to_pid(int pid, char c)
{
	int		data;
	int		check;
	int		i;

	i = 0;
	while (i < 8)
	{
		data = (c >> i) & 1;
		if (data == 0)
			check = kill(pid, SIGUSR1);
		else
			check = kill(pid, SIGUSR2);
		if (check == -1)
			exit(0);
		usleep(500);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			exit(0);
		while (av[2][i])
		{
			send_to_pid(pid, av[2][i]);
			i++;
		}
		send_to_pid(pid, '\0');
	}
	else
		ft_putstr_fd("Be aware about format : ./client PID data", 1);
	return (0);
}
