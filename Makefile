# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 13:46:06 by marvin            #+#    #+#              #
#    Updated: 2023/07/23 13:46:06 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# Color codes for terminal output
RED = \033[0;34m
NC = \033[0m

NAME = so_long
LIBFT = ./utility/libft/libft.a
GET_NEXT_LINE = ./utility/get_next_line/get_next_line_bonus.a
CC = gcc
STDFLAG = -Wall -Werror -Wextra
REMOVE = rm -f
SRCS = so_long.c\
movement.c\
functions.c\
check_error.c\
input_handle.c\
not_move.c\
check_exit.c

OBJS = $(SRCS:.c=.o)

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11

all: $(LIBFT)  $(GET_NEXT_LINE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(STDFLAG) -o $(NAME) $(OBJS) -L. -Wl,--whole-archive $(LIBFT) -Wl,--no-whole-archive  $(GET_NEXT_LINE) $(MLX_FLAGS)
	#-fsanitize=address
	@echo "$(RED)COMPILATO\nIl programma funziona perfettamente.$(NC)"

$(LIBFT):
	make -C ./utility/libft

$(GET_NEXT_LINE):
	make -C ./utility/get_next_line

clean:
	$(REMOVE) $(OBJS)
	make clean -C ./utility/libft
	make clean -C ./utility/get_next_line

fclean: clean
	$(REMOVE) $(NAME)
	make fclean -C ./utility/libft
	make fclean -C ./utility/get_next_line
	@echo "$(RED)ALL CLEAN\n... too clean.$(NC)"

re: fclean all

.PHONY: all clean fclean re
