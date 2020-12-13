
#include "libft.h"

char	*ft_strrev(char *str)
{
	int		size;
	int		i;
	int		j;
	char	aux;

	size = 0;
	i = 0;
	j = 0;
	while (*(str + size) != '\0')
		size++;
	j = size - 1;
	while (i < (size / 2))
	{
		aux = *(str + i);
		*(str + i) = *(str + j);
		*(str + j) = aux;
		i++;
		j--;
	}
	return (str);
}
