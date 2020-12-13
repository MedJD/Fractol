
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = -1;
	if (src < dst)
		while ((int)(--len) >= 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	else
		while (++i < (int)len)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	return (dst);
}
