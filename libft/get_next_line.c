/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:56:17 by vkatason          #+#    #+#             */
/*   Updated: 2023/08/17 17:07:58 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 			Helper function for `get_next_line` that copies a string 
 * 					from source to destination with a specified maximum size.
 *
			* @param dst 		The destination string where the copied string will be stored.
 * @param src 		The source string to be copied.
 * @param dstsize 	The maximum size of the destination string.
 * @return 			The length of the source string.
 * 
 * @note 			Diffence between `ft_strlcpy` and `gnl_strlcpy`:
 * 					`gnl_strlcpy` checks if `dst` or `src` is `NULL` 
 * 					at the beginning and returns `0` if either is
 * 					NULL. `ft_strlcpy` does not check for `NULL`,
 * 					`gnl_strlcpy` calculates the length of `src` 
 * 					at the beginning and stores it in `j`, 
 * 					which it returns at the end,
 * 					`gnl_strlcpy` checks if `dstsize` is not `0` 
 * 					before starting the copying loop
 */
size_t	gnl_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	j = gnl_strlen(src);
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

/**
 * @brief 			Helper function for `get_next_line` 
 * 					that returns a substring of a given string
 * 					(see `ft_substr` for more details).
 *
 * @param s 		The string from which to extract the substring.
 * @param start 	The starting index of the substring.
 * @param len 		The length of the substring.
 * @return 			The extracted substring, or NULL if the 
 * 					input string is empty or if memory allocation fails.
 */
char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*str;

	if (gnl_strlen(s) == 0)
		return (NULL);
	if (start > gnl_strlen(s))
	{
		len = 0;
		start = 0;
	}
	if (start + len > gnl_strlen(s) || len == 0)
		len = gnl_strlen(s) - start;
	if (len > gnl_strlen(s))
		len = gnl_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	gnl_strlcpy(str, (s + start), len + 1);
	return (str);
}

/**
 * @brief 				Helper function for `get_next_line` that 
 * 						reads from a file descriptor and saves the read content.
 * 
 * @param block 		The previously read content.
 * @param fd 			The file descriptor to read from.
 * @param n 			A pointer to an integer to store the number of bytes read.
 * @return 				The updated content after reading and saving.
 * @var buf 			A buffer to store the read content.
 * @var temp 			The updated content after reading and saving.
 * 
 * @note 				The function allocates memory for the `temp`
 * 						and the caller is responsible for freeing it.
 */
char	*gnl_read_and_save(char *block, int fd, int *n)
{
	char	*buf;
	char	*temp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (block);
	*n = read(fd, buf, BUFFER_SIZE);
	if (*n == -1)
		temp = NULL;
	else if (*n > 0)
	{
		buf[*n] = '\0';
		temp = gnl_strjoin(block, buf);
	}
	else
	{
		temp = gnl_strjoin(block, "");
	}
	free (buf);
	return (temp);
}

/**
 * @brief 				Helper function for `get_next_line` 
 * 						that a substring of length `len` from 
 * 						the beginning of the memory block pointed to by `block`
 * 						and then frees the memory block. 
 * 						If `null_block` is non-zero, it also sets `block` to NULL.
 *
 * @param block 		A pointer to the pointer to the memory block. 
 * 						This should point to a valid memory block.
 * @param len 			The length of the substring to extract. 
 * 						This should be less than or equal to the length of the memory block.
 * @param null_block 	If non-zero, `block` will be set to NULL.
 * @return 				A pointer to the extracted substring. 
 *
 * @note				Returns a newly allocated string that should be freed by the caller.
 */
char	*gnl_get_and_free(char **block, int len, int null_block)
{
	char	*line;

	line = gnl_substr(*block, 0, len);
	free(*block);
	if (null_block)
		*block = NULL;
	return (line);
}

/**
 * @brief 				Reads a line from a file descriptor and returns it as a string.
 * 						The function uses a static variable to keep track 
 * 						of the remaining data from previous calls.
 *
 * @param fd 			The file descriptor to read from.
 * @return 				A pointer to the line read from the file descriptor, 
 * 						or NULL if an error occurred or the end of file was reached.
 */
char	*get_next_line(int fd)
{
	static char	*block;
	int			line_len;
	int			n;
	char		*old_block;

	n = 0;
	while (fd >= 0 && BUFFER_SIZE > 0 && n >= 0)
	{
		old_block = block;
		if (gnl_strchr(block, '\n'))
		{
			line_len = gnl_strlen_line(block) + 1;
			block = gnl_substr(old_block, line_len, 0);
			return (gnl_get_and_free(&old_block, line_len, 0));
		}
		else
		{
			block = gnl_read_and_save(old_block, fd, &n);
			free(old_block);
			if (n == 0)
				return (gnl_get_and_free(&block, 0, 1));
		}
	}
	return (NULL);
}
