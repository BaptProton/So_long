# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proton <proton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 16:05:13 by bproton           #+#    #+#              #
#    Updated: 2026/02/17 12:08:29 by proton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iinclude -Ilib/ft_printf -Ilib/minilibx-linux

SRC =	src/so_long.c \
		src/utils/ft_split.c \
		src/utils/so_long_utils.c \
		src/map/parsing_utils.c \
		src/map/map_algorithm.c \
		src/image/image_gestion.c \
		src/image/image_utils.c \
		src/image/moves_player.c

OBJ_DIR = obj
OBJECTS = $(SRC:%.c=$(OBJ_DIR)/%.o)

MLX_DIR = lib/minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

PRINTF_DIR = lib/ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

LDLIBS = -L$(MLX_DIR) -lmlx -L$(PRINTF_DIR) -lftprintf -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJECTS) $(MLX_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
