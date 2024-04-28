/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:17:31 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/16 20:17:58 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares the first n bytes of the memory blocks 
 * pointed to by `s1` and `s2`.
 *
 * @param s1 	Pointer to the first memory block.
 * @param s2 	Pointer to the second memory block.
 * @param n 	Number of bytes to compare.
 * @return 		0 if the memory blocks are equal, 
 * 				a positive value if the first differing 
 * 				byte in `s1` is greater than the corresponding 
 * 				byte in `s2`, or a negative value if the 
 * 				first differing byte in `s1` is less than 
 * 				the corresponding byte in `s2`.
 * @var d1 		Pointer to the first memory block.
 * @var d2 		Pointer to the second memory block.
 * @note 		The comparison is done using unsigned characters.
 * 				Therefore, the function can be used to compare
 * 				any memory block, including memory blocks that
 * 				contain non-character data. (e.g. to compare 
 * 				two memory blocks that contain integer values, 
 * 				it's necessary to make typecast `int *` before passing
 * 				them to the function.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (--n && *d1 == *d2)
	{
		d1++;
		d2++;
	}
	return ((int)(*d1 - *d2));
}
