/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:47:52 by vkatason          #+#    #+#             */
/*   Updated: 2023/10/04 14:42:38 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief function that clears the list
 * 
 * @param lst current list (or stack in our case)
 * @param del is the variablee which takes the 
 * address of the function.
 * 
 * @note void (*del)(void *) is the pointer to the function
 * that receives void and returns nothing
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*that;
	t_list	*nextone;

	if (*lst != NULL && lst != NULL)
	{
		that = *lst;
		while (that -> next != NULL)
		{
			nextone = that -> next;
			ft_lstdelone(that, del);
			that = nextone;
		}
		ft_lstdelone(that, del);
		*lst = NULL;
	}
}
