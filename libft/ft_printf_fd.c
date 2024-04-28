/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:47:19 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/22 17:48:36 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Function prints string to a specified file descriptor.
 * 				The function supports the following format specifiers:
 * 				%c: character,
 * 				%s: string,
 * 				%p: pointer,
 * 				%d: decimal integer,
 * 				%i: integer,
 * 				%u: unsigned integer,
 * 				%x: hexadecimal integer.
 * 				One of the principal usage of this function is to write error messages
 * 				to the standard error output.
 * 				For example, ft_printf_fd(2, "Error: %s\n", "Invalid argument");
 * 
 * @param fd 	The file descriptor which the output will be written to.
 * @param sign 	The string we want to print with format specifiers.
 * @param ... 	The variable number of arguments to be formatted and printed.
 * 
 * @return 		The total number of characters written to the file descriptor.
 */
int	ft_printf_fd(int fd, const char *sign, ...)
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
			len += write(fd, &sign[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
