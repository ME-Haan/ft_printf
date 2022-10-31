/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:47:56 by mhaan         #+#    #+#                 */
/*   Updated: 2022/10/26 15:37:34 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mapped;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (0);
	mapped = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&mapped, del);
			return (0);
		}
		ft_lstadd_back(&mapped, tmp);
		lst = lst->next;
	}
	return (mapped);
}
