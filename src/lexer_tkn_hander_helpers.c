/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkn_hander_helpers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:06:32 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/31 21:26:01 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 			Function to handle the greater than symbol
 * 					and the logic of the redirections. 
 * 					Helper function for ft_handle_greater_than function
 * 					to manage memory leaks.
 * 
 * @param lexer 	lexer object
 * @param value 	value of the token
 * @param tkn 		pointer to the token we need to proceed
 */
void	ft_handle_greater_than_helper(t_lexer *lexer, char *value, t_tkn **tkn)
{
	if (ft_count_the_same(lexer, '>') >= 3)
	{
		value = ft_str_repeat('>', ft_count_the_same(lexer, '>'));
		lexer->i += ft_count_the_same(lexer, '>');
		lexer->c = lexer->input[lexer->i];
		*tkn = ft_init_tkn(TKN_ERROR, value);
		free(value);
	}
	else if (ft_count_the_same(lexer, '>') == 2)
	{
		lexer->i++;
		*tkn = ft_lexer_advance_with_tkn(lexer,
				ft_init_tkn(TKN_REDIR_APPEND, ">>"));
	}
	else if (ft_count_the_same(lexer, '>') == 1)
	{
		value = ft_lexer_char_to_str(lexer);
		*tkn = ft_lexer_advance_with_tkn(lexer,
				ft_init_tkn(TKN_REDIR_OUT, value));
		free(value);
	}
}

/**
 * @brief 			Function to handle the less than symbol
 * 					and the logic of the redirections. 
 * 					Helper function for ft_handle_less_than function
 * 					to manage memory leaks.
 * 
 * @param lexer 	lexer object
 * @param value 	value of the token
 * @param tkn 		pointer to the token we need to proceed
 */
void	ft_handle_less_than_helper(t_lexer	*lexer, char *value, t_tkn **tkn)
{
	if (ft_count_the_same(lexer, '<') >= 3)
	{
		value = ft_str_repeat('<', ft_count_the_same(lexer, '<'));
		lexer->i += ft_count_the_same(lexer, '<');
		lexer->c = lexer->input[lexer->i];
		*tkn = ft_init_tkn(TKN_ERROR, value);
		free(value);
	}
	else if (ft_count_the_same(lexer, '<') == 2)
	{
		lexer->i++;
		*tkn = ft_lexer_advance_with_tkn(lexer,
				ft_init_tkn(TKN_REDIR_HERE_DOC, "<<"));
	}
	else if (ft_count_the_same(lexer, '<') == 1)
	{
		value = ft_lexer_char_to_str(lexer);
		*tkn = ft_lexer_advance_with_tkn(lexer,
				ft_init_tkn(TKN_REDIR_IN, value));
		free(value);
	}
}
