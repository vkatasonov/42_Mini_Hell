/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:55:51 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/01 20:01:37 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Function to get current directory.
 *
 * @param data The data structure containing information about the program.
 * @return A char pointer to a string representing the current working directory.
 * Returns NULL and sets the exit status to 1 if an error occurs.
 * @var pwd The current working directory.
 */
char	*get_current_directory(t_data *data)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_printf_fd(1, "cd: error\n");
		data->exit_status = 1;
		return (NULL);
	}
	return (pwd);
}

/**
 * @brief Function to change directory from the current working 
 * to the specified directory.
 * Helper function for the `ft_cd` builtin.
 * 
 * @param dir The directory to change to.
 * @param data The data structure containing information about the shell.
 * @return 0 on success, -1 on failure.
 */
int	change_directory(char *dir, t_data *data)
{
	if (chdir(dir) == -1)
	{
		ft_error(dir, 3);
		data->exit_status = 1;
		return (-1);
	}
	return (0);
}

/**
 * @brief Function updates the environment variables
 * `OLDPWD` and `PWD` with new values.
 * Helper function for the `ft_cd` builtin.
 * 
 * @param data The main data structure containing 
 * the environment variables.
 * @param pwd_old The old value of the "PWD" variable.
 * @param pwd_new The new value of the "PWD" variable.
 */
void	update_env_variables(t_data *data, char *pwd_old, char *pwd_new)
{
	change_value_env(data, "OLDPWD", pwd_old);
	change_value_env(data, "PWD", pwd_new);
	free_cd(pwd_old, pwd_new);
}

/**
 * @brief Frees the memory allocated for the `OLDPWD` and `PWD` variables.
 * Helper function for the `ft_cd` builtin.
 *
 * @param pwd_old The pointer to the `OLDPWD`
 * @param pwd_new The pointer to the `PWD`
 */
void	free_cd(char *pwd_old, char *pwd_new)
{
	free(pwd_old);
	free(pwd_new);
}

/**
 * @brief Function to handle the cd builtin. 
 * Changes the current working directory.
 * If no arguments are provided, it changes to the home directory.
 * If an argument is provided, it changes to the specified directory.
 * 
 * @param data The main data structure.
 * @param cmds The array of command arguments.
 * 
 * @var pwd_old The old working directory.
 * @var pwd_new The new working directory.
 * @var dir The directory to change to.
 * @var i The index of the command argument.
 */
void	ft_cd(t_data *data, char **cmds)
{
	char	*pwd_old;
	char	*pwd_new;
	char	*dir;
	int		i;

	i = 1;
	pwd_old = get_current_directory(data);
	if (!pwd_old)
		return ;
	if (cmds[i] == NULL)
		dir = get_env_value(data->env_copy, "HOME");
	else
		dir = cmds[i];
	if (change_directory(dir, data) == -1)
	{
		free_cd(pwd_old, NULL);
		return ;
	}
	pwd_new = get_current_directory(data);
	if (!pwd_new)
	{
		free_cd(pwd_old, NULL);
		return ;
	}
	update_env_variables(data, pwd_old, pwd_new);
}
