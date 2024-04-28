/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:17:19 by vkatason          #+#    #+#             */
/*   Updated: 2023/10/11 14:33:01 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function deletes the given 
 * node `lst` from the linked list.
 * The `del` function is called 
 * to free the memory allocated for 
 * the content of the node.
 *
 * @param lst The node to be deleted.
 * @param del The function used to delete the content of the node.
 * @note void (*del)(void *) is the pointer to the function
 * that receives void and returns nothing and is used to delete 
 * the content of the node.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	(*del)(lst -> content);
	free(lst);
}
