/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:35:46 by vkatason          #+#    #+#             */
/*   Updated: 2022/09/28 16:12:09 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function that checks if the given character
 * is an ASCII character (not extended).
 * 
 * @param c int value of the character to be checked.
 * @return int 1 if the character is an ASCII character, 
 * 0 otherwise.
 * NOTE: ASCII characters are in the range of 0 to 127.
 */
int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
