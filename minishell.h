/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:39:42 by mzea-mor          #+#    #+#             */
/*   Updated: 2024/04/03 18:59:31 by mzea-mor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

/*
** ASCII colors escape sequences for printf
** Usage:
** 		ft_printf(RED "Red bold text" RST);
**		ft_printf(B "Bold text goes here" RST);
*/
# define RST "\033[0m"        /* Reset to default color */
# define BU "\033[1;4;0m"     /* Bold and underlined text*/
# define B "\033[1m"          /* Bold text default color */
# define U "\033[4m"          /* Underlined text default color */
# define RED "\033[1;31m"     /* Bold Red*/
# define GREEN "\033[1;32m"   /* Bold Green */
# define YELLOW "\033[1;33m"  /* Bold Yellow */
# define BLUE "\033[1;34m"    /* Bold Blue */
# define MAGENTA "\033[1;35m" /* Bold Magenta */
# define CYAN "\033[1;36m"    /* Bold Cyan */
# define WHITE "\033[1;37m"   /* Bold White */

/**
 * @brief The following defines are used to identify the type of redirection
 */

# define CMND_NOT_FOUND 1
# define CMND_NOT_EXEC 2
# define CMND_NOT_DIR 3
# define CMND_NOT_FILE 4
# define CMND_NOT_PERM 5
# define PERMISION_DENIED 6
# define CMND_NOT_MEM 7
# define CMND_NOT_ARG 8
# define CMND_NOT_PIPE 9
# define CMND_NOT_FORK 10
# define INPUT_QUOTES_ERROR 11
# define SYNTAX_ERROR 12
# define SYNTAX_ERROR_UNEXPECTED 13
# define UNEXPECTED_TOKEN 14

/*
 * The following defines are used to identify the type of error
 */

# define STDIN 0
# define STDOUT 1
# define STDERR 2

/**
 * @brief The following defines are used
 * to identify the type of exit status
 */

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define EXIT_NOT_FOUND 127
# define EXIT_SYNTAX_ERROR 258

/*----- STRUCTURES -----*/

/**
 * @brief Structure to handle the enviroment variables
 *
 * @param key The key of the variable
 * @param value The value of the variable
 */
typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

/**
 * @brief Structure representing a token in the minishell program.
 *
 * @param e_type The type of the token
 * @param TKN_PIPE Pipe symbol (|)
 * @param TKN_REDIR_IN Redirection input symbol (<)
 * @param TKN_REDIR_OUT Redirection output symbol (>)
 * @param TKN_REDIR_APPEND Redirection append symbol (>>)
 * @param TKN_REDIR_HERE_DOC Redirection here doc symbol (<<)
 * @param TKN_WORD Everything that is not a special character
 * @param TKN_STRING All that inside the quotes with quotes
 * @param TKN_ERROR 3 and more consecutive >, < and more than 2 |
 * @param value The value of the token
 * @param order The order of the token (e.g. 1, 2, 3, ...)
 */
typedef struct s_tkn
{
	enum
	{
		TKN_PIPE,
		TKN_REDIR_IN,
		TKN_REDIR_OUT,
		TKN_REDIR_APPEND,
		TKN_REDIR_HERE_DOC,
		TKN_WORD,
		TKN_STRING,
		TKN_ERROR
	} e_type;
	char				*value;
	int					order;
}						t_tkn;

/**
 * @brief Structure to handle the lexer
 *
 * @param c The current character
 * @param i The index of the current character
 * @param input The input string
 */
typedef struct s_lexer
{
	unsigned char		c;
	unsigned int		i;
	char				*input;
}						t_lexer;

/**
 * @brief Structure to handle the token list
 *
 * @param tkn The token
 * @param next The next token
 */
typedef struct s_tkn_lst
{
	t_tkn				*tkn;
	struct s_tkn_lst	*next;
	struct s_tkn_lst	*prev;
}						t_tkn_lst;

/**
 * @brief Structure to handle the export arguments
 *
 * @param cmds The commands
 * @param cmd_copy The copy of the command
 * @param equal_sign The equal sign
 * @param i The index
 * @param key The key
 * @param value The value
 */
typedef struct s_export_args
{
	char				**cmds;
	char				*cmd_copy;
	char				*equal_sign;
	int					i;
	char				*key;
	char				*value;
}						t_export_args;

/**
 * @brief Struct to handle the redirections
 * @param file The file to redirect
 * @param redir_type The type of redirection:
 * ">>" to append,
 * ">" to overwrite,
 * "<" to read from file
 * "<<" to read from a heredoc
 * @param next The next redirection
 */
typedef struct s_redirect
{
	char				*file;
	char				*redir_type;
	struct s_redirect	*next;
}						t_redirect;

