/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:20:09 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/20 17:34:37 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function that creates a `new node` 
 * within linked list with the given content.
 *
 * @param content The content to be stored in the new node
 * (can be any content including structs and even NULL).
 * @return A pointer to the newly created list node.
 * @note If the memory allocation fails, the function returns `0`.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof (t_list));
	if (!lst)
		return (0);
	lst -> content = (void *) content;
	lst -> next = NULL;
	return (lst);
}
