/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:34:51 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/02 22:38:05 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to parse user input, 
 * check for basic errors, tokenize it and
 * convert tokens to commands
 * 
 * @param usr_input User input received from
 * the readline.
 * @param data Main data structure that holds
 * such structures as token, command, etc
 * (see types of structures in minishell.h)
 */
void	ft_parser(char *usr_input, t_data *data)
{
	if (!(ft_is_input_error(usr_input, data)))
	{
		ft_get_new_input(usr_input, data);
		ft_tknize_input(data);
		ft_tkns_to_cmds(data);
	}
	else
		data->cmd = NULL;
	return ;
}
