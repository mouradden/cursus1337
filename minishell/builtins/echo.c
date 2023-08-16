/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:56:05 by mdenguir          #+#    #+#             */
/*   Updated: 2023/08/16 17:45:38 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo(char **input)
{
	int		i;
	int		j;
	int		temp;

	i = 1;
	temp = 0;
	while (input[i])
	{
		if (input[i][0] && input[i][0] == '-')
		{
			j = 1;
			while (input[i][j] && input[i][j] == 'n')
				j++;
			if (input[i][j] == '\0')
				temp = 1;
			else
			{
				ft_putstr_fd(input[i], 1);
			}
		}
		
		else
		{
			ft_putstr_fd(input[i], 1);
		}
		if (input[i + 1] && !ft_strcmp(input[i + 1], " "))
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (temp != 1)
		ft_putchar_fd('\n', 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = 0;
	if (!s)
	{
		return ;
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}