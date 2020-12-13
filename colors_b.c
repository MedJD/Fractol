
#include "fractol.h"

int			ft_color_wb(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0xFFFFFF);
	if (iter % 2 == 0)
		return (0xFFFFFF);
	return (0x000000);
}

int			ft_color_orange(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x000000);
	return ((int)(0xFF6B2C + iter * 30));
}

int			ft_color_green(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x000000);
	return ((int)(0x28B463 * iter > 0xFFFFFF ? 0x28B463 / iter / 4 :
				0x28B463 * iter));
}

int			ft_color_blue(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x000000);
	return ((int)(0xC34863 - iter * 10));
}

int			ft_color_red(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x000000);
	return ((int)(0xDA0A0A + iter * 40));
}
