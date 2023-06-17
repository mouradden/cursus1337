/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:50:52 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/17 10:45:47 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	loop_ligne(t_map map, int i)
{
	int		j;

	j = 0;
	while (map.map[i][j])
	{
		if (map.map[i][j] == '1')
			mlx_put_image_to_window
			(map.mlx, map.win, map.img.w, j * 50, i * 50);
		else if (map.map[i][j] == 'P')
			mlx_put_image_to_window
			(map.mlx, map.win, map.img.p, j * 50, i * 50);
		else if (map.map[i][j] == 'E')
			mlx_put_image_to_window
			(map.mlx, map.win, map.img.e, j * 50, i * 50);
		else if (map.map[i][j] == 'C')
			mlx_put_image_to_window
			(map.mlx, map.win, map.img.c, j * 50, i * 50);
		else if (map.map[i][j] == '0')
			mlx_put_image_to_window
			(map.mlx, map.win, map.img.em, j * 50, i * 50);
		else if (map.map[i][j] == 'X')
			mlx_put_image_to_window
			(map.mlx, map.win, map.img.en, j * 50, i * 50);
		j++;
	}
}

void	build_window(t_map map)
{
	int		i;

	i = 0;
	mlx_clear_window(map.mlx, map.win);
	while (map.map[i])
	{
		loop_ligne(map, i);
		i++;
	}
	display_moves(&map);
	check_game_status(map);
}

void	check_game_status(t_map map)
{
	if (!detect_exit(map.map) && !count_collect(map.map))
	{
		ft_printf("WIN : Coins collected and Exit Reached");
		destroy_images(map);
		free_and_exit_success(map);
	}
	else if (!is_p_still_alive(map.map))
	{
		ft_printf("LOST!!");
		destroy_images(map);
		free_and_exit_failure(map);
	}	
}

void	create_image(t_map *map, t_imgs *imgs)
{
	int		w;
	int		h;

	w = 50;
	h = 50;
	imgs->w = mlx_xpm_file_to_image(map->mlx, "assets/1.xpm", &w, &h);
	imgs->p = mlx_xpm_file_to_image(map->mlx, "assets/p.xpm", &w, &h);
	imgs->e = mlx_xpm_file_to_image(map->mlx, "assets/e.xpm", &w, &h);
	imgs->c = mlx_xpm_file_to_image(map->mlx, "assets/c.xpm", &w, &h);
	imgs->em = mlx_xpm_file_to_image(map->mlx, "assets/0.xpm", &w, &h);
	imgs->en = mlx_xpm_file_to_image(map->mlx, "assets/X.xpm", &w, &h);
	if (!imgs->w || !imgs->p || !imgs->e
		|| !imgs->c || !imgs->em || !imgs->en)
	{
		ft_printf("ERROR : assets missing !!");
		destroy_images(*map);
		free_and_exit_failure(*map);
	}	
}

void	destroy_images(t_map map)
{
	if (map.img.c)
		mlx_destroy_image(map.mlx, map.img.c);
	if (map.img.e)
		mlx_destroy_image(map.mlx, map.img.e);
	if (map.img.p)
		mlx_destroy_image(map.mlx, map.img.p);
	if (map.img.em)
		mlx_destroy_image(map.mlx, map.img.em);
	if (map.img.w)
		mlx_destroy_image(map.mlx, map.img.w);
}
