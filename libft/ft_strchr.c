/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:49:24 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/06 16:46:28 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <string.h>
// #include <stddef.h>

/**
 * @brief 		Function locates the first occurrence of the character `c`
 * 				(converted to a char) in the string `s`.  
 * @param s 	The string to search in.
 * @param c 	The character to be located.
 * @return 		A pointer to the located character, 
 * 				or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	count;
	char	*chain;

	count = 0;
	chain = (char *)s;
	while (count <= ft_strlen(chain))
	{
		if (chain[count] == (char)c)
			return (&chain[count]);
		count++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*str;
// 	int			position;

// 	str = "cervexa a litro";
// 	position = 'x';
// 	printf("string we have: %s\n", str);
// 	printf("result: %s\n", ft_strchr(str, position));
// 	printf("_result: %s\n", strchr(str, position));
// 	return (0);
// }
