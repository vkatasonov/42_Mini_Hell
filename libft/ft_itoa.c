/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:27:55 by vkatason          #+#    #+#             */
/*   Updated: 2023/10/22 15:46:48 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

/**
 * @brief Calculates the length of a number when converted to a string.
 * Counts the length of the number that we want to pass to size_t of
 * the number that we want to convert to string. Used in `ft_itoa`.
 *
 * @param num The number to calculate the length of.
 * @return The length of the number as a string.
 * @var len The length of the number as a string.
 */
size_t	ft_lennum(long int num)
{
	size_t	len;

	len = 0;
	if (num <= 0)
		len++;
	while (num)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

/**
 * @brief Function that converts int to a string.
 *
 * @param n The integer to be converted.
 * @return A string representation of the integer or 
 * NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	size_t		len;
	char		*str;
	long int	num;

	len = ft_lennum(n);
	num = n;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	if (num == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (num)
	{
		str[len] = num % 10 + '0';
		len--;
		num = num / 10;
	}
	return (str);
}

/*
	Implementation of the function ft_itoa:
	1. Declaration of variables
	2. Reservation of memory with len+1 to be able to write '\0' character
	3. Taking care of the negative numbers, if so we have to convert 
	negative number to the positive one
	4. Putting the ultimate position to '\0'
	5. Changing int to char 
*/

/* int	main(void)
{
	printf("Result of the convertion |%s| ", ft_itoa(2147483647));
}
 */