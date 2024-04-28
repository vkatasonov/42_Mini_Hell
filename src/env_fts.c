/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 16:18:21 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/02 19:34:22 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 			Function to change the value of an enviroment variable
 * 	
 * @param data 		The pointer to the data structure.
 * @param key 		The pointer to the key.
 * @param value 	The pointer to the value.
 * @var temp 		The pointer to the enviroment variable.
 * @var to_free 	The pointer to the value to free.
 */
void	change_value_env(t_data *data, char *key, char *value)
{
	t_env	*temp;
	char	*to_free;

	to_free = NULL;
	temp = data->env_copy;
	while (temp != NULL)
	{
		if (!ft_strncmp(temp->key, key, ft_strlen(key) + 1))
		{
			if (!value)
				to_free = ft_strdup("");
			to_free = ft_strdup(value);
			if (temp->value)
				free(temp->value);
			temp->value = to_free;
			return ;
		}
		temp = temp->next;
	}
}

/**
 * @brief 			Function to remove a enviromental variable
 * 	
 * @param data 		The pointer to the data structure.
 * @param key		The pointer to the key.
 * @var current		The pointer to the current enviromental variable.
 * @var prev		The pointer to the previous enviromental variable.
 * @note			The function will remove the enviromental variable
 * 					from the copy of the enviromental variables.
 */
void	remove_env_var(t_data *data, char *key)
{
	t_env	*current;
	t_env	*prev;

	current = data->env_copy;
	prev = NULL;
	while (current != NULL)
	{
		if (!ft_strncmp(current->key, key, ft_strlen(key)))
		{
			if (prev == NULL)
				data->env_copy = current->next;
			else
				prev->next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

/**
 * @brief 			Function to add a enviromental variable
 * 	
 * @param data 		The pointer to the data structure.
 * @param key 		The pointer to the key.
 * @param value 	The pointer to the value.
 * @var env_v		An auxiliar pointer that will get
 * 					join the key + '=' + value.
 * @var key_copy	An auxiliar pointer that get
 * 					the copy of the key.
 * @var value_copy	An auxiliar pointer that get
 * 					the copy of the value.
 * @var aux			An auxiliar pointer that get
 * 					the copy of the 'key=value'.
 * @var temp		An auxiliar pointer that get
 * 					the copy of '=' value.
 * 
 * @note			The function will add the enviromental variable
 * 					to the copy of the enviromental variables freeing
 * 					the memory of the key and value.
 */
void	add_env_var(t_data *data, char *key, char *value)
{
	char	*env_v;
	char	*key_copy;
	char	*value_copy;
	char	*aux;
	char	*temp;

	temp = ft_strdup("=");
	if (!value)
		value = "";
	key_copy = ft_strdup(key);
	value_copy = ft_strdup(value);
	env_v = ft_strjoin_free(key_copy, temp);
	aux = ft_strjoin_free(env_v, value_copy);
	data->env_copy = ft_env_lst_add_back(data, aux);
	free(aux);
}

/**
 * @brief 			Function to convert the enviromental variables
 * 					into a double char pointer.
 * 
 * @param env 		The pointer to the enviromental variables.
 * @var env_cpy		The double char pointer that will contain
 * 					the enviromental variables.
 * @var temp		Temporary pointer to the enviromental variable.
 * @var i			Counter.
 * @return 			The double char pointer that contain
 * 					the enviromental variables.
 * 
 * @note			The function will allocate memory for the double char pointer
 * 					and the caller is responsible for freeing it.
 */
char	**ft_env_to_char(t_env *env)
{
	char	**env_cpy;
	t_env	*temp;
	int		i;

	i = 0;
	temp = env;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	env_cpy = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	temp = env;
	while (temp != NULL)
	{
		env_cpy[i] = ft_strjoin(temp->key, "=");
		env_cpy[i] = ft_strjoin_free(env_cpy[i], ft_strdup(temp->value));
		i++;
		temp = temp->next;
	}
	env_cpy[i] = NULL;
	return (env_cpy);
}
