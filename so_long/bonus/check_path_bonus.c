/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:01:00 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/16 20:33:37 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	find_x_coordinates(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	map->enemy_x = -1;
	map->enemy_y = -1;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'X')
			{
				map->enemy_x = i;
				map->enemy_y = j;
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
	if (map->map[row][col] != '0'
		&& map->map[row][col] != 'C'
		&& map->map[row][col] != 'E')
		return ;
	if (map->map[row][col] == 'E')
		return ;
	map->map[row][col] = '*';
	fill_path_to_exit(map, row + 1, col);
	fill_path_to_exit(map, row - 1, col);
	fill_path_to_exit(map, row, col + 1);
	fill_path_to_exit(map, row, col - 1);
}

int	is_path_exists_to_exit(t_map map, int row, int col)
{
	int		path_exists;

	path_exists = 0;
	if (row < 0 || row >= map.h || col < 0 || col >= map.w)
		return (0);
	if (map.map[row][col] == 'E' && !count_collect(map.map))
		return (1);
	else if (map.map[row][col] == 'E' && count_collect(map.map))
		return (0);
	if (map.map[row][col] != '0' && map.map[row][col] != 'P'
		&& map.map[row][col] != 'C')
		return (0);
	fill_path_to_exit(&map, row, col);
	return (is_path_exists_to_exit
		(map, row + 1, col)
		|| is_path_exists_to_exit
		(map, row - 1, col)
		|| is_path_exists_to_exit
		(map, row, col + 1)
		|| is_path_exists_to_exit
		(map, row, col - 1));
}

int	is_valide_map(t_map map)
{
	int		i;
	int		j;

	is_path_exists_to_exit(map, map.pos_x, map.pos_y);
	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == 'C')
				return (0);
				j++;
		}
		i++;
	}
	return (1);
}
