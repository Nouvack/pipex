# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 11:25:55 by nsantand          #+#    #+#              #
#    Updated: 2025/01/18 18:29:11 by nsantand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED       = \033[1;31m
GREEN     = \033[1;32m
BLUE      = \033[1;34m
CYAN      = \033[1;36m
DEF_COLOR = \033[0;39m

NAME    := pipex
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
LIBFT   := ./lib/LIBFT
LIBFT_A   := ./lib/LIBFT/libft.a
SRC_DIR := src/
SRC     := $(SRC_DIR)pipex.c $(SRC_DIR)pipex_utils.c $(SRC_DIR)aux_utils.c
OBJ     := $(SRC:.c=.o)
HEADERS := -I . -I $(LIBFT)/include

all: libmlx libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(HEADERS) -o $(NAME) $(OBJ) $(LIBS) -L$(LIBFT) -lft
	@echo "$(CYAN)Pipex Compiled$(DEF_COLOR)🇵🇪🇷🇺"


libft: $(LIBFT_A)
$(LIBFT_A):
	@make -sC $(LIBFT)
	@echo "$(GREEN)Libft Compiled$(DEF_COLOR)🇵🇪🇷🇺"

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(LIBMLX)/build
	@make -sC $(LIBFT) clean
	@echo "$(RED)All object files erased!$(DEF_COLOR)🇵🇪🇷🇺"

fclean: clean
	@rm -rf $(NAME)
	@make -sC $(LIBFT) fclean

re: fclean all

.PHONY: all libmlx libft clean fclean re