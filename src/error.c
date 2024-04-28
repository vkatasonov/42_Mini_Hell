/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:25:58 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/03 13:26:41 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 				Function to send error message to the user
 * 
 * @param usr_input 	The user input string.
 * @param type_error 	The type of error:
 * 						1: command not found
 * 						2: command not exec
 * 						3: no such file or directory
 * 						4: is not a directory
 * 						11: Wrong quotes usage
 * 						12: Syntax error
 * 						13: Syntax error near unexpected token
 * 						14: Unexpected token in input
 */
void	ft_error(char *usr_input, int type_error)
{
	ft_printf_fd(2, "%sMiniHell:%s", RED, RST);
	if (type_error == 1)
		ft_printf_fd(2, RED " %s: command not found\n" RST, usr_input);
	else if (type_error == 2)
		ft_printf_fd(2, RED " %s: command not exec\n" RST, usr_input);
	else if (type_error == 3)
		ft_printf_fd(2, RED " %s: no such file or directory\n" RST, usr_input);
	else if (type_error == 4)
		ft_printf_fd(2, RED " %s: is not a directory\n" RST, usr_input);
	else if (type_error == INPUT_QUOTES_ERROR)
		ft_printf_fd(2, RED " Wrong quotes usage\n" RST);
	else if (type_error == SYNTAX_ERROR)
		ft_printf_fd(2, RED " Syntax error\n" RST);
	else if (type_error == SYNTAX_ERROR_UNEXPECTED)
		ft_printf_fd(2, RED " Syntax error near unexpected token '%s'\n" RST,
			usr_input);
	else if (type_error == UNEXPECTED_TOKEN)
		ft_printf_fd(2, RED " Unexpected token in input '%s'\n" RST,
			usr_input);
}
