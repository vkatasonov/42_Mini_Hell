/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:08:43 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/23 19:10:03 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 			Function to find first occurrence of a substring in a string.
 *
 * @param haystack 	The string to search in.
 * @param needle 	The substring to search for.
 * @var i 			An unsigned integer to iterate through the string `haystack`.
 * @var j 			An unsigned integer to iterate through the string `needle`.
 * @var k 			An unsigned integer to iterate through the string `needle`.
 * @var found 		An integer to store the first occurrence of the substring.
 * @return 			A pointer to the first occurrence of the substring in the string,
 * 					or NULL if the substring is not found.
 */
char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		found;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		k = 0;
		j = i;
		found = j;
		while (haystack[j] != '\0' && needle[k] != '\0')
		{
			if (haystack[j] != needle[k])
				found = -1;
			k++;
			j++;
		}
		if (found != -1)
			return ((char *)haystack + found);
		i++;
	}
	return (NULL);
}
