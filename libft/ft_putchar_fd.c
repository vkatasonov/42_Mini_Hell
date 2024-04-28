/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:23:23 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/19 19:53:56 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Outputs the char `c` to the file descriptor `fd`. 
 * 
 * @param c 	The character to output.
 * @param fd 	The file descriptor.
 * 
 * @note 		Uses libc function write(2)
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	char	letter;

// 	letter = 'A';
// 	ft_putchar_fd(letter, 2);
// 	return (0);
// }
