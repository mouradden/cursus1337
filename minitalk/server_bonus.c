/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:44:31 by mdenguir          #+#    #+#             */
/*   Updated: 2023/01/10 19:31:55 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	my_handler(int sig, siginfo_t *info, void *s)
{
	static int		pid;
	static int		bit;
	static int		index;

	(void)s;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		bit = 0;
		index = 0;
	}
	if (sig == SIGUSR2)
		bit += (1 << index);
	index++;
	if (index == 8)
	{
		if (bit != '\0')
			ft_putchar_fd(bit, 1);
		else
			kill (info->si_pid, SIGUSR2);
		bit = 0;
		index = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	sa.sa_sigaction = my_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
