/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:44:40 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/10 12:08:32 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
		usleep(500);
		if (check == -1)
			exit(0);
		i++;
	}
}

void	confirm_receiption(int sig, siginfo_t *info, void *s)
{
	(void)info;
	(void)s;
	if (sig == SIGUSR2)
	{
		ft_putstr_fd("\033[1;32m\nwell received\033[0m\n", 1);
		exit(1);
	}	
}

int	main(int ac, char **av)
{
	int					i;
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = confirm_receiption;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			exit(0);
		while (av[2][i])
			send_to_pid(pid, av[2][i++]);
		send_to_pid(pid, '\0');
		while (1)
		{
		}	
	}
	else
		ft_putstr_fd("Be aware about format : ./client_bonus PID data", 1);
	return (0);
}
