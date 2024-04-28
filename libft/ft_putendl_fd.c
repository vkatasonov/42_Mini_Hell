/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:10:47 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/19 20:16:05 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Function to put `\\n` after the string `s` to the file descriptor `fd`.
 *
 * @param s 	The string to be written.
 * @param fd 	The file descriptor to write to.
 */
void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/* int	main(void)
{
	char	*str;

	str = "Welcome to 42!";
	ft_putendl_fd(str, 1);
	return (0);
} */

// compile with gcc -Wextra -Wall -Werror ft_putchar_fd.c 
// ft_putendl_fd.c ft_putstr_fd.c ft_strlen.c