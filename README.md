# 🔥'Mini-hell'🔥

Minishell is a 42 cursus project that is a lightweight shell implementation written in C. It provides a minimalist command line interface with basic shell functionality such as pipes and redirections.

## 📚Implementation📚

To understand the project, you need to know it's parts. The process can be broken down into 4 steps as follows

`expander`->`lexer`->`parser`->`executor`. Depending on the implementation of this project by different authors, this process may vary from project to project.

### Quote control

One of the most important parts of the minishell process is the handling of single and double quotes. There are several important things to consider when parsing user input:

- The minishell must correctly handle the different types of quotes and their combinations. For example, nested quotes should be supported, where a quoted string contains another quoted string.
- The minishell typically performs variable expansion, where variables are replaced with their corresponding values. However, when an argument is enclosed in single quotes, variable expansion is disabled. This allows us to pass arguments that contain dollar signs ($) or other variable-related symbols without triggering unwanted substitutions.
- The quotes also help prevent word splitting, the process of splitting a command line argument into separate words based on whitespace. By using quotes, we can ensure that the whitespace characters inside the quotes are treated as part of the argument, not as word separators. This is especially important when dealing with arguments that contain spaces or other special characters.

### Stand-alone special symbols 

Another important step in the development of a minishell program is to check whether the input contains special stand-alone symbols (`<`, `>`, `|`, `&` etc.). In this case, we can very quickly detect very basic syntax errors if we encounter such symbols in the very first positions. 

**NOTE:** You must also change the exit error status if you are finishing the process and printing errors. In this case we can store this variable in the main structure (called, for example, data) and define error numbers in our header file: 

```
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define EXIT_NOT_FOUND 127
# define EXIT_SYNTAX_ERROR 258

// feel free to define as many error types codes as you need

typedef struct s_data
{
	int		exit_status;    ← here we save that status
	t_env		*env_copy;
	char		*input_copy;
	t_cmd		*cmd;
	t_token		*token;
	pid_t		pid;
}			t_data;

```

### Expander

The next important step is to deal with variable expansion. Bash always does this. 

In our case, the variable expansion process was broken down into several steps:

- **searching for variables in the input** (actually we should expand only those variables that are inside double quotes or inside single quotes that are inside double quotes). Since we don't have to replicate the behavior of standard bash, which waits for the quotes to be closed, we can output an error message.
- **saving variable names to a standalone list.**  It’s a list of structures, each of which contains following parameters:

```
typedef struct s_var_name
{
  char		*name;      ← name of variable
  char		*value;     ← value of variable
  int		pos;        ← position of i when checking input
  int		start;      ← position of the first letter in thevariable name 
  int		end;        ← position of the last letter in the variable name
}			t_var_name;
```

![Lexing process](/readme_imgs/newinput.svg)

Since we have a copy of all environment variables in the main structure (data→env_copy), which was done before Lexer was implemented, we need the names of expandable variables in the input to compare them with the environment variables to replace them later with a value or (!) with an empty string. Also we need to handle the case when we have `$?` which should expand to the exit status of the most recently executed foreground pipeline (exit error).

- **searching for names of found variables in the input string in the list of environment variables.**

