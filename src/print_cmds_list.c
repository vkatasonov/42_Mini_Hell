/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:49:48 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/22 18:49:04 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to print the redirections
 * from the list of redirections in the command.
 * Used in the debugging process.
 * 
 * @param redir Redirection list
 * (see struct s_redirect in lexer.h)
 */
void	ft_print_redirections(t_redirect *redir)
{
	while (redir != NULL)
	{
		ft_printf("redir_type: %s\n", redir->redir_type);
		ft_printf("redir_file: %s\n", redir->file);
		redir = redir->next;
	}
}

/**
 * @brief Function to print the single command
 * from the list of commands saved in the data->cmd.
 * Used in the debugging process.
 * 
 * @param cmd Single command from the data->cmd
 * (see struct s_cmd in lexer.h)
 * @param i the number of the command to print
 */
void	ft_print_single_cmd(t_cmd *cmd, int i)
{
	int	j;

	j = 0;
	ft_printf(YELLOW"\n----------- Command %d -----------\n"RST, i);
	ft_printf("ARGUMENTS:\n");
	if (cmd->args == NULL)
		ft_printf("No arguments\n");
	else
	{
		while (cmd->args[j] != NULL)
		{
			ft_printf("Arg[%d] = %s\n", j, cmd->args[j]);
			j++;
		}
	}
	ft_printf("***** END OF ARGS *****\n");
	if (cmd->redir != NULL)
		ft_print_redirections(cmd->redir);
	ft_printf("flag_redir: %d\n", cmd->flag_redir);
	ft_printf(YELLOW"-------- End of command %d --------\n\n"RST, i);
}

/**
 * @brief Function to print the list of commands
 * saved in the data->cmd (see struct s_cmd in lexer.h).
 * Used in the debugging process.
 * 
 * @param data The main data structure
 * @var cmd The pointer to the current node in the list
 * @var i The iterating number of the command to print
 */
void	ft_print_cmds(t_data *data)
{
	t_cmd	*cmd;
	int		i;

	cmd = data->cmd;
	i = 0;
	while (cmd != NULL)
	{
		ft_print_single_cmd(cmd, i);
		cmd = cmd->next;
		i++;
	}
}
