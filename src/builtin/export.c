/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:31:30 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/02 19:41:43 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * @brief Function checks if a given of variable name is valid.
 *
 * @param name The name to be checked.
 * @return 0 if the name is valid, 1 otherwise.
 * @var i The index of the name string.
 * Helper function for the `handle_export` function.
 */
int	check_name(char *name)
{
	int	i;

	i = 0;
	if (!ft_isalpha(name[i]) && name[i] != '_')
		return (1);
	i++;
	while (name[i] != '\0')
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Function trims leading and trailing spaces from a given string.
 * Helper function for the `handle_export_null_equal_sign` function.
 *
 * @param str The string to trim.
 * @return A new string with leading and trailing spaces removed.
 * @var end The end of the string.
 */
char	*trim_spaces(const char *str)
{
	const char	*end;

	end = str + ft_strlen(str) - 1;
	while (ft_isspace((unsigned char)*str))
		str++;
	if (*str == 0)
		return (ft_strdup_const(str));
	while (end > str && ft_isspace((unsigned char)*end))
		end--;
	return (ft_strndup(str, end - str + 1));
}

/**
 * @brief The function is responsible for handling the export command 
 * when there is a null equal sign or a space before the equal sign.
 * It takes a pointer to a structure `t_export_args` as a parameter, 
 * which contains the necessary arguments for the export command.
 * If the equal sign is NULL, it trims the spaces from the command 
 * at the current index and sets the key to the trimmed command 
 * and the value to NULL. If there is no space before the equal sign, 
 * it trims the spaces from the command at the current index, 
 * sets the key to the trimmed command, and sets the value to the trimmed
 * command after the equal sign. If there is a space before the equal sign, 
 * it frees the memory allocated for the command copy, 
 * increments the index, and goes back to the caller function.
 * 
 * @param args A pointer to a structure `t_export_args` containing the necessary 
 * arguments for the export command.
 * 
 * Helper function for the `handle_export` function.
 */
void	handle_export_null_equal_sign(t_export_args *args)
{
	if (args->equal_sign == NULL)
	{
		args->key = trim_spaces(args->cmds[args->i]);
		args->value = NULL;
	}
	else if (*(args->equal_sign - 1) != ' ')
	{
		*args->equal_sign = '\0';
		args->key = trim_spaces(args->cmds[args->i]);
		args->value = trim_spaces(args->equal_sign + 1);
	}
	else
	{
		free(args->cmd_copy);
		args->i++;
		return ;
	}
}

/**
 * @brief Handles the export built-in command.
 * 
 * Helper function for the `ft_export` function.
 * Taking a pointer to the main data structure 
 * and a pointer to the export arguments structure, 
 * this function checks if the export key is valid
 * and if it already exists in the environment.
 * 
 * If so it updates the value in the environment.
 * If the key is valid but does not exist, 
 * it adds a new environment variable.
 * The function also frees memory allocated 
 * for the arguments and updates the exit status.
 *
 * @param data The main data structure containing program information.
 * @param args The export arguments structure containing the key and value to export.
 * @return 0 if the export was successful, 1 otherwise.
 */
int	handle_export(t_data *data, t_export_args *args)
{
	handle_export_null_equal_sign(args);
	if (args->key == NULL || check_name(args->key))
	{
		free(args->key);
		free(args->value);
		free(args->cmd_copy);
		data->exit_status = 1;
		return (1);
	}
	if (get_env_value(data->env_copy, args->key) != NULL)
		change_value_env(data, args->key, args->value);
	else
		add_env_var(data, args->key, args->value);
	if (args->value != NULL)
		free(args->value);
	if (args->key != NULL)
		free(args->key);
	free(args->cmd_copy);
	return (0);
}

/**
 * @brief Exports environment variables or 
 * displays the current environment.
 * If no arguments are provided, 
 * it displays the current environment. 
 * If arguments are provided, 
 * it exports the specified environment
 * variables.
 *
 * @param data The data structure containing the environment variables.
 * @param cmds The array of command arguments.
 */
void	ft_export(t_data *data, char **cmds)
{
	int				i;
	t_export_args	args;

	i = 1;
	if (cmds[1] == NULL)
		ft_env(data->env_copy, 1);
	else
	{
		while (cmds[i] != NULL)
		{
			args.cmd_copy = ft_strdup_const(cmds[i]);
			args.equal_sign = ft_strchr(cmds[i], '=');
			args.cmds = cmds;
			args.i = i;
			if (handle_export(data, &args) == 1)
				return ;
			i++;
		}
	}
}
