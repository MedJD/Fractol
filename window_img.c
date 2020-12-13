
#include "fractol.h"

void	ft_mlx_putpixel(t_ptr *p, int x, int y, int color)
{
	if (x >= 0 && x < IMG_DIM && y >= 0 && y < IMG_DIM)
		p->data[y * (int)IMG_DIM + x] = color;
}

void	ft_creat_window(t_ptr *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, IMG_DIM, IMG_DIM + 36, "fract'ol");
}

void	ft_creat_image(t_ptr *p)
{
	p->img = mlx_new_image(p->mlx, IMG_DIM, IMG_DIM);
	p->data = (int*)mlx_get_data_addr(p->img, p->bpp, p->size, p->endian);
}

void	ft_title(t_ptr *p)
{
	int		i;
	int		j;

	i = 0;
	while (i < IMG_DIM)
	{
		j = 1000;
		while (j < IMG_DIM + 36)
		{
			mlx_pixel_put(p->mlx, p->win, i, j, 0x000000);
			j++;
		}
		i++;
	}
	mlx_string_put(p->mlx, p->win, 7, IMG_DIM - 4,
			0xFAFA00, "1337-FRACT'OL project|");
	mlx_string_put(p->mlx, p->win, 230, IMG_DIM - 4, 0xFAFA00,
			"Realised by:<mel-jadi>| ");
	mlx_string_put(p->mlx, p->win, 7, IMG_DIM + 13, 0xFAFA00,
			"T:Types|P:Pause/Play Julia|R:Reset|C:Colors");
	mlx_string_put(p->mlx, p->win, 450, IMG_DIM + 13, 0xFAFA00,
			"|W/S:Increase/Decrease ieter.|+/-:zoom|Arrows:move");
}

void	ft_reinitialise(t_ptr *p)
{
	p->speed = 0.8;
	p->prof_max = MAX_ITER;
	p->y_max = 2.0;
	p->x_max = 2.0;
	p->x_min = -2.0;
	p->y_min = -2.0;
}
