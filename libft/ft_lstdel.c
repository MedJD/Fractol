
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	while ((*alst)->next != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		(*alst) = (*alst)->next;
	}
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
