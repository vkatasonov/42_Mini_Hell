/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:09:15 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/01/11 16:47:07 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function used to print an exit.
 */
void	print_exit(void)
{
	ft_printf("%s%s%s\n", CYAN, "Goodbye!", RST);
}

/**
 * @brief Function to print a minishell header.
 */
void	print_header(void)
{
	ft_printf(RED "*************************************************\n" RST);
	ft_printf(RED "*   _ _ _     _                      _          *\n" RST);
	ft_printf(RED "*  | | | |___| |___ ___ _____ ___   | |_ ___    *\n" RST);
	ft_printf(RED "*  | | | | -_| |  _| . |     | -_|  |  _| . |   *\n" RST);
	ft_printf(RED "*  |_____|___|_|___|___|_|_|_|___|  |_| |___|   *\n" RST);
	ft_printf(RED "*                                               *\n" RST);
	ft_printf(RED "*                                               *\n" RST);
	ft_printf(RED "*         _____ _     _    __ __     _ _        *\n" RST);
	ft_printf(RED "*        |     |_|___|_|  |  |  |___| | |       *\n" RST);
	ft_printf(RED "*        | | | | |   | |  |     | -_| | |       *\n" RST);
	ft_printf(RED "*        |_|_|_|_|_|_|_|  |__|__|___|_|_|       *\n" RST);
	ft_printf(RED "*                                               *\n" RST);
	ft_printf(RED "*************************************************\n" RST);
}
