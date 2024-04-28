/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_handlers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:21:51 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/01 18:31:23 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 			Helper function for ft_lexer_get_next_token
 * 					that handles quotes. 
 * 
 * @param lexer 	lexer object
 * @return t_tkn* 	Pointer to the TKNS_STRING token.
 */
t_tkn	*ft_handle_quotes(t_lexer *lexer)
{
	if (lexer->c == '"' || lexer->c == '\'')
		return (ft_lexer_get_string(lexer));
	return (NULL);
}

/**
 * @brief 			Helper function for ft_lexer_get_next_token
 * 					that handles whitespace. Basically, it just advances
 * 					the lexer if the current character is a whitespace.
 * 
 * @param lexer 	lexer object
 */
void	ft_handle_whitespace(t_lexer *lexer)
{
	while (lexer->c == ' ' || lexer->c == '\t' || lexer->c == '\n')
		ft_lexer_advance(lexer);
}

/**
 * @brief 			Helper function for ft_lexer_get_next_token
 * 					that handles pipe.
 * 
 * @param lexer 	lexer object
 * @return t_tkn* 	TKN_PIPE token if the current
 * 					character is a pipe, TKN_ERROR if more than 2 pipes
 * 					found in the string, otherwise NULL.
 * @var char* value The string where the pipe symbols
 * 					are stored that will be used to create the token.
 * @var t_tkn* tkn 	The token structure that will be
 * 					returned.
 */
t_tkn	*ft_handle_pipe(t_lexer *lexer)
{
	char	*value;
	t_tkn	*tkn;

	if (lexer->c == '|' && ft_count_the_same(lexer, '|') >= 2)
	{
		value = ft_str_repeat('|', ft_count_the_same(lexer, '|'));
		lexer->i += ft_count_the_same(lexer, '|');
		lexer->c = lexer->input[lexer->i];
		tkn = ft_init_tkn(TKN_ERROR, value);
		free (value);
		return (tkn);
	}
	else if (lexer->c == '|' && ft_count_the_same(lexer, '|') == 1)
	{
		value = ft_lexer_char_to_str(lexer);
		tkn = ft_init_tkn(TKN_PIPE, value);
		free(value);
		return (ft_lexer_advance_with_tkn(lexer, tkn));
	}
	return (NULL);
}

/**
 * @brief 			Helper function for ft_lexer_get_next_token
 * 					that handles greater than symbols as redirections.
 * 
 * @param lexer 	lexer object
 * @return t_tkn* 	TKN_ERROR if 3 or more < found in the string,
 * 					TKN_REDIR_HERE_DOC if 2 < found in the string, TKN_REDIR_IN
 * 					if 1 < found in the string, otherwise NULL.
 */
t_tkn	*ft_handle_less_than(t_lexer *lexer)
{
	char	*value;
	t_tkn	*tkn;

	value = NULL;
	tkn = NULL;
	if (lexer->c == '<')
		ft_handle_less_than_helper(lexer, value, &tkn);
	return (tkn);
}

/**
 * @brief 			Helper function for ft_lexer_get_next_token
 * 					that handles greater than symbols as redirections.
 * 
 * @param lexer 	lexer object
 * @return t_tkn* 	TKN_ERROR if 3 or more > found in the string,
 * 					TKN_REDIR_APPEND if 2 > found in the string, TKN_REDIR_OUT
 * 					if 1 > found in the string, otherwise NULL.
 */
t_tkn	*ft_handle_greater_than(t_lexer *lexer)
{
	char	*value;
	t_tkn	*tkn;

	value = NULL;
	tkn = NULL;
	if (lexer->c == '>')
		ft_handle_greater_than_helper(lexer, value, &tkn);
	return (tkn);
}
