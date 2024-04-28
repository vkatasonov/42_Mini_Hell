/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:23:45 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/02 19:37:57 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Function to handle the unset builtins. 
 * It unsets environment variables sended on arguments.
 *
 * @param data The data structure containing the environment variables.
 * @param cmds An array of strings representing the command arguments.
 */
void	ft_unset(t_data *data, char **cmds)
{
	char	*key;
	int		i;

	i = 0;
	while (cmds[i] != NULL)
	{
		key = cmds[i];
		if (get_env_value(data->env_copy, key) != NULL)
			remove_env_var(data, key);
		if (cmds[i] != NULL)
			i++;
	}
}

/**
 * @brief Function to handle the env builtin: prints 
 * the environment variables stored in the linked list.
 * 
 * @param env The linked list of environment variables.
 * @param flag The flag indicating the format of the output.
 * If flag is 1, the output will be in the format "declare -x key="value"".
 * If flag is 0, the output will be in the format "key=value".
 */
void	ft_env(t_env *env, int flag)
{
	while (env != NULL)
	{
		if (flag == 1)
			ft_printf_fd(1, "declare -x %s=\"%s\"\n", env->key, env->value);
		else
			ft_printf_fd(1, "%s=%s\n", env->key, env->value);
		env = env->next;
	}
}

/**
 * @brief Function to handle the pwd builtin: prints the current 
 * working directory to the standard output. If the environment 
 * variable "PWD" is set, it prints its value. Otherwise, it prints 
 * the value of the "HOME" environment variable.
 *
 * @param data A pointer to the main data structure that contains 
 * the environment variables.
 */
void	ft_pwd(t_data *data)
{
	if (get_env_value(data->env_copy, "PWD") != NULL)
		ft_printf_fd(1, "%s\n", get_env_value(data->env_copy, "PWD"));
	else
		ft_printf_fd(1, "%s\n", get_env_value(data->env_copy, "HOME"));
}
