/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:50:51 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/01 16:09:17 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
// #include <string.h>
// #include <stdio.h>

/**
 * @brief 		Function that duplicates string `s1` 
 * 				by allocating memory for a new string
 * 				and copying the contents of `s1` into it. 
 * 				The duplicated string contains `\\0`.
 *
 * @param s1 	The string to be duplicated.
 * @return 		A pointer to the duplicated string, 
 * 				or NULL if the memory allocation fails.
 * @note 		Memory for the new string is obtained
 * 				with malloc(3), and should be freed with free(3).
 */
char	*ft_strdup(char *s1)
{
	char	*new;
	int		i;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!new)
		return (NULL);
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}

// int	main(int ac, char *av[])
// {
// 	char	*minefunction;
// 	char	*original;

// 	if (ac == 2)
// 	{
// 		minefunction = ft_strdup(av[1]);
// 		original = strdup(av[1]);
// 		printf(":%s:\n:%s:\n", minefunction, original);
// 	}
// 	return (0);
// }