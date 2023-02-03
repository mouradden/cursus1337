#ifndef MINILIBX_H
# define MINILIBX_H
#include "./gnl/get_next_line.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_map{
    char    **map;
    int     h;
    int     w;
}           t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

char **read_map(char *path);
int count_lines(char *path);
int valid_map(char **str);
int ft_strlength(char **s);
void	ft_putnbr(long n);
#endif