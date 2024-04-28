/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:54:40 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/14 17:03:56 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Function to put pointer to the standard output (1).
 * 
 * @param ptr 	The pointer to be written.
 * @return int 	The number of characters written.
 * 
 * @note		Uses recursion in if statement to convert the pointer to a 
 * 				hexadecimal string and `ft_putchar` to write the string to 
 * 				the standard output.
 * 				Uses [num % 16] as an index to get the hexadecimal character
 * 				from the string "0123456789abcdef". 
 * 				Uses [num / 16] to get the next digit of the hexadecimal number
 * 				by calling the function recursively.
 */
int	ft_putptr(void *ptr)
{
	unsigned long	num;
	int				res;

	num = (unsigned long)ptr;
	res = 0;
	if (num > 15)
		res += ft_putptr((void *)(num / 16));
	res += ft_putchar("0123456789abcdef"[num % 16]);
	return (res);
}
