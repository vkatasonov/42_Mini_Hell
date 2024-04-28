/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:07:10 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/14 17:02:55 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief		Function converts an unsigned integer to a 
 * 				string in a given number base.
 *
 * @param num 	The unsigned integer to convert.
 * @param set 	The set of characters representing the number base
 * 				(e.g. 0 to 9, 0 to 1, 0 to F and so on).
 * 
 * @return 		A pointer to the number converted to the string.
 * 
 * @note 		The function uses a static buffer to store the result.
 * 				The buffer is 50 characters long, which should be enough
 * 				for any number base up to base 16.	
 */
char	*ft_numbase(unsigned int num, char *set)
{
	static char	buffer[50];
	char		*ptr;
	int			base;

	base = ft_strlen(set);
	ptr = &buffer[49];
	*ptr = '\0';
	*--ptr = set[num % base];
	num /= base;
	while (num != 0)
	{
		*--ptr = set[num % base];
		num /= base;
	}
	return (ptr);
}
