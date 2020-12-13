
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, int nb)
{
	int		i;
	int		size;
	int		count;

	size = -1;
	i = 0;
	count = 0;
	while (dest[i])
	{
		size++;
		i++;
	}
	i = 0;
	while (src[i] && count < nb)
	{
		dest[size + i + 1] = src[i];
		i++;
		count++;
	}
	dest[size + i + 1] = '\0';
	return (dest);
}
