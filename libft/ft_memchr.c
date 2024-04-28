/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:05:50 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/16 20:08:49 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function searches for the first 
 * occurrence of a character in a given memory area.
 *
 * @param s 	Pointer to the memory area to be searched.
 * @param c     Character to be searched.
 * @param n     Number of bytes or symbols to be searched.
 *
 * @return      Pointer to the first occurrence of the 
 * 				character if found, or NULL if not found.
 * @note		If the character is not found within the
 * 				given memory area, the function returns `NULL`.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		if (*str++ == (unsigned char)c)
			return (str - 1);
	return (NULL);
}
