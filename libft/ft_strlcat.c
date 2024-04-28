/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:06:48 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/08 18:54:21 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>                       /* to use printf() */

/**
 * @brief 			Function that concatenates the string pointed to by `src`
 * 					to the end of the string pointed to by `dst`. 
 * 					It will append at most `dstsize - strlen(dst) - 1`
 * 					characters from `src` and null-terminate `\\0` the result.
 *
 * @param dst 		The destination string.
 * @param src 		The source string.
 * @param dstsize 	The size of the destination buffer.
 * @return 			The total length of the string that 
 * 					would have been created if
 *         			`dstsize` had been sufficiently large without `\\0`.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	maxlen;

	maxlen = ft_strlen(dst) + ft_strlen(src);
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (*dst)
		dst++;
	i = 0;
	while ((i < dstsize - (maxlen - ft_strlen(src)) - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (maxlen);
}

// int	main(void)
// {
// 	const char	*source;
// 	char		*dest;
// 	size_t		size;

// 	source = "String";
// 	dest = "to copy";
// 	size = 0;
// 	printf("original: %lu \n", strlcat(dest, source, size));
// 	printf("mine: %lu \n", ft_strlcat(dest, source, size));
// 	return (0);
// }