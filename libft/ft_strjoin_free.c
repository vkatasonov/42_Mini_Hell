/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:01:57 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/30 21:03:41 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 			Function that concatenates two strings 
 * 					in one and frees the original strings.
 *
 * @param s1 		The first string to be concatenated.
 * @param s2 		The second string to be concatenated.
 * @var joined 		The new string created by concatenating `s1` and `s2`.
 * @return 			A pointer to the newly allocated string, 
 * 					or NULL if allocation fails.
 */
char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	joined = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (joined);
}
