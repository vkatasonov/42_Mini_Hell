/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:32:17 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/06 19:15:04 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Converts an lowercase letter to uppercase
 * 				within the ASCII character set (a-z).
 *
 * @param c 	The character to be converted.
 * @return 		The uppercase equivalent of the input character, 
 * 				if it is an lowercase letter.
 *         		Otherwise, it returns the input character unchanged.
 * @note 		The function takes an integer as an argument, not a character.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
