/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:55:28 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/12 18:17:47 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

/**
 * @brief Checks if the given character is a printable character
 * (including space) in the ASCII table (not extended ASCII).
 * 
 * @param c int value of the character to be checked.
 * @return int 1 if the character is a printable character, 0 otherwise.
 * NOTE: Check only range of 32 to 126 and receives int.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
