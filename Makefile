# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/08 15:13:18 by vkatason          #+#    #+#              #
#    Updated: 2024/04/03 18:59:10 by mzea-mor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

USER := $(shell whoami)
NAME = minishell
CC = gcc -g
CLEAN = rm -Rf
CFLAGS = -Wall -Werror -Wextra
#-fsanitize=address
#LDFLAGS for home
#LDFLAGS = -L/opt/homebrew/Cellar/readline/8.2.10/lib -lreadline
#LDFLAGS for school
LDFLAGS = -lreadline -L/Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include
LIBFT = libft
SRC =  $(shell find ./src -iname "*.c")

#COLORS
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
DEFAULT	:= \033[0m

OBJS := $(SRC:.c=.o)

all: libftmake $(NAME)

$(NAME): $(OBJS) minishell.h
	@$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS) $(LIBFT)/libft.a
	@echo "$(GREEN)The app $(NAME) was successfully compiled. $(DEFAULT)"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	@echo "$(GREEN)Compiling:$(DEFAULT) $(notdir $<)"

clean: libftclean
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)Removing:$(DEFAULT) all objects of $(NAME)."

fclean: libftfclean
	@$(CLEAN) ./$(OBJS)
	@echo "$(RED)Removing:$(DEFAULT) all objects of $(NAME)."
	@$(CLEAN) ./$(NAME) ./$(NAME)
	@echo "$(RED)Removing:$(DEFAULT) $(NAME) program."

re: fclean all

norma: libftnorma
	@norminette $(SRC) minishell.h
libftnorma:
	@make norma -C $(LIBFT)
norma_color: libftnorma_color
	@norminette $(SRC) minishell.h 2>&1 | sed -e "s/Warning/\x1b[1;33m&\x1b[0m/" -e "s/Error/\x1b[1;31m&\x1b[0m/" -e "s/OK/\x1b[1;32m&\x1b[0m/"
libftnorma_color:
	@make norma_color -C $(LIBFT)
libftmake:
	@make -C $(LIBFT)
libftclean:
	@make clean -C $(LIBFT)
libftfclean:
	@make fclean -C $(LIBFT)
libftre: libftclean libftmake

.PHONY : all clean fclean re \
libftmake libftclean libftfclean libftre