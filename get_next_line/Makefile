# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 18:58:49 by lyandriy          #+#    #+#              #
#    Updated: 2023/01/15 19:05:24 by lyandriy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line_utils.c\
	  get_next_line.c

OBJ = $(SRC:.c=.o)

NAME = get_next_line.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re