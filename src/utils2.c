/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:12:22 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/02 22:59:46 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to free a cmd structure
 * 
 * @param cmd: a pointer to the cmd structure.
 */
void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->args)
	{
		while (cmd->args[i])
			free(cmd->args[i++]);
		free(cmd->args);
	}
	if (cmd->redir)
		free_redir(cmd->redir);
	free(cmd);
}

/**
 * @brief Function to free a data structure
 * 
 * @param data: a pointer to the data structure.
 */
void	free_data(t_data *data)
{
	if (data->tkns)
	{
		ft_free_tkn_lst(data->tkns);
		data->tkns = NULL;
	}
	if (data->cmd)
	{
		free_cmd(data->cmd);
		data->cmd = NULL;
	}
	if (data->env_copy)
	{
		free_env(data->env_copy);
		data->env_copy = NULL;
	}
	data = NULL;
}

/**
 * @brief function to duplicate a string constant
 * 
 * @param s: a pointer to the string.
 * @return char*
 */
char	*ft_strdup_const(const char *s)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup)
	{
		ft_memcpy(dup, s, len);
		dup[len] = '\0';
	}
	return (dup);
}

/**
 * @brief function to duplicate a string by n bytes
 * 
 * @param s: a pointer to the string.
 * @return char*
 */
char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*dup;

	len = ft_strlen(s);
	if (n > len)
		n = len;
	dup = malloc(n + 1);
	if (dup)
	{
		ft_memcpy(dup, s, n);
		dup[n] = '\0';
	}
	return (dup);
}

/**
 * @brief function to check if a string is a number
 * 
 * @param str: a pointer to the string.
 * @return int
 */
int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (!str[i])
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
