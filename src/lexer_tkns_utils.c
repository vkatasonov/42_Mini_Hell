/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:21:08 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/11 16:18:52 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 			The function is to manage 
 * 					the order of tokens in lexer. 
 * 					It uses a static integer order 
 * 					to keep track of the current 
 * 					order number across multiple 
 * 					calls to the function.
 * 
 * @param reset 	If reset is 1, the order
 * 					will be reset to 0. If reset is 0, the
 * 					order will be incremented by 1.
 * @return 			int The order number.
 */
int	ft_reset_tkn_order(int reset)
{
	static int	order = 0;

	if (reset)
		order = 0;
	else
		order++;
	return (order);
}

/**
 * @brief 			Function to count the same symbols
 * 					in the input string with the given symbol.
 * 
 * @param lexer 	lexer object.
 * @param symbol 	symbols which we want to count.
 * @return int 		number of repeated symbols.
 */
int	ft_count_the_same(t_lexer *lexer, char symbol)
{
	int		count;
	int		i;

	count = 0;
	i = lexer->i;
	while (lexer->input[i] == symbol)
	{
		count++;
		i++;
	}
	return (count);
}

/**
 * @brief 			Function to repeat the given character
 * 					the given number of times and return the string.
 * 					Used in ft_lexer_get_string to return as a TKN_ERROR
 * 					combinations like >>>, <<<, ||| etc.
 * 
 * @param c 		The character to be repeated.
 * @param count 	The number of times to repeat the character.
 * @return char* 	The string with the repeated character.
 */
char	*ft_str_repeat(char c, int count)
{
	char	*str;
	int		i;

	str = malloc(count + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		str[i] = c;
		i++;
	}
	str[count] = '\0';
	return (str);
}

/**
 * @brief 			Basically, it's a helper function 
 * 					for ft_lexer_get_next_token that advances
 * 					the lexer to the next character 
 * 					and returns the given token.
 * 
 * @param lexer 	The lexer object.
 * @param tkn 		The token to be returned.
 * @return 			The given token.
 */
t_tkn	*ft_lexer_advance_with_tkn(t_lexer *lexer, t_tkn *tkn)
{
	ft_lexer_advance(lexer);
	return (tkn);
}

/**
 * @brief 			The gets current character as a string.
 * 					Used in ft_lexer_get_word to save currect character
 * 					as a string in a TKN->value.
 * 
 * @param lexer 	The lexer object. 
 * @return char* 	Current character as a string.
 */
char	*ft_lexer_char_to_str(t_lexer *lexer)
{
	char	*value;

	value = ft_calloc(2, sizeof(char));
	value[0] = lexer->c;
	value[1] = '\0';
	return (value);
}