- **expanding of variable names** (if names of variables from input had been found in the environment variables list, we copy their values to the t_var_name→value member, otherwise we just save there empty line in all cases except `$?` . If we found this combination we assign it the value of data→exit_status integer.

- **making new input.** Once all members of the s_var_name structure for each variable in the found variables list have been filled, we begin forming a new input. That's why we needed the start and end positions of the variable name in the string.

### Lexer
In the tokenization and lexing process, which are similar in nature, we go through each input line and split it into different tokens. While the lexing process can be quite complex, the MiniShell project only requires a limited number of token types:

```
typedef struct s_tkn
{
  enum
  {
    TKN_PIPE,				← Pipe symbol (|)
    TKN_REDIR_IN,				← Redirection input symbol (<)
    TKN_REDIR_OUT,			← Redirection output symbol (>)
    TKN_REDIR_APPEND,			← Redirection append symbol (>>)
    TKN_REDIR_HERE_DOC,			← Redirection here doc symbol (<<)
    TKN_WORD,				← Those characters are to be grouped together between two spaces
    TKN_STRING,				← The entirety of the content within the aforementioned quotation marks
    TKN_ERROR				← 3 and more consecutive >, < and more than 2 |
  }			e_type;
  char			*value; 	← The value of the token
  int			order;  	← The order of the token in the token list (e.g. 1, 2, 3, ...)
}				t_tkn;
```
**NOTE** 


### Parser

The objective of this component is to transform the tokens list into a command list in the format illustrated below:

```
typedef struct s_cmd
{
  char			**args;
  int			flag_redir;
  int			fd[2];
  t_redirect		*redir;
  int			redir_count[2];
  int			save;
  struct s_cmd		*next;
}				t_cmd;
```

The `t_cmd struct` represents a linked list where each node represents a command line. This linked list is used to store the commands that are separated by pipes in the input string. For example, consider the line `echo "Hello World!" | cat -e`. This line contains two nodes of command list: first `echo "Hello World!"` and then `cat -e`. This process is repeated in a loop while there are no more arguments or pipes.

 - `args` 			is a double character array that contains the tokens type word
 - `flag_redir`		1 if there's a redir and 0 if not
 - `fd[2]`			is used to store the values of the file descriptor that we changed on the execution part
 - `*redir`			is a list that contains a string with the redir (example: "`<`") and the file name next to the redir
 - `redir_count[2]`	in redir_count[0] counts the input redirects and in redir_count[1] the outputs redirects
 - `save`			used to save the initial fd

### Executor


The process is executed in a loop until there are no further commands. The following steps are taken:

- A fork is created.
- Redirects are searched for and executed in a loop until there are no more redirects. The file descriptor is changed.
- If there is a built-in command, it is executed outside the fork and the file descriptor is changed. If there is not a built-in command, the command is executed using `execve`.

Once all commands have been executed, and provided that no output has been generated, the custom outputs associated with the file descriptors are sent to the standard output.

## 🎉Features🎉

### Basics:

- History of previous entered commands
- Search and launch the right executable (based on the PATH variable, using a relative or an absolute path)
- Environment variables ($ followed by a sequence of characters) expand to their values
- ctrl-C, ctrl-D and ctrl-\ behave like in bash
- `’` (single quotes - prevent from interpreting meta-characters in quoted sequence)
- `"` (double quotes - prevent from interpreting meta-characters in quoted sequence except for $)
- `$?` expands to the last exit status
- `|` connect cmds or groups with pipes; output of a cmd is connected to the input of the next cmd via a pipe

### Builtins:

- `echo` with option -n
- `cd` (relative or absolute path, and without arg for HOME)
- `pwd` without options
- `export` without arguments, it prints enviromental variables
- `unset` without options
- `env` without options
- `exit` with exit status

### Redirections:

- `>` for redirecting output
- `>>` for appending output
- `<` for redirecting input
- `<<` for Heredoc

## 🛠️Dependencies🛠️

### Install readline on 42 Macs

Install Brew, *ONLY* if it is not already installed:

	rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update

Install Readline library:

	brew install readline
	brew link --force readline
	echo 'export C_INCLUDE_PATH="$HOME/.brew/include:$C_INCLUDE_PATH"' >> ~/.zshrc
	echo 'export LIBRARY_PATH="$HOME/.brew/lib:$LIBRARY_PATH"' >> ~/.zshrc
	source ~/.zshrc
## 💻Usage💻

### Requirements:

- GCC / CLANG Compiler
- GNU Make
- GNU Readline library

### Steps:

To use 'Minihell', you need to clone the repository

	git clone https://github.com/MarcosZeaMoreno/minihell Minihell
	
Enter the folder and execute command `make`

	cd Minihell && make

And finally open the program

	./minishell

And you're done! Now use it however you want.

### Commands to try!

	ls -la | cat -e | wc

	cat << EOF > file
	cat file
	rm file

To exit the program:

	exit

## Authors
This is a collaborative educational project of **42Málaga** school created by 
- **Marcos Zea Moreno** ([MarcosZeaMoreno](https://github.com/MarcosZeaMoreno)): responsable of project structure, built-in functions, execution, redirection, and piping.
- **Vladimir Katasonov** ([vkatasonov](https://github.com/vkatasonov)): responsible for lexing, parsing, and input check.