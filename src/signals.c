/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:27:25 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/03/23 19:26:32 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Function to suppress the output like (CTRL + C) or (CTRL + D)
 */
void	suppress_output(void)
{
	struct termios	termios_p;

	if (isatty(0))
	{
		if (tcgetattr(0, &termios_p) != 0)
			perror("Minishell: tcgetattr");
		termios_p.c_lflag &= ~ECHOCTL;
		if (tcsetattr(0, 0, &termios_p) != 0)
			perror("Minishell: tcsetattr");
	}
}

/**
 * @brief Funtion to handle the sigint
 *
 * @param sig: signal
 */
void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/**
 * @brief Funtion to handle the sigquit
 *
 * @param sig: signal
 */
void	handle_sigquit(int sig)
{
	if (sig == SIGQUIT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
