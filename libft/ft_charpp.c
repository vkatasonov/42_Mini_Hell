/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charpp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:10:04 by vkatason          #+#    #+#             */
/*   Updated: 2023/09/24 12:38:16 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function frees the memory allocated 
 * for a null-terminated array of strings (double array
 * or martrix).
 * First it frees the memory allocated for each string 
 * and then the array itself. The array must be terminated 
 * with a NULL pointer.
 *
 * @param charpp The double pointer to the array of strings.
 * @var i The index of the current string in the array.
 */
void	ft_charpp_free(char **charpp)
{
	int	i;

	i = 0;
	while (charpp && charpp[i])
	{
		free(charpp[i]);
		charpp[i] = NULL;
		i++;
	}
	if (charpp)
	{
		free(charpp);
		charpp = NULL;
	}
}
