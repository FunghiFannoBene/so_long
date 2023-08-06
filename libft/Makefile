# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 00:46:18 by shhuang           #+#    #+#              #
#    Updated: 2022/12/03 02:50:05 by shhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
LIB=libft.h
CC=gcc
FLAGS=-Wall -Wextra -Werror
ARCHIVE=ar -rcs
RM=rm -f

FILEC=ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_strlen.c\
ft_memset.c\
ft_bzero.c\
ft_memcpy.c\
ft_strlcpy.c\
ft_strlcat.c\
ft_toupper.c\
ft_tolower.c\
ft_strchr.c\
ft_strrchr.c\
ft_atoi.c\
ft_strncmp.c\
ft_memmove.c\
ft_memchr.c\
ft_memcmp.c\
ft_strnstr.c\
ft_strdup.c\
ft_calloc.c\
ft_substr.c\
ft_strjoin.c\
ft_strtrim.c\
ft_split.c\
ft_itoa.c\
ft_strmapi.c\
ft_striteri.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\

BONUSC= ft_lstnew.c\
ft_lstclear.c\
ft_lstiter.c\
ft_lstmap.c\
ft_lstdelone.c\
ft_lstadd_back.c\
ft_lstlast.c\
ft_lstsize.c\
ft_lstadd_front.c\

FILEO=$(FILEC:.c=.o)
BONUSO=$(BONUSC:.c=.o)

all: $(NAME)
$(NAME): $(FILEO) $(LIB)
	$(ARCHIVE) $(NAME) $(FILEO)

bonus: $(BONUSO) $(LIB)
	$(ARCHIVE) $(NAME) $(BONUSO)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
			$(RM) $(FILEO) $(BONUSO)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
