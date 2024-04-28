/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:33:55 by vkatason          #+#    #+#             */
/*   Updated: 2023/09/24 14:19:05 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Function converts a hexadecimal (16-digits)
 * string to an integer.
 *
 * @param hex The hexadecimal string to convert.
 * @return The integer representation of the hexadecimal string.
 * Returns -1 if the input is not a valid hexadecimal string.
 * @var result The integer representation of the hexadecimal string.
 * @var val The value of the current hexadecimal digit.
 * @warning The function is case-insensitive and doesn't handle overflow. 
 * @note Function uses bitwise shift operation `result << 4` that is 
 * equivalent to multiplying result by 2 to the power of 4 (or 16).
 */
int	hex_to_int(char *hex)
{
	int	result;
	int	val;

	result = 0;
	while (*hex)
	{
		if ('0' <= *hex && *hex <= '9')
			val = *hex - '0';
		else if ('a' <= *hex && *hex <= 'f')
			val = *hex - 'a' + 10;
		else if ('A' <= *hex && *hex <= 'F')
			val = *hex - 'A' + 10;
		else
			return (-1);
		result = (result << 4) + val;
		hex++;
	}
	return (result);
}
