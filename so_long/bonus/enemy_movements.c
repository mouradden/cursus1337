/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:33:41 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/20 12:21:21 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	move_enemy(t_map *map)
{
	int			random_num;
	static int	a;

	find_x_coordinates(map);
	if (map->enemy_x == -1 && map->enemy_y == -1)
		return (1);
	if (a > 30)
	{
		random_num = rand() % 4;
		if (random_num == 0)
			move_x_up(*map);
		else if (random_num == 1)
			move_x_left(*map);
		else if (random_num == 2)
			move_x_right(*map);
		else if (random_num == 3)
			move_x_down(*map);
		a = 0;
	}
	else
		a++;
	build_window(*map);
	display_moves(map);
	return (0);
}

void	move_x_up(t_map map)
{
	if (map.map[map.enemy_x - 1][map.enemy_y] != '1'
		&& map.map[map.enemy_x - 1][map.enemy_y] != 'E'
		&& map.map[map.enemy_x - 1][map.enemy_y] != 'C'
		&& map.map[map.enemy_x - 1][map.enemy_y] != 'X')
	{
		map.map[map.enemy_x - 1][map.enemy_y] = 'X';
		map.map[map.enemy_x][map.enemy_y] = '0';
	}
}

void	move_x_left(t_map map)
{
	if (map.map[map.enemy_x][map.enemy_y - 1] != '1'
		&& map.map[map.enemy_x][map.enemy_y - 1] != 'E'
		&& map.map[map.enemy_x][map.enemy_y - 1] != 'C'
		&& map.map[map.enemy_x][map.enemy_y - 1] != 'X')
	{
		map.map[map.enemy_x][map.enemy_y - 1] = 'X';
		map.map[map.enemy_x][map.enemy_y] = '0';
	}
}

void	move_x_right(t_map map)
{
	if (map.map[map.enemy_x][map.enemy_y + 1] != '1'
		&& map.map[map.enemy_x][map.enemy_y + 1] != 'E'
		&& map.map[map.enemy_x][map.enemy_y + 1] != 'C'
		&& map.map[map.enemy_x][map.enemy_y + 1] != 'X')
	{
		map.map[map.enemy_x][map.enemy_y + 1] = 'X';
		map.map[map.enemy_x][map.enemy_y] = '0';
	}
}

void	move_x_down(t_map map)
{
	if (map.map[map.enemy_x + 1][map.enemy_y] != '1'
		&& map.map[map.enemy_x + 1][map.enemy_y] != 'E'
		&& map.map[map.enemy_x + 1][map.enemy_y] != 'C'
		&& map.map[map.enemy_x + 1][map.enemy_y] != 'X')
	{
		map.map[map.enemy_x + 1][map.enemy_y] = 'X';
		map.map[map.enemy_x][map.enemy_y] = '0';
	}
}
