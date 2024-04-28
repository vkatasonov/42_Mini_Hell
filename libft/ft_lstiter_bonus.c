/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:47:53 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/25 17:59:16 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates through the linked list 
 * & applies the function `f` to each element 
 * of the linked list `lst`.
 *
 * @param lst The pointer to the first element of the linked list.
 * @param f   The function to apply to each element of the linked list.
 * @note void (*f)(void *) is the pointer to the function 
 * that receives void and returns nothing and is used to apply
 * the function to each element of the linked list (basically, function callback)
 * @return if the linked list is `empty`, the function returns nothing and goes back
 * to the caller function.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	if (lst->next)
		ft_lstiter(lst->next, f);
	f(lst->content);
}
