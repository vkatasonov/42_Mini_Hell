/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdcounter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:15:33 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/18 18:56:49 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Function that counts the number 
 * 				of words in a string `str` based on 
 * 				a given delimiter `c`.
 *
 * @param str 	The string to count the words in.
 * @param c 	The delimiter character.
 * @return 		The number of words in the string.
 * @var i 		An index to iterate through the string.
 * @var words 	An integer to store the number of words.
 */
int	ft_wdcounter(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] != c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] == c && str[i] != '\0')
			i++;
	}
	return (words);
}
