/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:52:01 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/14 17:03:13 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief		Writes a single `char` to the 
 * 				standard output (1). Used in such
 * 				functions as `ft_printf` and `ft_putstr`.
 *
 * @param c 	The character to be written.
 * @return 		The number of characters written (always 1).
 */
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
