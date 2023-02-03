#include "minilibx.h"

// typedef struct s_data
// {
//     void *img;
//     char *addr;
//     int     bits_per_pixel;
//     int     line_length;
//     int     endian;
// }       t_data;
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
// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }
// int key_hook(int keycode, void *param)
// {
//     //w=13, A=0, s=1,d=2
//     // write(1, "x", 1);
//     ft_putnbr(keycode);
//     return (0);
// }

}