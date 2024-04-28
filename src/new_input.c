/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:41:44 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/03 13:18:16 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to check if 
 * the first characters in 
 * the string are spaces
 * 
 * @param str The string to check
 * @var i Position counter 
 * @return int Index of the first non-space character
 */
static int	ft_skip_first_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' '))
		i++;
	return (i);
}

/**
 * @brief Function to get a chunk of the string
 * to copy it then to the new string
 * 
 * @param usr_input The user input string
 * @param start The start index of the chunk
 * @param end The end index of the chunk
 * @var i Position counter
 * @var input_chunk The chunk we need to return
 * @return char* The chunk of the string
 */
static char	*ft_get_input_chunck(char *usr_input, int start, int end)
{
	char	*input_chunk;
	int		i;

	i = 0;
	input_chunk = (char *)malloc(sizeof(char) * (end - start + 1));
	while (start < end)
	{
		input_chunk[i] = usr_input[start];
		i++;
		start++;
	}
	input_chunk[i] = '\0';
	return (input_chunk);
}

/**
 * @brief Helper function for ft_get_new_input
 * that copies the chunk of the string if
 * the variable is not at the start of the string.
 * See params description in ft_get_new_input
 */
static void	ft_copy_text_chunk(int *i, t_var_name *var, char *usr_input,
		t_data *data)
{
	char	*input_chunk;
	char	*temp;

	if (*i != var->start)
	{
		input_chunk = ft_get_input_chunck(usr_input, *i, var->start);
		temp = ft_strjoin(data->input_copy, input_chunk);
		free(data->input_copy);
		data->input_copy = temp;
		*i = var->start;
		free(input_chunk);
	}
}

/**
 * @brief Helper function for ft_get_new_input
 * that copies the value of the variable if
 * the variable is at the start of the string
 * and changes position counter and replace 
 * the value of the varuable that has 
 * var->value == NULL with an empty string. 
 * See params description in ft_get_new_input 
 */
static void	ft_copy_var_value(int *i, t_var_name *var, t_data *data,
		t_list *tmp)
{
	char	*input_chunk;
	char	*temp;

	if (*i == var->start || tmp->next == NULL)
	{
		if (var->value != NULL)
		{
			temp = ft_strjoin(data->input_copy, var->value);
			free(data->input_copy);
			data->input_copy = temp;
			*i = var->end + 1;
		}
		else
		{
			input_chunk = ft_strdup("");
			temp = ft_strjoin(data->input_copy, input_chunk);
			free(data->input_copy);
			data->input_copy = temp;
			*i = var->end + 1;
			free(input_chunk);
		}
	}
}

/**
 * @brief Function to get the new input string
 * 
 * @param usr_input The user input string
 * @param data The main data structure that
 * contains the new input string and the copy
 * of the environment variables.
 * @var i Input string position counter
 * @var var_list The list of variables.
 * @var tmp The pointer to the current node in the list
 * @var var The structure that holds the variable name,
 * it's position in the string and value.
 */
void	ft_get_new_input(char *usr_input, t_data *data)
{
	int			i;
	t_list		*var_list;
	t_list		*tmp;
	t_var_name	*var;

	i = ft_skip_first_spaces(usr_input);
	var_list = ft_fill_values(usr_input, data);
	data->input_copy = ft_strdup("");
	tmp = var_list;
	while (tmp != NULL && usr_input[i] != '\0')
	{
		var = (t_var_name *)tmp->content;
		ft_copy_text_chunk(&i, var, usr_input, data);
		ft_copy_var_value(&i, var, data, tmp);
		tmp = tmp->next;
	}
	if (usr_input[i] != '\0')
		data->input_copy = ft_strjoin_free(data->input_copy,
				ft_get_input_chunck(usr_input, i, ft_strlen(usr_input)));
	ft_free_var_list(var_list);
}
