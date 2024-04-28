/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:30:18 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/17 13:55:42 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function sets the `len` bytes of the memory
 * pointed to by `b` to the specified value `c`.
 *
 * @param b 	Pointer to the chunk to be filled.
 * @param c 	Value to be set. The value is passed as an int,
 * 				but the function fills the memory area
 * 				with an unsigned char.
 * @param len 	Number of bytes to be set to the value.
 *
 * @return 		Pointer to the changed memory area `b`.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
