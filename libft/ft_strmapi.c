/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:44:19 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/19 18:17:25 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

/**
 * @brief 		Function that iterates through the `s` string 
 * 				applying the function `f` to each character. 
 * 				Changed string is saved as a new one. 
 * 				The function `f` takes an index and a character 
 * 				as parameters and returns a new character.
 *
 * @param s 	The string to change.
 * @param f 	The function to apply to each character.
 * @return 		The new string created by applying 
 * 				the function `f` to each character of `s`.
 *         		Returns NULL if `s` or `f` is NULL, 
 * 				or if memory allocation fails.
 * @compilation	gcc -Wall -Wextra -Werror ft_strmapi.c ft_strlen.c libft.h
 * @note		Remember to include stdio.h to use printf() function 
 * 				and stdlib.h for malloc() function.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*out;
	size_t	i;

	if (!s || !f)
		return (NULL);
	out = malloc(ft_strlen(s) + 1);
	if (!out)
		return (NULL);
	i = -1;
	while (s[++i])
		out[i] = f(i, (char)s[i]);
	out[i] = '\0';
	return (out);
}

// char	my_func(unsigned int i, char str)
// {
// 	printf("My inner function: index = %d and %c\n", i, str);
// 	return (str - 32);
// }

// int	main(void)
// {
// 	char	*str;
// 	char	*result;

// 	str = "hello.";
// 	printf("The result is %s\n", str);
// 	result = ft_strmapi(str, my_func);
// 	printf("The result is %s\n", result);
// 	return (0);
// }
