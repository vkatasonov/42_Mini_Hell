/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:35:46 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/03 22:36:47 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Function concatenates a specified 
 * 				number of characters from a source 
 * 				string `s2` to a destination string `s1`.
 *
 * @param s1 	The destination string.
 * @param s2 	The source string.
 * @param n 	The maximum number of characters to concatenate.
 * @return 		The pointer to the destination string after concatenation with a `\\0`.
 * @var i 		An index to iterate through the destination string.
 * @var j 		An index to iterate through the source string.
 * @note		The function assumes that the destination string
 * 				is large enough to accommodate the concatenated string.
 * 				Doesn't check for NULL pointers.
 */
char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0' && j < n)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}
