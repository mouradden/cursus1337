/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:50:43 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/17 10:45:08 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int keycode, t_map *map)
{
	find_p_coordinates(map);
	map->count_c = count_collect(map->map);
	if (keycode == 53)
	{
		destroy_images(*map);
		free_and_exit_success(*map);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		if (keycode == 13)
			move_up(map);
		else if (keycode == 0)
			move_left(map);
		else if (keycode == 1)
			move_down(map);
		else if (keycode == 2)
			move_right(map);
		build_window(*map);
	}
	return (0);
}

void	move_up(t_map *map)
{
	if (map->map[map->pos_x - 1][map->pos_y] == 'E')
	{
		if (!count_collect(map->map))
		{
			map->map[map->pos_x - 1][map->pos_y] = 'P';
			map->map[map->pos_x][map->pos_y] = '0';
		}	
	}
	else if (map->map[map->pos_x - 1][map->pos_y] != '1'
		&& map->map[map->pos_x - 1][map->pos_y] != 'E'
		&& map->map[map->pos_x - 1][map->pos_y] != 'X')
	{
		map->map[map->pos_x - 1][map->pos_y] = 'P';
		map->map[map->pos_x][map->pos_y] = '0';
		map->moves++;
		ft_printf("%d moves\n", map->moves);
	}
}

void	move_left(t_map *map)
{
	if (map->map[map->pos_x][map->pos_y - 1] == 'E')
	{
		if (!count_collect(map->map))
		{
			map->map[map->pos_x][map->pos_y - 1] = 'P';
			map->map[map->pos_x][map->pos_y] = '0';
		}		
	}
	else if (map->map[map->pos_x][map->pos_y - 1] != '1'
		&& map->map[map->pos_x][map->pos_y - 1] != 'E'
		&& map->map[map->pos_x][map->pos_y - 1] != 'X')
	{
		map->map[map->pos_x][map->pos_y - 1] = 'P';
		map->map[map->pos_x][map->pos_y] = '0';
		map->moves++;
		ft_printf("%d moves\n", map->moves);
	}
}

void	move_down(t_map *map)
{
	if (map->map[map->pos_x + 1][map->pos_y] == 'E')
	{
		if (!count_collect(map->map))
		{
			map->map[map->pos_x + 1][map->pos_y] = 'P';
			map->map[map->pos_x][map->pos_y] = '0';
		}		
	}
	else if (map->map[map->pos_x + 1][map->pos_y] != '1'
		&& map->map[map->pos_x + 1][map->pos_y] != 'E'
		&& map->map[map->pos_x + 1][map->pos_y] != 'X')
	{
		map->map[map->pos_x + 1][map->pos_y] = 'P';
		map->map[map->pos_x][map->pos_y] = '0';
		map->moves++;
		ft_printf("%d moves\n", map->moves);
	}
}

void	move_right(t_map *map)
{
	if (map->map[map->pos_x][map->pos_y + 1] == 'E')
	{
		if (!count_collect(map->map))
		{
			map->map[map->pos_x][map->pos_y + 1] = 'P';
			map->map[map->pos_x][map->pos_y] = '0';
		}
	}
	else if (map->map[map->pos_x][map->pos_y + 1] != '1'
	&& map->map[map->pos_x][map->pos_y + 1] != 'E'
	&& map->map[map->pos_x][map->pos_y + 1] != 'X')
	{
		map->map[map->pos_x][map->pos_y + 1] = 'P';
		map->map[map->pos_x][map->pos_y] = '0';
		map->moves++;
		ft_printf("%d moves\n", map->moves);
	}
}
