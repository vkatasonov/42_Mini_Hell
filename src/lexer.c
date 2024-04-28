/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:30:52 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/01 18:29:46 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 				The function initializes the lexer object.
 * 
 * @param input 		User input readed by readline.
 * @return t_lexer* 	Pointer to the lexer object.
 */
t_lexer	*ft_init_lexer(char *input)
{
	t_lexer	*lexer;

	lexer = ft_calloc(1, sizeof(t_lexer));
	lexer->input = input;
	lexer->i = 0;
	lexer->c = input[lexer->i];
	return (lexer);
}

/**
 * @brief 			The function advances the lexer to the next character.
 * 
 * @param lexer 	The lexer object. 
 */
void	ft_lexer_advance(t_lexer *lexer)
{
	if (lexer->c != '\0' && lexer->i < ft_strlen(lexer->input))
	{
		lexer->i += 1;
		lexer->c = lexer->input[lexer->i];
	}
}

/**
 * @brief 			The function gets different tokens from the input
 * 					with it's helper functions (see lexer_tkns_handlers.c)
 * 					It is a finite state machine that returns a token. It checks
 * 					the current character and returns the corresponding token.
 * 
 * @attention 		Very important to use ft_is_ext_no_quotes 
 * 					in the end of the while loop to check special characters
 * 					like $, ~, ©, ¥, ñ, etc. They need to form part of the word.
 * @var t_tkn* 		Pointer to the token.
 * @param lexer 	The lexer object. 
 * @return t_tkn* 	Pointer to the token.
 */
t_tkn	*ft_lexer_get_next_token(t_lexer *lexer)
{
	t_tkn	*tkn;

	tkn = NULL;
	while (lexer->c != '\0' && lexer->i < ft_strlen(lexer->input))
	{
		if (lexer->c == '"' || lexer->c == '\'')
			return (ft_lexer_get_string(lexer));
		ft_handle_whitespace(lexer);
		tkn = ft_handle_pipe(lexer);
		if (tkn != NULL)
			return (tkn);
		tkn = ft_handle_less_than(lexer);
		if (tkn != NULL)
			return (tkn);
		tkn = ft_handle_greater_than(lexer);
		if (tkn != NULL)
			return (tkn);
		if (ft_is_ext_no_quotes((int)lexer->c))
			return (ft_lexer_get_word(lexer));
	}
	ft_lexer_advance(lexer);
	return (NULL);
}

/**
 * @brief 			The function gets a string from the input.
 * 					As a string, we consider a sequence of characters
 * 					between two double quotes and two single quotes
 * 					and also checks if the string is followed by a space
 * 					or the end of the string. If not it keeps iterating
 * 					until it finds a space or the end of the string.
 * 					That implementation is needed to handle cases like
 * 					> "file".txt.
 * 
 * @param lexer 	The lexer object. 
 * 
 * @return t_tkn* 	Pointer to the token with a TKN_STRING type.
 * @var char quote 	The quote character.
 * @var char* value The string value that we need to add to the token.
 * @var t_tkn* tkn 	The token with the TKN_STRING type.
 */
t_tkn	*ft_lexer_get_string(t_lexer *lexer)
{
	char	*value;
	char	quote;
	t_tkn	*tkn;

	quote = lexer->c;
	ft_lexer_advance(lexer);
	value = ft_calloc(1, sizeof(char));
	value[0] = '\0';
	while (lexer->c != quote)
		value = ft_lexer_process_chars(lexer, value);
	ft_lexer_advance(lexer);
	if (lexer->c != ' ' && lexer->c != '\0')
	{
		while (lexer->c != ' ' && lexer->c != '\0' && lexer->c != '|'
			&& lexer->c != '>' && lexer->c != '<')
			value = ft_lexer_process_chars(lexer, value);
	}
	tkn = ft_init_tkn(TKN_STRING, value);
	free(value);
	return (tkn);
}

/**
 * @brief 			Retrieves a word token from the lexer.
 *
 * @param lexer 	The lexer object.
 * 
 * @return 			The word token.
 * @var char* value The value of the token.
 * @var char* tmp 	Temporary string to store the current character.
 * @var char prev_c The previous character.
 * @var t_tkn* tkn 	The token with the TKN_WORD type.
 */
t_tkn	*ft_lexer_get_word(t_lexer *lexer)
{
	char	*value;
	char	*tmp;
	t_tkn	*tkn;
	char	prev_c;

	tmp = NULL;
	prev_c = ' ';
	value = ft_calloc(1, sizeof(char));
	value[0] = '\0';
	value = ft_get_value(lexer, value, tmp, prev_c);
	while (lexer->c == ' ')
		ft_lexer_advance(lexer);
	tkn = ft_init_tkn(TKN_WORD, value);
	free(value);
	return (tkn);
}
