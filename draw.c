
#include "fractol.h"

void	ft_draw_fractal(t_thread *p, int b, int a)
{
	if (p->e->type == 0)
		ft_mlx_putpixel(p->e, b, a, ft_mandelbrot(p->e, b, a));
	else if (p->e->type == 1)
		ft_mlx_putpixel(p->e, b, a, ft_julia(p->e, b, a));
	else if (p->e->type == 2)
		ft_mlx_putpixel(p->e, b, a, ft_tricorne(p->e, b, a));
	else if (p->e->type == 3)
		ft_mlx_putpixel(p->e, b, a, ft_burningship(p->e, b, a));
	else if (p->e->type == 4)
		ft_mlx_putpixel(p->e, b, a, ft_monsieur(p->e, b, a));
	else if (p->e->type == 5)
		ft_mlx_putpixel(p->e, b, a, ft_negatibrot(p->e, b, a));
	else if (p->e->type == 6)
		ft_mlx_putpixel(p->e, b, a, ft_mandelbrot_1(p->e, b, a));
	else if (p->e->type == 7)
		ft_mlx_putpixel(p->e, b, a, ft_quadcorne(p->e, b, a));
}

void	ft_write_img(t_thread *p)
{
	int			a;
	int			b;

	a = 0;
	while (a < (int)IMG_DIM)
	{
		b = (int)(p->i * IMG_DIM / NBTHREAD);
		while (b < (int)((p->i + 1) * IMG_DIM / NBTHREAD))
		{
			ft_draw_fractal(p, (long double)b, (long double)a);
			b++;
		}
		a++;
	}
	pthread_exit(NULL);
}

void	ft_draw(t_ptr *p)
{
	int			i;
	int			j;

	i = 459;
	ft_bzero(p->data, (int)IMG_DIM * (int)IMG_DIM * 4);
	ft_begin(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	while (++i < IMG_DIM)
	{
		j = IMG_DIM;
		while (++j < IMG_DIM + 18)
			mlx_pixel_put(p->mlx, p->win, i, j, 0x000000);
	}
	mlx_string_put(p->mlx, p->win, 460, IMG_DIM - 4, 0xFAFA00,
			"Number of iterations :");
	mlx_string_put(p->mlx, p->win, 681, IMG_DIM - 4, 0xFF0000,
			ft_itoa(p->prof_max));
	mlx_string_put(p->mlx, p->win, 709, IMG_DIM - 4, 0xFAFA00,
			"| Fractal type : ");
	mlx_string_put(p->mlx, p->win, 875, IMG_DIM - 4, 0xFF0000,
			ft_detect_type(p));
}

void	ft_begin(t_ptr *p)
{
	pthread_t	thread[NBTHREAD];
	t_thread	div[NBTHREAD];
	int			i;

	i = 0;
	while (i < NBTHREAD)
	{
		div[i].e = p;
		div[i].i = i;
		pthread_create(&thread[i], NULL, (void*)ft_write_img, &div[i]);
		i++;
	}
	while (--i >= 0)
		pthread_join(thread[i], NULL);
}
