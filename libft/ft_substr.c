/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:00:50 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/11 16:31:15 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Returns a `substr` of the given string 's',
 * 				starting at the index `start`
 * 				and with a length of `len`.
 *
 * @param s 	The string from which to extract the substring.
 * @param start The starting index of the substring.
 * @param len 	The length of the substring.
 * @var substr 	The substring to be returned.
 * @var i 		The counter to iterate through the string. 
 * @return 		The substring, or NULL if allocation fails or 's' is NULL.
 * @example		ft_substr("hello", 1, 3) returns "ell".
 * @warning		The function allocates memory for the new string
 * 				and the caller is responsible for freeing it.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[i] && i < len)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
