/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:47:17 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/19 14:08:13 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stddef.h>	// for size_t
// #include <stdio.h> 	// for printf
// #include <string.h>	// for strrchr

/**
 * @brief 			Searches for the last occurrence 
 * 					of a character `c` in a string `s`.
 *
 * @param s 		The string to search in.
 * @param c 		The character to search for.
 * @var count 		An unsigned integer to count the characters in the string.
 * @var position 	A pointer to the string `s` as soon as `s` is cast to a char pointer.
 * @var last 		An integer to store the last occurrence of the character `c`.
 * @return 			A pointer to the last occurrence 
 * 					`c` of the character in the string `s`,
 *         			or NULL if `c` is not found.
 * @note 			The `\\0` is considered part of the string.
 * @compilation 	gcc -Wall -Wextra -Werror ft_strrchr.c ft_strlen.c libft.h
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	count;
	char	*position;
	int		last;

	count = 0;
	position = (char *)s;
	last = -1;
	while (count <= ft_strlen(position))
	{
		if (position[count] == (char)c)
			last = count;
		count++;
	}
	if (last != -1)
	{
		while (last > 0)
		{
			s++;
			last--;
		}
		return ((char *)s);
	}
	else
		return (0);
}

// int	main(void)
// {
// 	const char	*str;
// 	int			position;

// 	str = s;
// 	position = '\0';
// 	printf("string we have: %s\n", str);
// 	printf("result: :%s:\n", ft_strrchr(str, position));
// 	printf("_result: :%s:\n", strrchr(str, position));
// 	return (0);
// }
