/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:19:10 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/02 22:35:19 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 		Function to execute a command with absolute path.
 *
 * @param cmds	a double char pointer that contain the arguments.
 * @param env	a double char pointer that contain the enviromental variables.
 * @param data	a pointer to the data structure.
 */
void	exec_absolute_path(char **cmds, char **env, t_data *data)
{
	if (access(cmds[0], F_OK) == 0)
	{
		if (access(cmds[0], X_OK) == 0)
		{
			execve(cmds[0], cmds, env);
			return ;
		}
		else
		{
			ft_printf_fd(2, "%s: Permission denied.\n", *cmds);
			data->exit_status = 1;
			return ;
		}
	}
	else
	{
		ft_printf_fd(2, "%s: No such file or directory\n", *cmds);
		data->exit_status = 1;
		return ;
	}
}

/**
 * @brief 			Function to execute a command handler.
 * @param command	a pointer that contain the string of the command.
 * @param cmds		a double char pointer that contain the string of readline.
 * @param env		a double char pointer that 
 * 					contain the enviromental variables.
 * @return			1 if the command is not found,
					2 if the command is found (in case of return 2, maybe dont need
					to be returned, because execve should exit the proccess, but was
					added just in case).
 */
int	execute_command_handler(char *command, char **cmds, char **env)
{
	if (access(command, F_OK) == 0)
	{
		if (access(command, X_OK) == 0)
		{
			execve(command, cmds, env);
			return (2);
		}
		else
		{
			ft_printf_fd(2, "%s: Permission denied.\n", *cmds);
			return (1);
		}
	}
	else
		return (1);
}

/**
 * @brief 				Function that executes a command 
 * 						by searching for it in the directories 
 * 						specified in the PATH environment variable.
 * 
 * @param cmds 			An array of strings with command and its arguments.
 * @param env 			An array of strings with environment variables.
 * @param enviroment 	Pointer to the enviromental variables.
 * @param data 			Main data structure.
 * @var command 		Pointer to the command.
 * @var path 			Pointer to the path.
 * @var i 				Counter.
 * @var found 			Flag to check if the command is found.
 */
void	exec_command_in_path(char **cmds, char **env,
	t_env *enviroment, t_data *data)
{
	char	*command;
	char	**path;
	int		i;
	int		found;

	found = 0;
	i = 0;
	path = ft_split(get_env_value(enviroment, "PATH"), ':');
	while (path[i])
	{
		command = ft_strjoin(ft_strjoin(path[i], "/"), *cmds);
		if (execute_command_handler(command, cmds, env) == 2)
		{
			data->exit_status = 0;
			found = 1;
			break ;
		}
		i++;
	}
	if (!found)
		ft_printf_fd(2, "%s: Command not found.\n", *cmds);
	free_split(path);
}

/**
 * @brief 				Function to execute a command.
 *
 * @param cmds 			a double char pointer that contain the arguments.
 * @param enviroment 	a pointer to the enviromental variables.
 * @param data 			main data structure.
 * @var env 			a double char pointer 
 * 						that contain the enviromental variables.
 */
void	exec_local(char **cmds, t_env *enviroment, t_data *data)
{
	char	**env;

	env = ft_env_to_char(enviroment);
	if (check_builtin_rare(cmds))
		exit(0);
	if (check_builtin(cmds))
		exec_builtin(data, cmds);
	else
	{
		if (cmds[0][0] == '/' || strncmp(cmds[0], "./", 2) == 0)
			exec_absolute_path(cmds, env, data);
		else
			exec_command_in_path(cmds, env, enviroment, data);
		exit(127);
	}
}
