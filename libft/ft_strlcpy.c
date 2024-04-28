/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:53:21 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/11 16:30:16 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>                       /* to use printf() */

/**
 * @brief 			Function that copies a string from `src` to `dest`
 * 					with a specified size limit `dstsize`.
 *
 * @param dst 		The destination string where 
 * 					the copied string will be stored.
 * @param src 		The source string to be copied.
 * @param dstsize 	The maximum number of characters 
 * 					that can be copied to the destination string.
 * @return 			The total length of the source string.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if ((src[i] || dst[i]) && dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	const char	*str = "string to try to copy";
// 	size_t		sz;
// 	size_t		szmine;
// 	char		bf[10];

// 	bf[9] = '\0';
// 	printf("string: \"%s\"\n\n", str);
// 	printf("buffer before copy: \"%s\"\n", bf);
// 	sz = strlcpy(bf, str, sizeof(bf));
// 	szmine = ft_strlcpy(bf, str, sizeof(bf));
// 	if (sz >= sizeof(bf))
// 		printf("reduced: from %zu to %lu simbols !\n", sz, sizeof(bf) - 1);
// 	if (szmine >= sizeof(bf))
// 		printf("mine: from %zu to %lu simbols !\n", szmine, sizeof(bf) - 1);
// 	printf(":  \"%s\"\n", bf);
// 	return (0);
// }
