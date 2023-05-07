# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:22:50 by lyandriy          #+#    #+#              #
#    Updated: 2023/02/18 23:04:14 by lyandriy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	  utils.c\
	  so_long.c\
	  get_map.c\
	  check_map.c\
	  check_file.c\
	  create_img.c\
	  move_sprite.c\
	  clear_memory.c\
	  check_map_struct.c

GNL = get_next_line/get_next_line.a
LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra 
LMLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(GNL):
	@make -C get_next_line
$(LIBFT):
	@make -C libft
$(NAME) : $(OBJ) $(GNL) $(LIBFT)
	$(CC) $(CFLAGS) $(LMLX) $(OBJ) $(GNL) $(LIBFT) -o $(NAME)

clean:
	@make clean -C libft
	@make clean -C get_next_line
	rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@make fclean -C get_next_line
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
