/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:52:22 by vkatason          #+#    #+#             */
/*   Updated: 2024/01/11 16:29:19 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 		Helper function for ft_split that counts
 * 				the number of words in a string based on 
 * 				a given delimiter.
 *
 * @param s 	The string to count the words in.
 * @param c 	The delimiter character.
 * 
 * @return 		The number of words in the string.
 */
static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

/**
 * @brief 		Helper function for ft_split that
 * 				calculates the size of a word in a string.
 * 				Function takes a string `s`, a delimiter `c`, 
 * 				and an index `i` as input. It counts the number
 * 				of characters in the word starting from index `i` 
 * 				until it reaches the delimiter `c` or the end of the string.
 *
 * @param s The string to calculate the word size from.
 * @param c The delimiter character.
 * @param i The starting index of the word.
 * 
 * @return The size of the word.
 */
static int	ft_wordsize(char const *s, char c, int i)

{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

/**
 * @brief 		Frees the memory allocated for an array of strings.
 * 				Helper function for ft_split.
 *
 * @param strs 	The array of strings to be freed.
 * @param j 	The number of strings in the array.
 */
static void	ft_free(char **strs, int j)
{
	while (j-- > 0)
		free(strs[j]);
	free(strs);
}

/** @brief 		Function that separates one string 
 *  			to various depending on separator
 * 
 *  @param s 	string of chars
 *  @param c 	any char separator
 * 
 *  @return 	char** array of separated string
 */
char	**ft_split(char const *s, char c)
{
	int		i;
	int		word;
	char	**strs;
	int		size;
	int		j;

	i = 0;
	j = -1;
	word = ft_wordcount(s, c);
	strs = (char **)malloc((word + 1) * sizeof(char *));
	if (!(strs))
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_wordsize(s, c, i);
		strs[j] = ft_substr(s, i, size);
		if (!strs[j])
			return (ft_free(strs, j), NULL);
		i += size;
	}
	strs[j] = 0;
	return (strs);
}
