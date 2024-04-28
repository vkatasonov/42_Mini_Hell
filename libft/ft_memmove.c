/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:01:46 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/16 20:00:25 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <string.h>

/**
 * @brief 	Copies a `n` size block of memory from 
 * 			a `src` address to a `dest` address.
 *
 * @param dst 	The destination address where the memory will be copied to.
 * @param src 	The source address from where the memory will be copied.
 * @param len 	The number of bytes to be copied.
 * 
 * @return 		A pointer to the destination address.
 * @var 		d Pointer to the destination address.
 * @var 		s Pointer to the source address.
 * @note 		If `dst` and `src` are `NULL`, the function returns `dst`.
 * @note 		Memmove handles overlapping memory blocks correctly 
 * 				by copying the memory block to a temporary buffer
 * 				before copying it to the destination address.	
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	if (src < dst)
		while (len--)
			d[len] = s[len];
	else
		while (len--)
			*d++ = *s++;
	return (dst);
}

// Test
// int	main(void)
// {
// 	char	source [100] = "Things to move";
// 	char	comparison [100] = "Things to move";

// 	ft_memmove(source + 100, source, strlen(source)+1);
// 	printf(":%s:\n", source);
// 	memmove(comparison + 100, comparison, strlen(comparison)+1);
// 	printf(":%s:\n", comparison);
// 	return (0);
// }
