/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:18:49 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/03 19:09:26 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to free a token structure
 * 
 * @param tkn: a pointer to the token structure.
 */
void	ft_free_tkn(t_tkn *tkn)
{
	if (tkn == NULL)
		return ;
	free(tkn->value);
	free(tkn);
}

/**
 * @brief Function to free a token list structure
 * 
 * @param data: a pointer to the token list structure.
 * @param tkn_lst: a pointer to the token list structure.
 * 
 * @return int: 1 if the token has an error, 0 otherwise.
 */
int	ft_check_tkn_errors(t_data *data, t_tkn_lst *tkn_lst)
{
	if (ft_tkns_error_exit(data) == 1)
	{
		ft_free_cmd(data->cmd);
		data->cmd = NULL;
		return (1);
	}
	if (!ft_valid_pipe(tkn_lst, data))
	{
		ft_free_cmd(data->cmd);
		data->cmd = NULL;
		return (1);
	}
	if (!ft_valid_redir(tkn_lst, data))
	{
		ft_free_cmd(data->cmd);
		data->cmd = NULL;
		return (1);
	}
	return (0);
}
