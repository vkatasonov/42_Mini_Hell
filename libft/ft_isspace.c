/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:59:55 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/03 21:19:48 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Function that checks if the char is space or not
 * 
 * @param c any char in ASCII table
 * @return true if the char is space and false if it's not
 */
bool	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
