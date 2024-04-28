/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:34:31 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/19 14:04:59 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Function trims consecutive characters 
 * 				specified in `set` from the beginning 
 * 				and end of a string `s1`, respectively.
 * 
 * @param s1 	The string to be trimmed.
 * @param set 	The set of characters to be removed.
 * @return 		A new dynamically allocated string 
 * 				with the characters removed,
 * 				or NULL if memory allocation fails.
 * @example		ft_strtrim("  hello  ", " ") returns "hello".
 * @note		The function allocates memory for the new string
 * 				and the caller is responsible for freeing it.
 */
char	*ft_strtrim(const char *s1, const char *set)
{
	char	*res;
	size_t	len;

	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len - 1]))
		len--;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	return (res);
}
