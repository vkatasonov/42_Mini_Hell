/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_value_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:21:48 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/02 22:49:58 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 				Toggles the status based on 
 * 						the character in the user input.
 * 	
 * @param usr_input 	user input string
 * @param i 			index of the character to check
 * @param status 		status array to toggle based on the character
 * 						(0) - double quotes
 * 						(1) - single quotes
 */
static void	ft_toggle_status(char *usr_input, int i, int *status)
{
	if (usr_input[i] == '\"')
		status[0] = (status[0] + 1) % 2;
	if (usr_input[i] == '\'')
		status[1] = (status[1] + 1) % 2;
}


/**
 * @brief 				Function checks if the character is expandable
 * 						based on the status of the double and single quotes.
 * 	
 * @param c 			Character to check
 * @param status 		Integer array of size 2
 * 						(0) - double quotes
 * 						(1) - single quotes
 * @return int 			1 if the character is expandable, 0 if not
 */
static int	ft_is_expandable(char c, int status[2])
{
	return (((c == '$' && (status[0] == 0 && status[1] == 0)) || (c == '$'
				&& (status[0] == 1 && status[1] == 1)) || (c == '$'
				&& (status[0] == 1 && status[1] == 0))));
}

/**
 * @brief 				Function to get the expandable name
 * 						from the user input.
 * @param usr_input 	User input string
 * @param i 			Index of the character to start from
 * @var start 			Start index of the expandable variable
 * @return char* 		Name of the expandable variable
 */
static char	*ft_get_expandable_name(char *usr_input, int *i)
{
	int	start;
	int	second_pos;

	second_pos = *i + 1;
	start = (*i)++;
	while (usr_input[*i] && (ft_isalnum(usr_input[*i]) || usr_input[*i] == '_'
			|| usr_input[second_pos] == '?'))
	{
		if (usr_input[second_pos] == '?')
		{
			(*i)++;
			break ;
		}
		(*i)++;
	}
	return (ft_substr(usr_input, start + 1, *i - start - 1));
}

/**
 * @brief 				Function to create a new variable name
 * 
 * @param usr_input 	The user input string
 * @param i 			Index of the character to start from
 * @return t_var_name* 	Structure to handle the variable names
 */
t_var_name	*ft_create_var(char *usr_input, int *i)
{
	t_var_name	*var;

	var = malloc(sizeof(t_var_name));
	if (!var)
		return (NULL);
	var->start = *i;
	var->name = ft_get_expandable_name(usr_input, i);
	var->end = *i - 1;
	var->pos = *i;
	var->value = NULL;
	return (var);
}

/**
 * @brief 				Function to get the list of expandable 
 * 						variable names from the user input.
 * 
 * @param usr_input 	User input string
 * @var i 				Index of the character to start from
 * @var status 			Flag to check the status of the 
 * 						double and single quotes:
 * 						(0) - double quotes
 * 						(1) - single quotes
 * @var vars 			List of expandable variable names
 * @var var 			Structure to handle the variable names
 * 						and their positions
 * @return t_list* 		List of expandable variable names
 */
t_list	*ft_var_name(char *usr_input)
{
	int			i;
	int			status[2];
	t_list		*vars;
	t_var_name	*var;

	i = 0;
	status[0] = 0;
	status[1] = 0;
	vars = NULL;
	while (usr_input[i])
	{
		ft_toggle_status(usr_input, i, status);
		if (ft_is_expandable(usr_input[i], status))
		{
			var = ft_create_var(usr_input, &i);
			if (!var)
				return (NULL);
			ft_lstadd_back(&vars, ft_lstnew(var));
		}
		else
			i++;
	}
	return (vars);
}
