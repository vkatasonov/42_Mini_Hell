# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzea-mor <mzea-mor@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 12:54:50 by vkatason          #+#    #+#              #
#    Updated: 2024/04/01 18:49:42 by mzea-mor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

APPNAME = libft

SRC = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_isspace.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_numbase.c ft_printf.c ft_putchar_fd.c \
		ft_putchar.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr.c ft_putptr.c \
		ft_putstr_fd.c ft_putstr.c ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c \
		ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
		ft_toupper.c ft_type.c ft_wdcounter.c get_next_line.c get_next_line_utils.c \
		ft_hex_to_int.c ft_charpp.c ft_atol.c ft_strstr.c ft_strcat.c \
		ft_strtok.c ft_strncpy.c ft_printf_fd.c ft_strcpy.c ft_realloc.c \
		ft_match_symbol.c ft_strncat.c ft_is_extended.c ft_is_ext_no_quotes.c \
		ft_strjoin_free.c

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c\
		ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc -g

LIB = ar -rcs $(NAME)

REMOVE = rm -f

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
	@echo "$(GREEN)Compiling:$(DEFAULT) $(notdir $<)"

$(NAME): $(OBJ) $(OBJ_BONUS)
	@$(LIB) $(OBJ) $(OBJ_BONUS)
	@echo "$(GREEN)$(APPNAME) was successfully compiled. $(DEFAULT)"

norma:
	@norminette $(SRC) $(SRC_BONUS) libft.h

norma_color:
	@norminette $(SRC) libft.h 2>&1 | sed -e "s/Warning/\x1b[1;33m&\x1b[0m/" -e "s/Error/\x1b[1;31m&\x1b[0m/" -e "s/OK/\x1b[1;32m&\x1b[0m/"

clean:
	@$(REMOVE) $(OBJ) $(OBJ_BONUS)
	@echo "$(RED)Removing:$(DEFAULT) all objects of $(APPNAME)."

fclean: clean
	@$(REMOVE) $(NAME)
	@echo "$(RED)Removing:$(DEFAULT) $(APPNAME)."

re: fclean all
@echo "$(MAGENTA)Recompiling:$(DEFAULT) $(APPNAME)."

.PHONY: all clean fclean re

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