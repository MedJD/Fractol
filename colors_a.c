
#include "fractol.h"

int		ft_color_bw(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x000000);
	if (iter % 2 == 0)
		return (0x000000);
	return (0xFFFFFF);
}

int		ft_color_blueciel(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x000000);
	return ((int)(0x4FC3F7 * iter > 0xFFFFFF ? (int)(0x4FC3F7 / iter) :
				0x4FC3F7 * iter));
}

int		ft_color_marron(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0xB71C1C);
	return ((int)(0x4E342E * iter > 0xFFFFFF ? (int)(0x4FC3F7 / iter) :
				0x4E342E * iter));
}

int		ft_color_yellow(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x000000);
	return (0xFFD700 + iter * 550);
}

int		ft_color_purple(int iter, t_ptr *p)
{
	if (iter == p->prof_max)
		return (0x4D0066);
	return (0x483D8B + iter * 10);
}
