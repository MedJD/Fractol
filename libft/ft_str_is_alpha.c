
#include "libft.h"

int		ft_str_is_alpha(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] > '@' && str[i] < '[') || (str[i] > '`' && str[i] < '{')))
			return (0);
		i++;
	}
	return (1);
}
