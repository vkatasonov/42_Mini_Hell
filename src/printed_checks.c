/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:32:11 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/17 18:07:55 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief This function prints the variables from the list
 * of expandable variables found in the user input string.
 * Used in the debugging process.
 * 
 * @param vars 
 * @var current The pointer to the list that tracks
 * current node in the list
 * @var var The structure that holds the variable name
 */
void	ft_print_vars(t_list *vars)
{
	t_list		*current;
	t_var_name	*var;

	current = vars;
	while (current != NULL)
	{
		var = (t_var_name *)current->content;
		ft_printf("Variable: %s\n", var->name);
		ft_printf("Value: %s\n", var->value);
		ft_printf("Start: %d\n", var->start);
		ft_printf("End: %d\n", var->end);
		current = current->next;
	}
	ft_printf("-------- End of variable list --------\n");
	ft_free_var_list(vars);
}

/**
 * @brief Function to print the variables from the env_copy list.
 * Used in the debugging process.
 * @var tmp The pointer to the current node in the list
 * @param data Main data structure
 */
void	print_env_vars(t_data *data)
{
	t_env	*tmp;

	tmp = data->env_copy;
	while (tmp != NULL)
	{
		ft_printf("Key: %s, Value: %s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
