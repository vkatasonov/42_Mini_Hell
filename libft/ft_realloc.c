/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:55:14 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/29 23:25:47 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		42 implementation of a standart realloc function. 
 * 				Reallocates a block of memory with a new size.
 *
 * @note 		If `ptr` is NULL, this function behaves 
 * 				like `malloc(size)`.
 * 				If `size` is 0, this function frees the memory 
 * 				pointed to by `ptr` and returns NULL.
 *
 * @param ptr   Pointer to the memory to be reallocated.
 * @param size  New size of the memory block.
 * @var new    	Pointer to the new memory block.
 * @return      Pointer to the reallocated memory, or NULL if the
 *              reallocation failed.
 */
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr)
		return (malloc(size));
	if (!size)
	{
		if (ptr)
		{
			free(ptr);
			ptr = NULL;
		}
		return (NULL);
	}
	new = malloc(size);
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, size);
	free(ptr);
	ptr = NULL;
	return (new);
}
