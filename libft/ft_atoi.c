/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:49:33 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/18 19:28:18 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function that converts the initial 
 * portion of the string pointed to by `str`
 * to its equivalent integer representation. 
 * It skips leading white space characters 
 * and then interprets the optional sign 
 * and numeric digits.
 * 42 implementation of the standard `atoi` function.
 *
 * @param str The string to be converted.
 * @return The converted integer value.
 * @var i The index of the current character in the string.
 * @var res The converted integer value.
 * @var sign The sign of the integer value.
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

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
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
