/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:53:27 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/19 20:03:45 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Outputs the string `s` to the `fd`.
 * @param s 	The string to output.
 * @param fd 	The file descriptor.
 * 
 * @note 		Uses `write(2)`.
 * @compile 	gcc -Wextra -Werror -Wall ft_putstr_fd.c libft.h ft_strlen.c
 */
void	ft_putstr_fd(char const *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

// int	main(void)
// {
// 	char	*string;

// 	string = "Welcome to 42!";
// 	ft_putstr_fd(string, 1);
// 	return (0);
// }