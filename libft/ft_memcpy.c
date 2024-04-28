/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:41:37 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/29 00:01:10 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 	Copies an `n` size block of memory from a `src` address 
 * 			to a `dest` address.
 *
 * @param dst 	The destination address where data will be copied to.
 * @param src 	The source address from where data will be copied.
 * @param n 	The number of bytes to be copied.
 * @return 		A pointer to the destination address.
 * @note 		If `dst` and `src` are `NULL`, the function returns `dst`.
 * @note 		The behavior is undefined if the source and destination overlap.
 * @var d 		Pointer to the destination address.
 * @var s 		Pointer to the source address.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst - n - 1);
}

// int	main(void)
// {
// 	char	source[] = "Too many stuff to copy";
// 	char	destination [100];

// 	ft_memcpy(destination, source, ft_strlen(source)+1);
// 	printf("Copied string is %s", destination);

// 	int	nums[] = {10, 20, 30, 40, 50};
// 	int	n = sizeof(nums)/sizeof(nums[0]);
// 	int	numdest[n];
// 	int	i;

// 	ft_memcpy(numdest, nums, sizeof(nums));
// 	printf("\nCopied array is ");
// 	i = 0;
// 	while (i < n)
// 	{
// 		printf ("%d ", numdest[i]);
// 		i++;
// 	}
// 	return (0);
// }

// Result:
// Copied string is Too many stuff to copy
// Copied array is 10 20 30 40 50
