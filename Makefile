# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bproton <bproton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 16:05:13 by bproton           #+#    #+#              #
#    Updated: 2024/04/04 16:13:45 by bproton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I./map_parsing -I./image_related
SRC =	so_long.c ft_split.c so_long_utils.c ./map_parsing/parsing_utils.c \
		./map_parsing/map_algorithm.c ./image_related/image_gestion.c \
		./image_related/image_utils.c ./image_related/moves_player.c \


OBJECTS = $(SRC:.c=.o)

all: $(NAME)

libmlx.a:
	$(MAKE) -C minilibx

libftprintf.a:
	$(MAKE) -C ft_printf

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -Lft_printf -lftprintf -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Iminilibx -c $< -o $@

clean:
	rm -f $(NAME) $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
