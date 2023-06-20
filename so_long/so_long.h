/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:50:48 by mdenguir          #+#    #+#             */
/*   Updated: 2023/06/19 11:03:26 by mdenguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./gnl/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include <mlx.h>
# include <stdlib.h>

typedef struct s_imgs{
	void	*w;
	void	*p;
	void	*e;
	void	*c;
	void	*em;
}	t_imgs;

typedef struct s_map{
	char	**map;
	int		h;
	int		w;
	int		pos_x;
	int		pos_y;
	int		moves;
	void	*mlx;
	void	*win;
	int		count_c;
	t_imgs	img;
}	t_map;

char	**read_map(char *path);
int		ft_get_height(char **s);
int		ft_get_width(char **s);
int		count_lines(char *path);
int		ft_strlength(char **s);
char	*ft_strdup(const char *s1);
int		check_wall_map(char **str);
int		check_rectangle_map(char **str);
int		check_unique_p_e_c(char **str);
void	valid_map(char **str);
void	build_window(t_map map);
void	find_p_coordinates(t_map *map);
void	init(t_map *map, char *path);
void	move_up(t_map *map);
void	move_left(t_map *map);
void	move_down(t_map *map);
void	move_right(t_map *map);
void	free_2_dimensions(char **str);
int		count_collect(char **str);
int		detect_exit(char **str);
void	fill_path_to_exit(t_map *map, int row, int col);
int		is_valid_path(t_map map);
void	check_args(char *str);
void	free_and_exit_success(t_map map);
void	free_and_exit_failure(t_map map);
int		key_pressed(int keycode, t_map *map);
void	create_image(t_map *map, t_imgs *imgs);
int		is_p_still_alive(char **str);
void	check_game_status(t_map map);
void	check_pce(int c, int *count_p, int *count_e, int *count_c);
int		check_foreign_lettre(char **str);
void	destroy_images(t_map map);
#endif