
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*zone;

	zone = (void *)malloc(size);
	if (zone == NULL)
		return (NULL);
	ft_memset(zone, 0, size);
	return (zone);
}
