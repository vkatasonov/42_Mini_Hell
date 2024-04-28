/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:32:04 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/25 23:47:10 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief			Function to extract tokens from strings.
 * 					A token is a sequence of characters 
 * 					within a string `str` that is bound 
 * 					by a delimiter `delim`.
 * 
 * @param str 		The string to extract tokens from.
 * @param delim 	The delimiter string.
 * @return char* 	A pointer to the next token found in the string.
 * @note 			The function maintains a static variable
 * 					to keep track of the current position in the string.
 * @example 		For example, if the string is "Hello, World!"
 * 					and the delimiter is ",", the first token will be "Hello".
 */
char	*ft_strtok(char *str, const char *delim)
{
	static char	*stock;
	char		*ptr;

	if (str != NULL)
		stock = str;
	if (stock == NULL)
		return (NULL);
	while (ft_strchr(delim, *stock))
		stock++;
	if (*stock == '\0')
	{
		stock = NULL;
		return (NULL);
	}
	ptr = stock;
	while (*stock != '\0' && !ft_strchr(delim, *stock))
		stock++;
	if (*stock != '\0')
	{
		*stock = '\0';
		stock++;
	}
	else
		stock = NULL;
	return (ptr);
}