/**
 * @brief Structure to handle the commands
 * @param args The arguments of the command
 * where the very first argument is the command itself
 * and the rest are the arguments
 * @param flag_redir The flag to check if
 * the command has a redirection
 * @param fd The file descriptor for the pipe
 * that will be used to pass the output of the
 * previous command to the input of the next command
 * @param redir The redirection
 * @param redir_count The redirection direction
 * where 0 is input and 1 is output
 * @param save The save dup. It duplicates stdin
 * and saves it's value.
 * @param next The next cmd structure
 */
typedef struct s_cmd
{
	char				**args;
	int					flag_redir;
	int					fd[2];
	t_redirect			*redir;
	int					redir_count[2];
	int					save;
	struct s_cmd		*next;
}						t_cmd;

/**
 * @brief Structure to handle the execution of commands
 *
 * @param input The input file descriptor
 * @param output The output file descriptor
 * @param cmd The command to execute
 * @param save The save dup
 * @param pipefd The pipe file descriptors
 */
typedef struct s_exec_cmd
{
	int					input;
	int					output;
	t_cmd				*cmd;
	int					pipefd[2];
}						t_exec_cmd;

/**
 * @brief Structure to handle the pipeline arguments
 *
 * @param in The input file descriptor
 * @param pipefd The pipe file descriptors
 * @param cmd The command to execute
 */
typedef struct s_pipeline_args
{
	int					*in;
	int					pipefd[2];
	t_cmd				**cmd;
}						t_pipeline_args;

/**
 * @brief Structure to handle the data
 *
 * @param env_copy The current copy of enviroment variables
 * @param input_copy The clean copy of the user input with
 * the enviroment variables expanded
 * @param cmd The list of parsed commands
 * @param token The token list
 * @param pid The process id
 */
typedef struct s_data
{
	int					exit_status;
	t_env				*env_copy;
	char				*input_copy;
	t_cmd				*cmd;
	t_tkn_lst			*tkns;
	pid_t				pid;
	int					fd[2];
}						t_data;

/**
 * @brief The structure to handle the variable names
 * during the input scanning
 * @param name The name of the variable
 * @param pos The position of the last character of the variable
 * name in the input
 * @param start The start position of the variable in the input
 * startin with $ from 0
 * @param end The end position of the variable in the input
 */
typedef struct s_var_name
{
	char				*name;
	char				*value;
	int					pos;
	int					start;
	int					end;
}						t_var_name;

/*----- BUILTINS ----*/

void					ft_echo(t_data *data, char **cmds);
void					ft_cd(t_data *data, char **cmds);
void					ft_pwd(t_data *data);
void					ft_export(t_data *data, char **cmds);
void					ft_unset(t_data *data, char **cmds);
void					ft_env(t_env *env, int flag);

/*-----  ENVIRONMENT VARIABLES ----*/

t_env					*ft_env_lst_add_back(t_data *data, char *env);
void					ft_env_lst_last(t_data *data, t_env *env_lst);
t_env					*ft_env_lst_new(t_data *data, char *env);
t_data					*ft_get_env_cpy(t_data *data, char **env);
void					add_env_var(t_data *data, char *key, char *value);
void					remove_env_var(t_data *data, char *key);
void					change_value_env(t_data *data, char *key, char *value);
char					*get_env_value(t_env *env, char *key);
char					**ft_env_to_char(t_env *env);
void					print_env_vars(t_data *data);

/*-----  SIGNALS FUNCTIONS ----*/

void					handle_sigint(int sig);

/*-----  PRINT FUNCTIONS ----*/

void					print_exit(void);
void					print_header(void);

/*-----  EXECUTOR FUNCTIONS ----*/

int						check_builtin(char **cmds);
int						check_builtin_rare(char **cmds);
void					exec_builtin(t_data *data, char **cmds);
void					exec_local(char **cmds, t_env *enviroment,
							t_data *data);
void					ft_do_builtin_rare(t_data *data, char **cmds);

/*-----  PIPES & REDIR FUNCTIONS ----*/

void					execute_pipeline(t_data *data);
void					ft_redir(t_cmd *cmd, int save, int pipefd[2]);
void					ft_check_counts(t_cmd *cmd);
void					ft_case_heredoc(t_cmd *cmd, int save);

/*-----  UTILS FUNCTIONS ----*/

void					ft_error(char *str, int type_error);
void					free_split(char **split);
char					**strdup_2d(char **src);
char					*ft_strdup_const(const char *s);
char					*ft_strndup(const char *s, size_t n);
int						ft_isnumber(char *str);

/*-----  EXECUTOR FUNCTIONS ----*/

