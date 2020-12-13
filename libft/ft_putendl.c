
#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s == NULL)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}
