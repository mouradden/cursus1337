/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:43:56 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/16 20:24:59 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_and_exit_success(t_map map)
{
	free_2_dimensions(map.map);
	mlx_clear_window(map.mlx, map.win);
	mlx_destroy_window(map.mlx, map.win);
	exit(0);
}

void	free_and_exit_failure(t_map map)
{
	free_2_dimensions(map.map);
	mlx_clear_window(map.mlx, map.win);
	mlx_destroy_window(map.mlx, map.win);
	exit(1);
}
