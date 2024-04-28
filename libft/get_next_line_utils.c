/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:53:54 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/14 15:55:05 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 			Helper function for `get_next_line` 
 * 					that calculates the size of a word in a string.
 * 	
 * @param s 		The string to calculate the length of.
 * @return 			The length of the string.
 * @note 			Instead of `ft_strlen`, this function checks 
 * 					if the string is NULL and returns 0.
 */
size_t	gnl_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * @brief 			Helper function for `get_next_line` that 
 * 					calculates the length of a line in a string
 * 					up to the first newline character `\\n`.
 *	
 * @param s 		The string to calculate the length of.
 * @return 			The length of the line in the string.
 * @note 			Instead of `ft_strlen`, this function checks
 * 					if the string is NULL and returns 0.
 * 					Instead of `ft_gnl_strlen`, this function 
 * 					stops at the first newline character.
 */
size_t	gnl_strlen_line(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\n')
	{
		len++;
	}
	return (len);
}

/**
 * @brief 			Helper function for `get_next_line` 
 * 					that concatenates the string `src` 
 * 					to the end of the string `dst` with a `\\0`.
 *
 * @param dst 		The destination string.
 * @param src 		The source string to be appended.
 * @param dstsize 	The size of the destination buffer.
 * @return 			The total length of the resulting string 
 * 					after concatenation or the length of `src` plus `dstsize`.
 * 					If `dst` or `src` is NULL, the function returns 0.
 * 					If `dstsize` is 0 or less than the length of `dst`, 
 * 					the function returns the length of `src` plus `dstsize`.
 * @note 			The difference between `ft_strlcat` and `gnl_strlcat` is that
 * 					`gnl_strlcat` checks if dst or src is NULL and returns 0 in this case.
 * 					`gnl_strlcat` also checks if dstsize is 0 or less than the length of dst
 * 					and returns the length of src plus dstsize in this case.
 * 					`gnl_strlcat` also uses `gnl_strlen` instead of `ft_strlen`.
 * 					`gnl_strlcat` uses the variable `j` to keep track of the 
 * 					current position in the `dst` string while `ft_strlcat` 
 * 					increments the `dst` pointer itself to reach the end of the `dst` string.
 */
size_t	gnl_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	dlen = gnl_strlen(dst);
	slen = gnl_strlen(src);
	j = dlen;
	if (dstsize == 0 || dstsize <= dlen)
		return (slen + dstsize);
	while (src[i] != '\0' && i < dstsize - dlen - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}

/**
 * @brief 			Refactored version of `ft_strjoin` 
 * 					to use as a helper function for `get_next_line`.
 * 
 * @param s1 		The first string to be concatenated.
 * @param s2 		The second string to be concatenated.
 * @return 			The concatenated string, or NULL if memory allocation fails.
 * 
 * @note 			Difference between `ft_strjoin` and `gnl_strjoin`:
 * 					`gnl_strjoin` treats NULL inputs as empty strings. 
 * 					If s1 or s2 is NULL, it sets them to "" before proceeding.
 * 					`gnl_strjoin` uses gnl_strlcpy and gnl_strlcat, which handle 
 * 					the indexing of the current string internally.
 */
char	*gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len = gnl_strlen(s1) + gnl_strlen(s2);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	gnl_strlcpy(str, s1, len + 1);
	gnl_strlcat(str, s2, len + 1);
	return (str);
}

/**
 * @brief 			Refactored version of `ft_strchr` function
 * 					to use as a helper function for `get_next_line`.
 * 					Searches for the first occurrence of a character
 * 					in a string.
 *
 * @param s 		The string to search in.
 * @param c 		The character to search for.
 * @return 			A pointer to the first occurrence of the character in the string,
 *         			or NULL if the character is not found.
 * 
 * @note 			Difference between `ft_strchr` and `gnl_strchr`:
 * 					`gnl_strchr` checks if s is NULL at the beginning 
 * 					and returns NULL if it is, 
 * 					`gnl_strchr` casts `c` to unsigned char 
 * 					before comparing it to `s[i]`,
 * 					`gnl_strchr` has an additional check after 
 * 					the loop where it checks if `c` is the same as `s[i]` 
 * 					(which would be `\\0` at this point).
 */
char	*gnl_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == s[i])
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
