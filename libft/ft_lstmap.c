
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_lst;

	if (lst)
	{
		new_lst = f(lst);
		new_lst->next = ft_lstmap(lst->next, f);
		return (new_lst);
	}
	return (NULL);
}
