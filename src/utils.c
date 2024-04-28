/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:25:15 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/02 19:49:25 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to free a 2d array
 * 
 * @param split: a pointer to the 2d array.
 */
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/**
 * @brief Function to free a 2d array
 * 
 * @param dest: a pointer to the 2d array.
 * @param i: an integer that represent the number of elements.
 */
void	free_dest(char **dest, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(dest[j++]);
	free(dest);
}

/**
 * @brief Function to duplicate a 2d array
 * 
 * @param src: a pointer to the 2d array.
 * @return char** 
 */
char	**strdup_2d(char **src)
{
	int		i;
	int		len;
	char	**dst;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	dst = malloc(sizeof(char *) * (len + 1));
	if (!dst)
		return (NULL);
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		if (!dst[i])
		{
			free_dest(dst, i);
			return (NULL);
		}
		i++;
	}
	dst[i] = NULL;
	return (dst);
}

/**
 * @brief Function to free a redirect structure
 * 
 * @param redir: a pointer to the redirect structure.
 */
void	free_redir(t_redirect *redir)
{
	t_redirect	*tmp;

	while (redir)
	{
		tmp = redir;
		redir = redir->next;
		free(tmp->file);
		free(tmp->redir_type);
		free(tmp);
	}
}

/**
 * @brief Function to free a env structure
 * 
 * @param env: a pointer to the env structure.
 */
void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}
