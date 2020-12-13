
#include "fractol.h"
#include <stdio.h>

void	ft_zoom(t_ptr *p, long double x, long double y, long double k)
{
	long double		x1;
	long double		y1;

	x1 = (x / IMG_DIM) * (p->x_max - p->x_min) + p->x_min;
	y1 = (y / IMG_DIM) * (p->y_max - p->y_min) + p->y_min;
	p->x_min = x1 + ((p->x_min - x1) * k);
	p->y_min = y1 + ((p->y_min - y1) * k);
	p->x_max = x1 + ((p->x_max - x1) * k);
	p->y_max = y1 + ((p->y_max - y1) * k);
}

void	ft_initial(t_ptr **p)
{
	(*p) = (struct s_ptr *)malloc(sizeof(struct s_ptr));
	(*p)->bpp = (int *)malloc(4);
	(*p)->size = (int *)malloc(4);
	(*p)->endian = (int *)malloc(4);
	(*p)->img = NULL;
	(*p)->mlx = NULL;
	(*p)->data = NULL;
	(*p)->win = NULL;
	(*p)->zoom = 1.0;
	(*p)->y_max = 2.0;
	(*p)->x_max = 2.0;
	(*p)->x_min = -2.0;
	(*p)->y_min = -2.0;
	(*p)->jul_re = 0.0;
	(*p)->jul_im = 0.0;
	(*p)->pause = 0;
	(*p)->speed = 0.8;
	(*p)->prof_max = MAX_ITER;
	(*p)->col_type = 2;
}

void	ft_puthelp(t_ptr *p, char **argv)
{
	if (p)
		free(p);
	ft_putstr("\ninvalid Type \"");
	ft_putstr(argv[1]);
	ft_putstr("\"\n\n");
	ft_putstr("Available Fractals : \n");
	ft_putstr("\t1-Julia\n\t2-Mandelbrot\n\t3-mandelbrot_1\n");
	ft_putstr("\t4-Negatibrot\n\t5-Tricorne\n\t6-Quadcorne\n");
	ft_putstr("\t7-Burningship\n\t8-Monsieur\n");
	exit(0);
}

void	ft_detect_fract(t_ptr **p, char **argv)
{
	ft_initial(p);
	argv[1] = ft_strcapitalize(argv[1]);
	if (ft_strcmp("Mandelbrot", argv[1]) == 0)
		(*p)->type = 0;
	else if (ft_strcmp("Julia", argv[1]) == 0)
		(*p)->type = 1;
	else if (ft_strcmp("Tricorne", argv[1]) == 0)
		(*p)->type = 2;
	else if (ft_strcmp("Burningship", argv[1]) == 0)
		(*p)->type = 3;
	else if (ft_strcmp("Monsieur", argv[1]) == 0)
		(*p)->type = 4;
	else if (ft_strcmp("Negatibrot", argv[1]) == 0)
		(*p)->type = 5;
	else if (ft_strcmp("Quadcorne", argv[1]) == 0)
		(*p)->type = 7;
	else if (ft_strcmp("Mandelbrot_1", argv[1]) == 0)
		(*p)->type = 6;
	else
		ft_puthelp(*p, argv);
}

int		main(int argc, char **argv)
{
	t_ptr		*p;

	p = NULL;
	if (argc != 2)
	{
		ft_putstr("Usage : ./fractol [fractal_type]\n");
		exit(0);
	}
	ft_detect_fract(&p, argv);
	ft_creat_window(p);
	ft_title(p);
	ft_creat_image(p);
	ft_draw(p);
	mlx_hook(p->win, 2, 0, ft_deal_key, p);
	mlx_hook(p->win, 6, 0, ft_mouse_move, p);
	mlx_hook(p->win, 4, 0, ft_mouse_press, p);
	mlx_loop(p->mlx);
}
