/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_outils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:50:40 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/15 12:12:50 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_height(char **s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_get_width(char **s)
{
	int		i;

	i = 0;
	while (s[0][i])
	{
		i++;
	}
	return (i);
}

int	count_collect(char **str)
{
	int		i;
	int		j;
	int		count_c;

	i = 0;
	count_c = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'C')
				count_c++;
			j++;
		}
		i++;
	}
	return (count_c);
}

int	detect_exit(char **str)
{
	int		i;
	int		j;
	int		count_e;

	i = 0;
	count_e = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'E')
				count_e++;
			j++;
		}
		i++;
	}
	return (count_e);
}

int	is_p_still_alive(char **str)
{
	int		i;
	int		j;
	int		count_p;

	i = 0;
	count_p = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				count_p++;
			j++;
		}
		i++;
	}
	return (count_p);
}
