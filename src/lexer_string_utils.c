/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_string_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:56:25 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/01 18:32:39 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 			Function that processes characters in the lexer
 * 					in case of a string token.
 * 
 * @param lexer 	The lexer object.
 * @param value 	The value of the token.
 * @return char* 	The value of the token.
 * @var tmp 		The temporary string.
 */
char	*ft_lexer_process_chars(t_lexer *lexer, char *value)
{
	char	*tmp;

	tmp = ft_lexer_char_to_str(lexer);
	value = ft_realloc(value,
			(ft_strlen(value) + ft_strlen(tmp) + 1) * sizeof(char));
	ft_strcat(value, tmp);
	ft_lexer_advance(lexer);
	free(tmp);
	return (value);
}

/**
 * @brief 			Helper function for ft_lexer_get_word
 * 					that takes the value of a token and save it 
 * 					in a string.
 * @param lexer 	The lexer object.
 * @param value 	The value of the token.
 * @param tmp 		The temporary string.
 * @param prev_c 	The previous character.
 * @return char* 	The value of the token as a string
 */
char	*ft_get_value(t_lexer *lexer, char *value, char *tmp, char prev_c)
{
	while (ft_is_extended((int)lexer->c))
	{
		if (lexer->c == ' ' || lexer->c == '|'
			|| lexer->c == '>' || lexer->c == '<')
			break ;
		tmp = ft_lexer_char_to_str(lexer);
		value = ft_realloc(value, (ft_strlen(value) + ft_strlen(tmp) + 1)
				* sizeof(char));
		ft_strcat(value, tmp);
		free(tmp);
		prev_c = lexer->c;
		ft_lexer_advance(lexer);
		if ((lexer->c == '"' || lexer->c == '\'') && prev_c != ' ')
		{
			tmp = ft_get_string_without_order(lexer);
			value = ft_realloc(value,
					(ft_strlen(value) + ft_strlen(tmp) + 1)
					* sizeof(char));
			ft_strcat(value, tmp);
			free(tmp);
			break ;
		}
	}
	return (value);
}

/**
 * @brief 			Basically, a copy of the ft_lexer_get_string 
 * 					function with one important difference: it doesn't
 * 					initialize the string token, but instead it returns
 * 					a string value of the string token that goes right
 * 					after the current token. 
 * 					It's used to handle the cases like 
 * 					export test="some string var" where 
 * 					the string token follows the word token without
 * 					any space between them. In this case, we need to
 * 					get the string token value without initializing
 * 					the string token and continue with the word token: 
 * 					tkn 1 = export, tkn 2 = test="some string var".
 * 
 * @param lexer 	The lexer object.
 * @return char* 	The string value of the token.
 * @var value 		The value of the token (the string we need).
 */
char	*ft_get_string_without_order(t_lexer *lexer)
{
	char	*value;
	char	quote;

	quote = lexer->c;
	ft_lexer_advance(lexer);
	value = ft_calloc(1, sizeof(char));
	value[0] = '\0';
	while (lexer->c != quote)
		value = ft_lexer_process_chars(lexer, value);
	ft_lexer_advance(lexer);
	if (lexer->c != ' ' && lexer->c != '\0')
	{
		while (lexer->c != ' ' && lexer->c != '\0')
			value = ft_lexer_process_chars(lexer, value);
	}
	return (value);
}
