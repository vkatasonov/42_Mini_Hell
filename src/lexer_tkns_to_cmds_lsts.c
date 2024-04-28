/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_to_cmds_lsts.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:44:43 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/01 18:31:00 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 			Function to reallocate memory 
 * 					for args in the command list
 * 
 * @param cmd 		The command structure.
 * @param new_arg 	The new argument to be added.
 * @var new_args 	The new arguments list.
 * @var i 			The index of the current argument.
 * @var j 			The index of the new argument.
 */
void	ft_realloc_args(t_cmd *cmd, char *new_arg)
{
	char	**new_args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd->args != NULL && cmd->args[i] != NULL)
		i++;
	new_args = malloc((i + 2) * sizeof(char *));
	if (new_args == NULL)
	{
		free(new_arg);
		return ;
	}
	while (j < i)
	{
		new_args[j] = cmd->args[j];
		j++;
	}
	new_args[i] = new_arg;
	new_args[i + 1] = NULL;
	free(cmd->args);
	cmd->args = new_args;
}
