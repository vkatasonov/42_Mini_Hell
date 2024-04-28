/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_extended.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:11:04 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/12 19:00:01 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function checks if a character is an extended 
 * ASCII character. Used in `minishell` (e.g. to check if 
 * a character is a valid character for a variable name 
 * and in tokens parsing).
 *
 * @param c The character to check.
 * @return 1 if the character is an extended 
 * ASCII character, 0 otherwise.
 * @note The function checks if the character is in the range of 32 to 255,
 * and takes as a parameter int instead of char. 
 */
int	ft_is_extended(int c)
{
	return ((c >= 32 && c <= 255) && c != 127 && c != 129 && c != 141
		&& c != 143 && c != 144 && c != 157 && c != 160
		&& c != 173);
}
