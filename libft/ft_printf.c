/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:08:14 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/14 17:02:26 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief		Function is a simpified implementation of the printf function
 * 				from the standard C library. The function supports the following
 * 				format specifiers:
 * 				%c: character,
 * 				%s: string,
 * 				%p: pointer,
 * 				%d: decimal integer,
 * 				%i: integer,
 * 				%u: unsigned integer,
 * 				%x: hexadecimal integer.
 * 				For example, ft_printf("Hello, %s!\n", "world");
 * 
 * @param sign  The string we want to print with format specifiers.
 * @param ... 	The variable number of arguments to be formatted and printed.
 * 
 * @return int  The total number of characters written to the standard output.
 */
int	ft_printf(const char *sign, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, sign);
	i = 0;
	len = 0;
	while (sign[i])
	{
		if (sign[i] == '%')
		{
			len += ft_type(sign[i + 1], args);
			i++;
		}
		else
			len += write(1, &sign[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
