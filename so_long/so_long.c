/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:50:46 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/20 10:21:31 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_program(t_map *map)
{
	ft_printf("The window has been closed\n");
	destroy_images(*map);
	free_and_exit_success(*map);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2)
	{
		init(&map, av[1]);
		check_args(av[1]);
		build_window(map);
		mlx_hook(map.win, 2, 0, key_pressed, &map);
		mlx_hook(map.win, 17, 0L, close_program, &map);
		mlx_loop(map.mlx);
	}
	else
		ft_printf("Invalid arguments! SYNTAX : ./so_long map.ber\n");
}
