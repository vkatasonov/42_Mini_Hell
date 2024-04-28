/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:20:19 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/14 17:04:45 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 			Helper function to `ft_printf` that handles 
 * 					the formatting and printing of different types of data.
 * 					It checks the type and performs the appropriate 
 * 					action to print the data.
 *
 * @param type 		The format specifier character indicating the type of data to be printed.
 * @param args 		The variable argument list containing the data to be printed.
 * @return 			The number of characters printed.
 * @note 			Supported format specifiers:
 * 					`c` - character
 * 					`s` - string
 * 					`p` - pointer
 * 					`d` - decimal integer
 * 					`i` - integer
 * 					`u` - unsigned integer
 *					`x` - hexadecimal integer (lowercase)
 *					`X` - hexadecimal integer (uppercase).
 */
int	ft_type(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'p')
	{
		ft_putstr("0x");
		return (ft_putptr(va_arg(args, void *)) + 2);
	}
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_putstr(
				ft_numbase(va_arg(args, unsigned int), "0123456789")));
	else if (type == '%')
		return (ft_putchar('%'));
	else if (type == 'x')
		return (ft_putstr(
				ft_numbase(va_arg(args, unsigned int), "0123456789abcdef")));
	else if (type == 'X')
		return (ft_putstr(
				ft_numbase(va_arg(args, unsigned int), "0123456789ABCDEF")));
	return (0);
}
