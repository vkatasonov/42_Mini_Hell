/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:07:05 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/08 14:31:06 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/**
 * @brief		Function applies function `f` to each character 
 * 				of the string passed as an argument.
 * 
 * @param s 	The string to iterate.
 * @param f  	The function to apply to each character of s and its index.
 * @note		Each character is passed by address to `f` to be modified.
 * @example		ft_striteri("Hello.", my_func);
 * 				my_func(0, "H"), my_func(1, "o"), my_func(2, "r"), my_func(3, "r"), my_func(4, "o"), 
 * 				my_func(5, "r")
 * Result:		"Horror"
 * @compilation	gcc -Wall -Wextra -Werror ft_striteri.c -o striteri
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

/*
** void my_func(unsigned int i, char *str)
** {
** 	printf("My own function: index = %d and the string is %s\n", i, str);
** }
**
** int main()
** {
** 	char str[10] = "Hello.";
** 	printf("The result is %s\n", str);
** 	ft_striteri(str, my_func);
** 	printf("The result is %s\n", str);
** 	return 0;
** }
*/