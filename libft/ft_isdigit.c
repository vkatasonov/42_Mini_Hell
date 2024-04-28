/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:11:16 by vkatason          #+#    #+#             */
/*   Updated: 2023/11/09 16:36:58 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief returns 1 if the number is digit from 1 to 9
 * and 0 if it's not
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
