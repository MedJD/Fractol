
#include "fractol.h"

int		ft_julia(t_ptr *p, long double col, long double row)
{
	int				iter;
	t_com			z;
	t_com			c;
	long double		tmp;

	z.re = p->x_min + ((p->x_max - p->x_min) / IMG_DIM) * col;
	z.im = p->y_min + ((p->y_max - p->y_min) / IMG_DIM) * row;
	c.re = p->jul_re;
	c.im = p->jul_im;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < p->prof_max)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_mandelbrot(t_ptr *p, long double col, long double row)
{
	int				iter;
	t_com			z;
	t_com			c;
	long double		tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / IMG_DIM) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / IMG_DIM) * row;
	z.re = 0.0;
	z.im = 0.0;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < p->prof_max)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * tmp * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_burningship(t_ptr *p, long double col, long double row)
{
	int				iter;
	t_com			z;
	t_com			c;
	long double		tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / IMG_DIM) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / IMG_DIM) * row;
	z.re = 0.0;
	z.im = 0.0;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < p->prof_max)
	{
		tmp = z.re;
		z.re = z.re * z.re - z.im * z.im + c.re;
		if (tmp < 0)
			tmp *= -1.0;
		if (z.im < 0)
			z.im *= -1.0;
		z.im = 2 * (tmp) * (z.im) + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_mandelbrot_1(t_ptr *p, long double col, long double row)
{
	int				iter;
	t_com			z;
	t_com			c;
	long double		tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / IMG_DIM) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / IMG_DIM) * row;
	z.re = 0.0;
	z.im = 0.0;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < p->prof_max)
	{
		tmp = z.re;
		z.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re;
		z.im = 3 * tmp * tmp * z.im - z.im * z.im * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_get_color(int iter, t_ptr *p)
{
	if (p->col_type == 0)
		return (ft_color_bw(iter, p));
	if (p->col_type == 1)
		return (ft_color_wb(iter, p));
	if (p->col_type == 2)
		return (ft_color_orange(iter, p));
	if (p->col_type == 3)
		return (ft_color_blueciel(iter, p));
	if (p->col_type == 4)
		return (ft_color_yellow(iter, p));
	if (p->col_type == 5)
		return (ft_color_green(iter, p));
	if (p->col_type == 6)
		return (ft_color_marron(iter, p));
	if (p->col_type == 7)
		return (ft_color_red(iter, p));
	if (p->col_type == 8)
		return (ft_color_purple(iter, p));
	return (ft_color_blue(iter, p));
}
