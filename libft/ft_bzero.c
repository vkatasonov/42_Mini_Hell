/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:47:58 by vkatason          #+#    #+#             */
/*   Updated: 2022/10/16 21:23:24 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <unistd.h>

/**
 * @brief Function sets the first `n` bytes 
 * of the memory pointed to by `s` to zero.
 *
 * @param s Pointer to the memory (string) to be set to 0.
 * @param n Number of bytes to be set to 0.
 */
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		*str++ = '\0';
}

// int	main(void) {
//   const char	a[] = "hola";
//   int longitud = ft_strlen(a);
//   int i = 0;
//   ft_bzero((void *)a,2);
//   while(i < longitud)
// 	{
// 		write(1, &a[i], 1);
// 		i++;
// 	}
//   printf("%c", *a);  
// }
//   //a = /0/0la/0
