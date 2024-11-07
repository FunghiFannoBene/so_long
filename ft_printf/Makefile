# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 00:49:40 by shhuang           #+#    #+#              #
#    Updated: 2022/12/28 04:55:05 by shhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libftprintf.a

SRCS	= printf.c \
		  functionsprintf.c \
		  functionsprintf2.c \
		  percentualelist.c \
		  percentualelist2.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ../libft
	ar rcs $(NAME) $(OBJS) ../libft/libft.a

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ../libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ../libft fclean

re: fclean all

.PHONY: all clean fclean re