int						ft_init(t_data *data, int ac, char **av, char **env);

/*----- INPUT CHECK ----*/

int						ft_is_input_error(char *usr_input, t_data *data);

/*----- VARIABLE SEARCH AND EXPANSION ----*/
t_list					*ft_var_name(char *usr_input);
t_var_name				*ft_create_var(char *usr_input, int *i);
char					*ft_check_vars(t_list *var_list, t_data *data);
t_list					*ft_fill_values(char *usr_input, t_data *data);
void					ft_free_var_list(t_list *vars);
void					ft_print_vars(t_list *vars);
void					ft_get_new_input(char *usr_input, t_data *data);

/*----- LEXER FUNCTIONS -----*/
t_lexer					*ft_init_lexer(char *input);
void					ft_lexer_advance(t_lexer *lexer);
t_tkn					*ft_lexer_advance_with_tkn(t_lexer *lexer, t_tkn *tkn);
char					*ft_lexer_char_to_str(t_lexer *lexer);
t_tkn					*ft_lexer_get_next_token(t_lexer *lexer);
char					*ft_lexer_process_chars(t_lexer *lexer, char *value);
t_tkn					*ft_lexer_get_string(t_lexer *lexer);
char					*ft_get_string_without_order(t_lexer *lexer);
t_tkn					*ft_lexer_get_word(t_lexer *lexer);
char					*ft_get_value(t_lexer *lexer, char *value, char *tmp,
							char prev_c);
t_tkn					*ft_init_tkn(int type, char *value);
int						ft_count_the_same(t_lexer *lexer, char symbol);
char					*ft_str_repeat(char c, int count);
int						ft_reset_tkn_order(int reset);
t_tkn_lst				*ft_add_tkn_to_lst(t_tkn_lst *head, t_tkn *tkn);
void					ft_tknize_input(t_data *data);
void					ft_print_tkn(t_tkn *tkn);
void					ft_print_tkn_lst(t_data *data);
t_tkn					*ft_handle_quotes(t_lexer *lexer);
void					ft_handle_greater_than_helper(t_lexer *lexer,
							char *value, t_tkn **tkn);
t_tkn					*ft_handle_greater_than(t_lexer *lexer);
void					ft_handle_less_than_helper(t_lexer	*lexer,
							char *value, t_tkn **tkn);
t_tkn					*ft_handle_less_than(t_lexer *lexer);
t_tkn					*ft_handle_pipe(t_lexer *lexer);
void					ft_handle_whitespace(t_lexer *lexer);
int						ft_check_tkn_errors(t_data *data, t_tkn_lst *tkn_lst);

/*---- PARSING & CMD CREATION FUNCTIONS/ -----*/

void					ft_parser(char *usr_input, t_data *data);
t_redirect				*ft_init_redir(void);
void					ft_free_redir(t_redirect *redir);
t_cmd					*ft_init_cmd(void);
void					ft_handle_tkn_type(t_tkn *tkn, t_tkn_lst **tkn_lst,
							t_cmd **tmp, t_data *data);
void					ft_tkns_to_cmds(t_data *data);
int						ft_tkn_lst_last(t_tkn_lst *tkn_lst);
void					ft_print_cmds(t_data *data);
void					ft_print_single_cmd(t_cmd *cmd, int i);
void					ft_print_redirections(t_redirect *redir);
int						ft_tkns_error_exit(t_data *data);
int						ft_valid_pipe(t_tkn_lst *tkns, t_data *data);
int						ft_valid_redir(t_tkn_lst *tkns, t_data *data);
void					ft_add_arg_to_cmd(t_cmd *cmd, t_tkn_lst **tkn_lst);
t_redirect				*ft_make_new_redir(t_cmd *cmd);
int						ft_add_redir_to_cmd(t_data *data, t_cmd *cmd,
							t_tkn_lst **tkns_lst);
void					ft_realloc_args(t_cmd *cmd, char *new_arg);

/*----- CLEANING FUNCTIONS ----*/
void					ft_free_var_list(t_list *vars);
void					ft_free_lexer(t_lexer *lexer);
void					ft_free_tkn_lst(t_tkn_lst *head);
void					free_data(t_data *data);
void					free_env(t_env *env);
void					free_cmd(t_cmd *cmd);
void					ft_free_cmd(t_cmd *cmd);
void					free_redir(t_redirect *redir);
void					ft_free_redir(t_redirect *redir);
void					free_cd(char *pwd_old, char *pwd_new);

/*----- READLINE FUNCTIONS -----*/

void					rl_replace_line(const char *text, int clear_undo);
void					rl_clear_history(void);

/*---- TERMIOS FUNCTIONS -----*/

void					suppress_output(void);

#endif
