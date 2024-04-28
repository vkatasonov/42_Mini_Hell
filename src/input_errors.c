/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:30:41 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/03 13:26:47 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 				Checks for unbalanced or 
 * 						open quotes in user input.
 * @param usr_input 	The user input string.
 * 
 * @details
 * 						The function uses three flags 
 * 						to track the state of single quotes, 
 * 						double quotes, and escape characters.
 * 
 * @var int i 			Index of the string.
 * 
 * @var int flags[3] 	Array of flags used to 
 * 						track the state of quotes and escape characters.
 * 
 * @var flags[0] 		Flag for single quotes. 
 * 						This flag is toggled each time a single 
 * 						quote (') is encountered, unless a double 
 * 						quote is currently open (flags[1] is 1).
 * 
 * @var flags[1] 		Flag for double quotes. 
 * 						This flag is toggled each time a double quote (") 
 * 						is encountered, provided a single quote is not 
 * 						currently open (flags[0] is 0) and the next 
 * 						character is not escaped (flags[2] is 0).
 * 
 * @var flags[2] 		Flag for escape characters. 
 * 						This flag is toggled each time a backslash 
 * 						`\\` is encountered, unless a single quote 
 * 						is currently open (flags[0] is 1). 
 * 						If the flag is 1, it means the next character 
 * 						is escaped and should not be considered as a quote.
 * 
 * 						If a backslash followed by a single quote is found 
 * 						within single quotes, the function immediately 
 * 						returns 1, indicating an error.
 * 
 * @return int 			1 if there is an open quote, 0 otherwise. 
 * 
 * TESTS:
 * 						This is a test OK
 * 						This is a 'test' OK
 * 						"This is a \"test\" OK
 * 						"This is a 'test" OK
 * 						'This is a "test' OK
 * 						"This is a '' test" OK
 * 						"This is a \"\" test" OK
 * 						'This is a \'\' test' ERROR 
 * 						'This is a "" test' OK
 * 						"This is a \"test ERROR (need a " to close
 * 						the quote, because escape character is 
 * 						not found and " considered as an open 
 * 						quote in the end of the string)
 * 						"This is a 'test ERROR (need a " to close the quote)
 * 						'This is a "test ERROR (need a ' to close the quote)
 * 						echo "This is test '$USER '$TERMCOLOR'" OK
 */
static int	ft_check_input_quotes(char *usr_input)
{
	int	i;
	int	flags[3];

	i = -1;
	while (++i < 3)
		flags[i] = 0;
	i = -1;
	while (usr_input[++i] != '\0')
	{
		if (usr_input[i] == '\\' && usr_input[i + 1] == '\'' && flags[0])
			return (1);
		if (usr_input[i] == '\\' && !flags[0])
			flags[2] = 1;
		else
		{
			if (usr_input[i] == '\'' && !flags[1])
				flags[0] = !flags[0];
			else if (usr_input[i] == '\"' && !flags[0] && !flags[2])
				flags[1] = !flags[1];
			flags[2] = 0;
		}
	}
	if (flags[0] || flags[1])
		return (1);
	return (0);
}

/**
 * @brief 				Helper function to check if the user input
 * 						matches a symbol and its length.
 * 
 * @param usr_input 	User input string.
 * @param symbol 		The symbol/s to match.
 * @param length 		The length of the symbol/string.
 * @return int 			1 if the input matches the symbol and
 * 						its length, 0 otherwise.
 */
static int	ft_match_symbol_and_length(char *usr_input, char *symbol,
		int length)
{
	return (ft_strncmp(usr_input, symbol, length) == 0
		&& (int)ft_strlen(usr_input) == length);
}

/**
 * @brief 				Checks if the user input string
 * 						contains only a standalone symbols and
 * 						wrong symbol combinations and doesn't
 * 						contain any other characters that 
 * 						is considered as an error by default.
 * @param input 		The user input string.
 * @return int 			1 if the input standalone symbols, 
 * 						0 otherwise.
 */
static int	ft_is_standalone_symbols(char *usr_input)
{
	if (ft_match_symbol_and_length(usr_input, ">", 1)
		|| ft_match_symbol_and_length(usr_input, "<", 1)
		|| ft_match_symbol_and_length(usr_input, "|", 1)
		|| ft_match_symbol_and_length(usr_input, "&", 1)
		|| ft_match_symbol_and_length(usr_input, ";", 1)
		|| ft_match_symbol_and_length(usr_input, ">>", 2)
		|| ft_match_symbol_and_length(usr_input, "<<", 2)
		|| ft_match_symbol_and_length(usr_input, "||", 2)
		|| ft_match_symbol_and_length(usr_input, "&&", 2)
		|| ft_match_symbol_and_length(usr_input, "|&", 2)
		|| ft_match_symbol_and_length(usr_input, "&|", 2)
		|| ft_match_symbol_and_length(usr_input, "<|", 2)
		|| ft_match_symbol_and_length(usr_input, ">|", 2)
		|| ft_match_symbol_and_length(usr_input, "&>", 2)
		|| ft_match_symbol_and_length(usr_input, "&<", 2)
		|| ft_match_symbol_and_length(usr_input, ";<", 2)
		|| ft_match_symbol_and_length(usr_input, ";>", 2)
		|| ft_match_symbol_and_length(usr_input, ";;", 2)
		|| ft_match_symbol_and_length(usr_input, "?<", 2)
		|| ft_match_symbol_and_length(usr_input, "?>", 2)
		|| ft_match_symbol_and_length(usr_input, "&?", 2)
		|| ft_match_symbol_and_length(usr_input, "&-", 2))
		return (1);
	return (0);
}

/**
 * @brief 			Function to check if the user input
 * 					contains an error.
 * 
 * @param usr_input The user input string.
 * @return int 		1 if the input contains an error, 0 otherwise.
 */
int	ft_is_input_error(char *usr_input, t_data *data)
{
	if (ft_is_standalone_symbols(usr_input) == 1)
	{
		ft_error(usr_input, SYNTAX_ERROR);
		data->exit_status = EXIT_SYNTAX_ERROR;
		return (1);
	}
	if (ft_check_input_quotes(usr_input) == 1)
	{
		ft_error(usr_input, INPUT_QUOTES_ERROR);
		data->exit_status = EXIT_SYNTAX_ERROR;
		return (1);
	}
	return (0);
}
