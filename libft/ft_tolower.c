/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:03:40 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/06 19:15:56 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Converts an uppercase letter to lowercase
 * 				within the ASCII character set (A-Z).
 *
 * @param c 	The character to be converted.
 * @return 		The lowercase equivalent of the input character, 
 * 				if it is an uppercase letter.
 *         		Otherwise, it returns the input character unchanged.
 * @note 		The function takes an integer as an argument, not a character.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
