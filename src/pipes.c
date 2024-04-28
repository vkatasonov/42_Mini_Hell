/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:19:39 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/03 18:59:49 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function that execute a command in the child process.
 *
 * @param args: a pointer to the execute command structure.
 * @param data: a pointer to the data structure.
 * @param save: an integer that contain the save value.
 */
void	execute_child_process(t_exec_cmd *args, t_data *data, int save)
{
	if (args->input != 0)
	{
		dup2(args->input, 0);
		close(args->input);
	}
	if (args->output != 1 && args->cmd->redir_count[0] == 0)
	{
		dup2(args->output, 1);
		close(args->output);
	}
	if (args->cmd->flag_redir)
		ft_redir(args->cmd, save, args->pipefd);
	if (args->cmd->args != NULL)
		exec_local(args->cmd->args, data->env_copy, data);
	exit(0);
}

/**
 * @brief Function that execute a command in the parent process.
 *
 * @param args: a pointer to the execute command structure.
 * @param pid: a pid_t that contain the process id.
 * @param data: a pointer to the data structure.
 */
void	execute_parent_process(t_exec_cmd *args, pid_t pid, t_data *data)
{
	int		status;

	waitpid(pid, &status, 0);
	if (check_builtin_rare(args->cmd->args) == 1)
		ft_do_builtin_rare(data, args->cmd->args);
	else
		data->exit_status = WEXITSTATUS(status);
	if (args->input != 0)
		close(args->input);
	if (args->output != 1)
		close(args->output);
}

/**
 * @brief Function that execute a command checking if
 * 		is a child or parent process.
 *
 * @param args: a pointer to the execute command structure.
 * @param data: a pointer to the data structure.
 * @param save: an integer that contain the save value.
 */
void	execute_command(t_exec_cmd *args, t_data *data, int save)
{
	pid_t	pid;

	args->pipefd[0] = args->input;
	args->pipefd[1] = args->output;
	ft_check_counts(args->cmd);
	pid = fork();
	if (pid == 0)
		execute_child_process(args, data, save);
	else
		execute_parent_process(args, pid, data);
}

/**
 * @brief Function that execute a command in a pipeline
 * 		if has pipe, if not execute the command.
 *
 * @param args: a pointer to the pipeline arguments structure.
 * @param data: a pointer to the data structure.
 * @param save: an integer that contain the save value.
 */
void	execute_pipeline_command(t_pipeline_args *args, t_data *data, int save)
{
	t_exec_cmd	exec_args;
	t_cmd		**cmd_ptr;

	cmd_ptr = args->cmd;
	if ((*cmd_ptr)->next != NULL)
		pipe(args->pipefd);
	else
		args->pipefd[1] = 1;
	exec_args.input = *(args->in);
	exec_args.output = args->pipefd[1];
	exec_args.cmd = *cmd_ptr;
	exec_args.pipefd[0] = args->pipefd[0];
	exec_args.pipefd[1] = args->pipefd[1];
	execute_command(&exec_args, data, save);
	if (*(args->in) != 0)
		close(*(args->in));
	*(args->in) = args->pipefd[0];
	*cmd_ptr = (*cmd_ptr)->next;
}

/**
 * @brief Function that save data in args and send to execute_pipeline_command.
 *
 * @param data: a pointer to the data structure.
 */
void	execute_pipeline(t_data *data)
{
	int				in;
	t_cmd			*cmd;
	int				save;
	t_pipeline_args	args;

	if (data->cmd == NULL)
		return ;
	save = dup(0);
	cmd = data->cmd;
	in = 0;
	while (cmd != NULL)
	{
		args.in = &in;
		args.cmd = &cmd;
		execute_pipeline_command(&args, data, save);
	}
	dup2(save, 0);
	close(save);
	if (in != 0)
		close(in);
}
