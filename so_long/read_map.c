#include "minilibx.h"

int ft_strlength(char **s)
{
	int i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }
// void	ft_putnbr(long n)
// {
// 	int		count;

// 	count = 0;
// 	if (n <= 9 && n >= 0)
// 		ft_putchar(n + '0');
// 	else if (n < 0)
// 	{
// 		ft_putchar('-');
// 		n *= -1;
// 		ft_putnbr(n);
// 	}
// 	else
// 	{
// 		ft_putnbr(n / 10);
// 		ft_putnbr(n % 10);
// 	}
// }

// int main()
// {
//     int fd;
//     int i = 0;

//     char **res = read_map("t.txt");
//     // while (res[i])
//     // {
//     //     printf("%s", res[i]);
//     //     i++;
//     // }
	
// 	printf("|%d|\n", valid_map(res));
// }
void render(t_map *map)
{
	int i=0, j=0;
	int a=0, b=0;
	t_vars vars;
	void *img;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx,500,500, "so_long game");
	
	// if (!valid_map(map->map))
	// 	return (void)0;
	
	// while (map->map[i] && b<500)
	// {
	// 	j=0;
	// 	a=0;
	// 	while (map->map[i][j] && a<500)
	// 	{   
	// 		if(map->map[i][j] == '1')
	// 		{
	// 			img = mlx_xpm_file_to_image(vars.win, "./w.xpm", &map->w, &map->h);
	// 			mlx_put_image_to_window(vars.mlx, vars.win, img, a, b);
	// 		}
	// 		else if(map->map[i][j] == 'p')
	// 		{
	// 			img = mlx_xpm_file_to_image(vars.win, "./p.xpm", &map->w, &map->h);
	// 			mlx_put_image_to_window(vars.mlx, vars.win, img, a, b);
	// 		}
	// 		else if(map->map[i][j] == 'e')
	// 		{
	// 			img = mlx_xpm_file_to_image(vars.win, "./ee.xpm", &map->w, &map->h);
	// 			mlx_put_image_to_window(vars.mlx, vars.win, img, a, b);
	// 		}
	// 		j++;
	// 		a+=50;
	// 	}
	// 	i++;
	// 	b += 50;
	// }
	mlx_loop(vars.mlx);
}
// int main()
// {
// 	t_map *map;
// 	int i=0;
// 	map->map = read_map("t.txt");
// 	// while(map->map[i])
// 	// {
// 	// 	printf("|%s|", map->map[i]);
// 	// 	i++;
// 	// }
// 	render(map);
// 	return 0;
// }