/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tkns.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:27:36 by vkatason          #+#    #+#             */
/*   Updated: 2024/04/01 18:30:07 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 			Initializes a token with the given type and value.
 * 					This function allocates memory for a new token, 
 * 					sets its type and value,
 * 					and returns a pointer to the created token.
 *
 * @param type 		The type of the token.
 * @param value 	The value of the token.
 * @return 			A pointer to the created token.
 */
t_tkn	*ft_init_tkn(int type, char *value)
{
	t_tkn	*tkn;

	tkn = ft_calloc(1, sizeof(t_tkn));
	if (tkn == NULL)
	{
		ft_putstr_fd("Error: Failed to allocate memory for token\n", 2);
		exit(EXIT_FAILURE);
	}
	tkn->e_type = type;
	if (value && value[strlen(value)] == '\0')
		tkn->value = ft_strdup(value);
	else
	{
		ft_putstr_fd("Error: Value is not null-terminated\n", 2);
		exit(EXIT_FAILURE);
	}
	tkn->order = ft_reset_tkn_order(0);
	return (tkn);
}

/**
 * @brief 			Adds a token to the token list.
 *	
 * @param head 		The head of the token list.
 * @param tkn 		The token to be added.
 * @return 			The updated head of the token list.
 */
t_tkn_lst	*ft_add_tkn_to_lst(t_tkn_lst *head, t_tkn *tkn)
{
	t_tkn_lst	*new_lst_node;
	t_tkn_lst	*current;

	if (tkn == NULL)
	{
		ft_putstr_fd("Error: Null token\n", 2);
		return (head);
	}
	new_lst_node = malloc(sizeof(t_tkn_lst));
	if (new_lst_node == NULL)
	{
		ft_putstr_fd("Error: Failed to allocate memory for token_list\n", 2);
		exit(EXIT_FAILURE);
	}
	new_lst_node->tkn = tkn;
	new_lst_node->next = NULL;
	new_lst_node->prev = NULL;
	if (head == NULL)
		return (new_lst_node);
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = new_lst_node;
	new_lst_node->prev = current;
	return (head);
}

/**
 * @brief 			Tokenizes the input string and stores 
 * 					the tokens in a token list in the data structure.
 *
 * @param input 	The input string.
 * @param data 		The main data structure.
 */
void	ft_tknize_input(t_data *data)
{
	t_lexer	*lexer;
	t_tkn	*tkn;

	if (data->tkns != NULL)
	{
		ft_free_tkn_lst(data->tkns);
		data->tkns = NULL;
	}
	lexer = ft_init_lexer(data->input_copy);
	data->tkns = NULL;
	while (1)
	{
		tkn = ft_lexer_get_next_token(lexer);
		if (tkn == NULL)
			break ;
		data->tkns = ft_add_tkn_to_lst(data->tkns, tkn);
	}
	ft_free_lexer(lexer);
}

/**
 * @brief 		The function that frees the token list.
 * 
 * @param head 	The head of the token list. 
 */
void	ft_free_tkn_lst(t_tkn_lst *head)
{
	t_tkn_lst	*current;
	t_tkn_lst	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		if (current->tkn != NULL)
		{
			if (current->tkn->value != NULL)
			{
				free(current->tkn->value);
				current->tkn->value = NULL;
			}
			free(current->tkn);
			current->tkn = NULL;
		}
		free(current);
		current = next;
		if (current != NULL)
			current->prev = NULL;
	}
	ft_reset_tkn_order(1);
}

/**
 * @brief			Frees the memory allocated for a lexer object.
 * 
 * @param lexer 	The lexer object to be freed.
 */
void	ft_free_lexer(t_lexer *lexer)
{
	if (lexer->input != NULL)
	{
		free(lexer->input);
		lexer->input = NULL;
	}
	free(lexer);
	lexer = NULL;
}
