/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:30:29 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/19 01:34:59 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Copies a string from `src` to `dest`, 
 * 				up to a specified length `len`.
 *
 * @param dest 	The destination string where 
 * 				the copied string will be stored.
 * @param src 	The source string to be copied.
 * @param len 	The maximum number of characters to be copied.
 * @return 		`dest` - The pointer to the destination string.
 * @example 	For example, if the source string is "Hello, World!"
 * 				and the length is 5, the destination string will be "Hello".
 * @note 		The function assumes that the destination string
 * 				is large enough to accommodate the copied string.
 */
char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != 0)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < len)
		dest[i++] = '\0';
	return (dest);
}
