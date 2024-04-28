/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:21:01 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/20 17:42:58 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function that allocates memory 
 * for an array of elements and initializes 
 * them to zero.
 *
 * @param count The number of elements 
 * to allocate memory for.
 * @param size The size of each element.
 * @return A pointer to the allocated memory, 
 * or NULL if the allocation fails.
 * @var memory The pointer to the allocated memory.
 * @var i The index of the current element.
 * @note size_t used to represent the size of objects.
 * It's lagre enough to represent the size of any object
 * even depending on the system.
 */
void	*ft_calloc(size_t count, size_t size)
{
	char	*memory;
	size_t	i;

	i = 0;
	memory = malloc(count * size);
	if (memory == NULL)
		return (NULL);
	while (i < count * size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
