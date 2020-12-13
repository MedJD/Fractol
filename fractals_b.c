
#include "fractol.h"

int		ft_tricorne(t_ptr *p, long double col, long double row)
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
		z.im = -1 * 2 * tmp * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_quadcorne(t_ptr *p, long double col, long double row)
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
		z.im = -3 * tmp * tmp * z.im + z.im * z.im * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_negatibrot(t_ptr *p, long double col, long double row)
{
	int				iter;
	t_com			z;
	t_com			c;
	long double		tmp;

	c.re = p->x_min + ((p->x_max - p->x_min) / IMG_DIM) * col;
	c.im = p->y_min + ((p->y_max - p->y_min) / IMG_DIM) * row;
	z.re = c.re;
	z.im = c.im;
	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < p->prof_max)
	{
		tmp = z.re;
		z.re = (z.re * z.re - z.im * z.im) / (z.re * z.re * z.re * z.re
				+ z.im * z.im * z.im * z.im + 2 * z.re * z.re * z.im * z.im)
			+ c.re;
		z.im = -(2 * tmp * z.im) / (tmp * tmp * tmp * tmp + z.im * z.im *
				z.im * z.im + 2 * tmp * tmp * z.im * z.im) + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

int		ft_monsieur(t_ptr *p, long double col, long double row)
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
		if (z.re < 0)
			z.re *= -1;
		tmp = z.re;
		z.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re;
		z.im = -3 * tmp * tmp * z.im + z.im * z.im * z.im + c.im;
		iter++;
	}
	return (ft_get_color(iter, p));
}

char	*ft_detect_type(t_ptr *p)
{
	if (p->type == 0)
		return ("Mandelbrot");
	if (p->type == 1)
		return ("Julia");
	if (p->type == 2)
		return ("Tricorne");
	if (p->type == 3)
		return ("Burningship");
	if (p->type == 4)
		return ("Monsieur");
	if (p->type == 5)
		return ("Negatibrt");
	if (p->type == 6)
		return ("Mandelbrot_1");
	if (p->type == 7)
		return ("Quadcorne");
	return ("NO Fracts");
}
