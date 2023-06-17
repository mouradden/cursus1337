/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:50:51 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/14 17:03:15 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_moves(t_map *map)
{
	char	*str_moves;

	str_moves = ft_itoa(map->moves);
	mlx_string_put(map->mlx, map->win, 10, 10, 0x00FFFFFF, str_moves);
	free(str_moves);
	mlx_string_put(map->mlx, map->win, 40, 10, 0x00FFFFFF, "moves");
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
