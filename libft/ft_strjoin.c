/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:23:41 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/26 18:37:16 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

/**
 * @brief 			Function that concatenates two strings 
 * 					`s1` and `s2` into one. The resulting 
 * 					string `dest` is allocated dynamically 
 * 					using `malloc`, and it is terminated 
 * 					with a null `\\0` character.
 *
 * @param s1 		The first string to be concatenated.
 * @param s2 		The second string to be concatenated.
 * @var dest 		The new string created by concatenating `s1` and `s2`.
 * @var i 			An index to iterate over the strings.
 * @var len1 		The length of the first string `s1`.
 * @var len2 		The length of the second string `s2`.
 * @return 			The concatenated string, or NULL if either 
 * 					`s1` or `s2` is NULL or if memory allocation fails.
 * @note 			The resulting string must be freed with `free(3)`.
 * 					Original strings are not modified and not freed.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	len1;
	size_t	len2;
	char	*dest;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		dest = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
		if (dest == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			dest[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			dest[len1] = s2[i];
			len1++;
		}
		dest[len1] = '\0';
		return (dest);
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;
// 	char	*str3;

// 	str1 = "";
// 	str2 = "";
// 	str3 = "Jaime";
// 	printf("%s\n", ft_strjoin(str1, str2));
// 	printf("%s\n", ft_strjoin(str1, str3));
// 	return (0);
// }