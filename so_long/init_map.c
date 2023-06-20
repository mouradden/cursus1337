/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:50:37 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/20 12:08:46 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *path)
{
	char	**res;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR \n The file probably doesnt exist\n");
		exit(1);
	}	
	res = malloc(count_lines(path) * (sizeof(char *) + 1));
	if (!res)
		exit(1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		res[i++] = ft_strdup(line);
		free(line);
	}
	res[i] = 0;
	return (res);
}

void	free_2_dimensions(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	init(t_map *map, char *path)
{
	map->map = read_map(path);
	if (map->map[0] == NULL)
	{
		ft_printf("ERROR \n Empty map!\n");
		exit(1);
	}
	valid_map(map->map);
	map->h = ft_get_height(map->map);
	map->w = ft_get_width(map->map) - 1;
	map->moves = 0;
	find_p_coordinates(map);
	if (!is_valid_path(*map))
	{
		ft_printf("ERROR \n invalid path in the map !!!");
		free_2_dimensions(map->map);
		exit(1);
	}
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->w * 50, map->h * 50, "so_long");
	free_2_dimensions(map->map);
	map->map = read_map(path);
	create_image(map, &map->img);
}
