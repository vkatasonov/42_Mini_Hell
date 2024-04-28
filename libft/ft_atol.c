/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:51:15 by vkatason          #+#    #+#             */
/*   Updated: 2023/10/22 15:45:46 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function that converts the initial 
 * portion of the string pointed to by `str`
 * to its equivalent long representation. 
 * It skips leading white space characters 
 * and then interprets the optional sign 
 * and numeric digits.
 * 42 implementation of the standard `atol` function.
 *
 * @param str The string to be converted.
 * @return The converted integer value.
 * @var i The index of the current character in the string.
 * @var res The converted integer value.
 * @var sign The sign of the integer value.
 */
long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * sign);
}
