/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:18:58 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/19 20:11:49 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_p_coordinates(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->pos_x = -1;
	map->pos_y = -1;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
			{
				map->pos_x = i;
				map->pos_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	fill_path_to_exit(t_map *map, int row, int col)
{
	if (row < 0 || row >= map->h || col < 0 || col >= map->w)
		return ;
	if (map->map[row][col] == 'E')
	{
		map->map[row][col] = '*';
		return ;
	}
	if (map->map[row][col] != '0'
		&& map->map[row][col] != 'C'
		&& map->map[row][col] != 'P')
		return ;
	map->map[row][col] = '*';
	fill_path_to_exit(map, row + 1, col);
	fill_path_to_exit(map, row - 1, col);
	fill_path_to_exit(map, row, col + 1);
	fill_path_to_exit(map, row, col - 1);
}

int	is_valid_path(t_map map)
{
	int		i;
	int		j;

	fill_path_to_exit(&map, map.pos_x, map.pos_y);
	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'C' || map.map[i][j] == 'E')
				return (0);
				j++;
		}
		i++;
	}
	return (1);
}
