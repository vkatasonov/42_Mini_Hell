/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:13:40 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/26 20:23:41 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to check the number of redirections.
 * 
 * @param cmd: a pointer to the command structure.
 */
void	ft_check_counts(t_cmd *cmd)
{
	t_redirect	*tmp;
	int			*count;

	count = malloc(sizeof(int) * 2);
	if (count == NULL)
		return ;
	count[0] = 0;
	count[1] = 0;
	tmp = cmd->redir;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->redir_type, ">", 2) == 0
			|| ft_strncmp(tmp->redir_type, ">>", 3) == 0)
			count[1]++;
		else if (ft_strncmp(tmp->redir_type, "<", 2) == 0
			|| ft_strncmp(tmp->redir_type, "<<", 3) == 0)
			count[0]++;
		tmp = tmp->next;
	}
	cmd->redir_count[0] = count[0];
	cmd->redir_count[1] = count[1];
	free(count);
}

/**
 * @brief Function to redirect output of a command.
 * 
 * @param cmd: a pointer to the command structure.
 * @param fd: an integer that contain the file descriptor.
 */
void	ft_output(t_cmd *cmd, int fd)
{
	if (ft_strncmp(cmd->redir->redir_type, ">", 2) == 0)
	{
		fd = open(cmd->redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror("Error opening file");
			return ;
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else if (ft_strncmp(cmd->redir->redir_type, ">>", 3) == 0)
	{
		fd = open(cmd->redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
		{
			perror("Error opening file");
			return ;
		}
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
}

/**
 * @brief Function to redirect input of a command.
 * 
 * @param cmd: a pointer to the command structure.
 * @param fd: an integer that contain the file descriptor.
 * @param save: an integer that contain the save value.
 */
void	ft_input(t_cmd *cmd, int fd, int save)
{
	if (ft_strncmp(cmd->redir->redir_type, "<", 2) == 0)
	{
		fd = open(cmd->redir->file, O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening file");
			return ;
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else if (ft_strncmp(cmd->redir->redir_type, "<<", 3) == 0)
		ft_case_heredoc(cmd, save);
}

/**
 * @brief Function to manage heredoc case.
 * 
 * @param cmd: a pointer to the command structure.
 * @param save: an integer that contain the save value.
 */
void	ft_case_heredoc(t_cmd *cmd, int save)
{
	int		pfd[2];
	char	*line;

	pipe(pfd);
	dup2(save, 0);
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, cmd->redir->file) == 0)
		{
			free(line);
			break ;
		}
		write(pfd[1], line, ft_strlen(line));
		write(pfd[1], "\n", 1);
		free(line);
	}
	close(pfd[1]);
	dup2(pfd[0], STDIN_FILENO);
	close(pfd[0]);
}

/**
 * @brief Function to redirect input and output of a command.
 * 
 * @param cmd: a pointer to the command structure.
 * @param save: an integer that contain the save value.
 * @param pipefd: an integer double pointer that
 * 		contain the pipe file descriptor.
 */
void	ft_redir(t_cmd *cmd, int save, int pipefd[2])
{
	t_redirect	*tmp;

	tmp = cmd->redir;
	while (cmd->redir != NULL)
	{
		ft_input(cmd, 0, save);
		if (cmd->redir_count[0] == 0)
		{
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
		}
		cmd->redir = cmd->redir->next;
	}
	cmd->redir = tmp;
	while (cmd->redir != NULL)
	{
		ft_output(cmd, 0);
		if (cmd->redir_count[1] == 0)
		{
			dup2(pipefd[1], STDOUT_FILENO);
			if (pipefd[1] != 1)
				close(pipefd[1]);
		}
		cmd->redir = cmd->redir->next;
	}
}
