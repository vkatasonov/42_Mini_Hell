/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:45:41 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/03 19:05:33 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief 			Function to check exit status and return value
 * 
 * @param data: 	a pointer to the data structure.
 * @return int 		Exit status or first command argument.
 */
int	check_exit(t_data *data)
{
	if (data->cmd == NULL)
		return (0);
	if (data->cmd->args[1] != NULL)
	{
		if (ft_isnumber(data->cmd->args[1]) == 0)
		{
			ft_putstr_fd("exit: ", 2);
			ft_putstr_fd(data->cmd->args[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			return (255);
		}
		else
			return (ft_atoi(data->cmd->args[1]));
	}
	else
		return (data->exit_status);
}

/**
 * @brief 		Function to get the process ID (PID) 
 * 				using `fork()` and `waitpid()`.
 * 				The PID of the child process is stored 
 * 				in the `data` structure.
 * 
 * @param data 	A pointer to the `t_data` structure.
 */
void	ft_getpid(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putstr_fd("Error in fork\n", 2);
		exit(1);
	}
	if (!pid)
		exit(1);
	waitpid(pid, NULL, 0);
	data->pid = pid - 1;
}

/**
 * @brief 		Function to inits main data structure
 * 				and check arguments count
 */
int	ft_init(t_data *data, int ac, char **av, char **env)
{
	char	**env_temp;

	(void)av;
	env_temp = strdup_2d(env);
	if (ac > 1)
	{
		ft_putstr_fd("The program no needs any argument\n", 2);
		return (1);
	}
	print_header();
	data->env_copy = NULL;
	data->input_copy = NULL;
	data->exit_status = 0;
	data->tkns = NULL;
	data->cmd = NULL;
	data->fd[1] = dup(1);
	data->fd[0] = dup(0);
	ft_getpid(data);
	ft_get_env_cpy(data, env_temp);
	free_split(env_temp);
	return (0);
}

/**
 * @brief 			Function that prompts the user for input 
 * 					and reads the input using the readline function.
 * 					If the user input is NULL, it sets the data's 
 * 					cmd to NULL, prints "exit", and returns 1.
 * 					Otherwise, it adds the user input to the history, 
 * 					parses the input using `ft_parser`,
 * 					frees the user input, and executes the pipeline 
 * 					if the cmd is not NULL.
 * 					If the cmd is not NULL and the first argument 
 * 					is "exit", it returns 1.
 * 					Finally, it frees the cmd and returns 0.
 * 
 * @param data 		A pointer to the main data structure.
 * 
 * @return int 		1 if the user input is NULL 
 * 					or the first argument is "exit", 0 otherwise.
 */
int	get_prompt(t_data *data)
{
	char	*usr_input;

	if (!data)
		return (-1);
	usr_input = readline("\033[1;31mMiniHell: \033[0m");
	if (usr_input == NULL)
	{
		data->cmd = NULL;
		ft_printf("exit\n");
		return (1);
	}
	add_history(usr_input);
	ft_parser(usr_input, data);
	free(usr_input);
	if (data->cmd)
		execute_pipeline(data);
	if (data->cmd && data->cmd->args && !ft_strncmp("exit",
			data->cmd->args[0], 5))
		return (1);
	ft_free_cmd(data->cmd);
	return (0);
}

/**
 * @brief 		Main function of the minishell program.
 * 
 * @param ac 	Argument count.	
 * @param av 	Array of arguments.
 * @param env 	Array of enviromental variables.
 * 
 * @return int  0 if the program runs successfully.
 */
int	main(int ac, char **av, char **env)
{
	t_data	data;
	int		exit_status;

	if (ft_init(&data, ac, av, env) == 1)
		return (0);
	while (1)
	{
		suppress_output();
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		if (get_prompt(&data) == 1)
			break ;
	}
	exit_status = check_exit(&data);
	free_data(&data);
	rl_clear_history();
	print_exit();
	exit(exit_status);
}
