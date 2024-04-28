/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:02:02 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/16 20:03:39 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 			Compares lexicographically (case-sensitive) 
 * 					the string pointed to by `s1` 
 * 					to the string pointed to by `s2`,
 * 					up to `n` characters and stops if 
 * 					a difference is found or at the end of either
 * 					string is reached.
 *
 * @param s1 		The first string to be compared.
 * @param s2 		The second string to be compared.
 * @param n 		The maximum number of characters to compare.
 * @return 			An integer greater than, equal to, or less than 0, 
 * 					depending on whether the string pointed to by `s1` 
 * 					is greater than, equal to, or less than 
 * 					the string pointed to by `s2`:
 * 					"abc" vs "abc" = 0
 * 					"abc" vs "abcd" = -1
 * 					"abcd" vs "abc" = 1
 * @note 			Doesn't check for NULL pointers.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
		if (*s1++ != *s2++)
			return ((unsigned char)*--s1 - (unsigned char)*--s2);
	return (0);
}
