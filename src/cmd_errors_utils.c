/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_errors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 11:34:22 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/23 16:48:59 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 		Function to check if there is 
 * 				a tkn with the TKN_ERROR type in the list.
 * 				If so it prints the error message and returns 1.
 * @param data 	Main data structure
 * @return 		1 if there is an error, 0 if not
 */
int	ft_tkns_error_exit(t_data *data)
{
	t_tkn_lst	*tkns;

	tkns = data->tkns;
	while (tkns != NULL)
	{
		if (tkns->tkn->e_type == TKN_ERROR)
		{
			ft_error(tkns->tkn->value, UNEXPECTED_TOKEN);
			data->exit_status = 258;
			return (1);
		}
		tkns = tkns->next;
	}
	return (0);
}

/**
 * @brief 		Function to check if there are
 * 				valid tokens on the both sides of the pipe.
 * @param data 	Main data structure
 * @param tkns 	The list of tokens
 * @return 		int 1 if there is an error, 0 if not
 */
int	ft_valid_pipe(t_tkn_lst *tkns, t_data *data)
{
	t_tkn_lst	*tmp;

	tmp = tkns;
	while (tmp != NULL)
	{
		if (tmp->tkn->e_type == TKN_PIPE && (tmp->prev == NULL
				|| tmp->next == NULL))
		{
			ft_error("|", SYNTAX_ERROR_UNEXPECTED);
			data->exit_status = 258;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

/**
 * @brief 		Function to check if there is 
 * 				valid tokens right next to redirection.
 * @param data 	Main data structure
 * @param tkns 	The list of tokens
 * @return 		1 if there is an error, 0 if not
 */
int	ft_valid_redir(t_tkn_lst *tkns, t_data *data)
{
	t_tkn_lst	*tmp;

	tmp = tkns;
	while (tmp != NULL)
	{
		if ((tmp->tkn->e_type == TKN_REDIR_APPEND
				|| tmp->tkn->e_type == TKN_REDIR_IN
				|| tmp->tkn->e_type == TKN_REDIR_OUT
				|| tmp->tkn->e_type == TKN_REDIR_HERE_DOC)
			&& ((tmp->next == NULL) || (tmp->next->tkn->e_type != TKN_WORD
					&& tmp->next->tkn->e_type != TKN_STRING)))
		{
			ft_error(tmp->tkn->value, SYNTAX_ERROR_UNEXPECTED);
			data->exit_status = 258;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
