# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proton <proton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 17:21:02 by proton            #+#    #+#              #
#    Updated: 2024/03/21 18:06:29 by proton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./so_long -I./map_parsing./image_related 
SRC =	so_long.c ft_split.c so_long_utils.c ./map_parsing/parsing_utils.c \
		./map_parsing/map_algorithm.c ./image_related/image_gestion.c \


OBJECTS = $(SRC:.c=.o)


all: $(NAME)

libmlx.a:
	$(MAKE) -C minilibx

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -Lminilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Iminilibx -c $< -o $@

clean:
	rm -f $(NAME) $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

