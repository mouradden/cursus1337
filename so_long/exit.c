/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:54:47 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/16 20:34:40 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_exit_success(t_map map)
{
	free_2_dimensions(map.map);
	mlx_clear_window(map.mlx, map.win);
	mlx_destroy_window(map.mlx, map.win);
	exit(0);
}

void	free_and_exit_failure(t_map map)
{
	mlx_clear_window(map.mlx, map.win);
	mlx_destroy_window(map.mlx, map.win);
	exit(1);
}
