/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns_to_cmds.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:56:09 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/03 16:17:47 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 			Helper function to handle the token types
 * 					in the process of converting tokens to commands
 * 					(in ft_tkns_to_cmds function).
 * 
 * @param tkn 		The token structure
 * @param tkn_lst 	Token list from data structure
 * @param tmp 		Temporary command structure
 * @param data 		Main data structure
 * 					(for structure types see minishell.h)
 */
void	ft_handle_tkn_type(t_tkn *tkn,
						t_tkn_lst **tkn_lst,
						t_cmd **tmp,
						t_data *data)
{
	if (tkn->e_type == TKN_PIPE)
	{
		(*tmp)->next = ft_init_cmd();
		*tmp = (*tmp)->next;
		*tkn_lst = (*tkn_lst)->next;
	}
	else if (tkn->e_type == TKN_REDIR_IN || tkn->e_type == TKN_REDIR_OUT
		|| tkn->e_type == TKN_REDIR_APPEND
		|| tkn->e_type == TKN_REDIR_HERE_DOC)
	{
		ft_add_redir_to_cmd(data, *tmp, tkn_lst);
		(*tmp)->flag_redir = 1;
	}
	else
		ft_add_arg_to_cmd(*tmp, tkn_lst);
}

/**
 * @brief 			Function checks correct usage 
 * 					of the symbols in the token list with 
 * 					helper functions (see cmd_errors_utils.c).
 * 					For e.g., after and before pipes we need
 * 					to have valid arguments (not NULL) or 
 * 					after redirection should go other token
 * 					that has word or string type. Then this function 
 * 					converts tokens to commands which are stored in
 * 					the main data structure (data->cmd).
 * 
 * @param data 		Main data structure
 * @var tmp 		Temporary command structure
 * @var tkn_lst 	Token list from data structure
 * @var tkn 		Token structure
 * 					(for structure types see minishell.h)
 */
void	ft_tkns_to_cmds(t_data *data)
{
	t_cmd		*tmp;
	t_tkn_lst	*tkn_lst;
	t_tkn		*tkn;

	tkn_lst = data->tkns;
	tmp = ft_init_cmd();
	data->cmd = tmp;
	if (ft_check_tkn_errors(data, tkn_lst) == 1)
		return ;
	while (tkn_lst)
	{
		tkn = tkn_lst->tkn;
		ft_handle_tkn_type(tkn, &tkn_lst, &tmp, data);
	}
}

/**
 * @brief 			Function to add arguments to the command structure.
 * 
 * @param cmd 		The command structure
 * @param tkn_lst 	The token list from data structure
 * 					(for structure types see minishell.h)
 */
void	ft_add_arg_to_cmd(t_cmd *cmd, t_tkn_lst **tkn_lst)
{
	while (*tkn_lst != NULL && (*tkn_lst)->tkn->e_type != TKN_PIPE
		&& (*tkn_lst)->tkn->e_type != TKN_REDIR_IN
		&& (*tkn_lst)->tkn->e_type != TKN_REDIR_OUT
		&& (*tkn_lst)->tkn->e_type != TKN_REDIR_APPEND
		&& (*tkn_lst)->tkn->e_type != TKN_REDIR_HERE_DOC)
	{
		ft_realloc_args(cmd, ft_strdup((*tkn_lst)->tkn->value));
		*tkn_lst = (*tkn_lst)->next;
	}
}

/**
 * @brief 				Function to create a new redirection structure
 * 						and add it to the command structure.
 * 
 * @param cmd 			The command structure
 * 
 * @return t_redirect* 	The redirection structure
 * 						(for structure types see minishell.h)
 * @var redir 			The redirection list from the command structure
 */
t_redirect	*ft_make_new_redir(t_cmd *cmd)
{
	t_redirect	*redir;

	if (cmd->redir == NULL)
	{
		cmd->redir = ft_calloc(1, sizeof(t_redirect));
		redir = cmd->redir;
	}
	else
	{
		redir = cmd->redir;
		while (redir->next != NULL)
			redir = redir->next;
		redir->next = ft_calloc(1, sizeof(t_redirect));
		redir = redir->next;
	}
	return (redir);
}

/**
 * @brief 			Function to add redirection to each command.
 * 
 * @param data 		Main data structure
 * @param cmd 		The command structure
 * @param tkns_lst 	The token list from data structure
 * 					(for structure types see minishell.h)
 * @return int 		1 if there is an error, 0 if not
 */
int	ft_add_redir_to_cmd(t_data *data, t_cmd *cmd, t_tkn_lst **tkns_lst)
{
	t_redirect	*redir;
	t_tkn_lst	*tkns;

	tkns = *tkns_lst;
	redir = ft_make_new_redir(cmd);
	redir->redir_type = ft_strdup(tkns->tkn->value);
	if (tkns->next == NULL)
	{
		ft_error("newline", SYNTAX_ERROR_UNEXPECTED);
		data->exit_status = 258;
		return (1);
	}
	else
		redir->file = ft_strdup(tkns->next->tkn->value);
	*tkns_lst = (*tkns_lst)->next;
	if (*tkns_lst != NULL)
		*tkns_lst = (*tkns_lst)->next;
	return (0);
}
