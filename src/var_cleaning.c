/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_cleaning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 20:31:17 by vkatason          #+#    #+#             */
/*   Updated: 2024/03/23 19:28:57 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to free the var_name structure
 * 
 * @param var: a pointer to the var_name structure.
 */
void	ft_free_var_list(t_list *vars)
{
	t_list		*current;
	t_list		*next;
	t_var_name	*var;

	current = vars;
	while (current != NULL)
	{
		var = (t_var_name *)current->content;
		if (var->name != NULL)
			free(var->name);
		if (var->value != NULL)
			free(var->value);
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}
