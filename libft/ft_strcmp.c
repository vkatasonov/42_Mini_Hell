/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:05:26 by vkatason          #+#    #+#             */
/*   Updated: 2024/02/23 15:00:56 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Function makes lexicographical comparison 
 * 				of two strings `s1` and `s2`.
 *
 * @param s1 	The first string to compare.
 * @param s2 	The second string to compare.
 * @return 		An integer greater than, equal to, or less than 0, 
 * 				depending on whether the first string is greater than, 
 * 				equal to, or less than the second string.
 * @example 	ft_strcmp("abc", "abc") returns 0
 * 				ft_strcmp("abc", "abd") returns -1
 * 				ft_strcmp("abd", "abc") returns 1
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
