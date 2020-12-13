
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*cp;

	i = 0;
	while (src[i])
		i++;
	cp = (char*)malloc(i + 1);
	if (cp == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
