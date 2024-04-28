/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:00:51 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/25 19:45:47 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function applies the function 'f' 
 * to each element of the linked list 'lst' 
 * and creates a new list with the results. 
 * The 'del' function is used to delete 
 * the content of an element if needed.
 *
 * @param lst The pointer to the `first` element of the list.
 * @param f The `function to apply` to each element.
 * @param del The function used to `delete` the content of an element.
 * @return The new list created by applying 'f' to each element of 'lst' or 
 * NULL if 'lst' is NULL or 'f' is NULL.
 * @note void *(*f)(void *) is the pointer to the function that receives void
 * and returns a pointer to void and void (*del)(void *) is the pointer to the
 * function that receives void and returns nothing and is used to delete the
 * content of the node.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;

	if (!lst && !f)
		return (NULL);
	newlist = 0;
	while (lst)
	{
		newnode = ft_lstnew (0);
		if (!newnode)
		{
			ft_lstclear (&newlist, del);
			return (NULL);
		}
		newnode->content = f(lst->content);
		ft_lstadd_back(&newlist, newnode);
		lst = lst -> next;
	}
	return (newlist);
}
