# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 23:37:45 by mobadiah          #+#    #+#              #
#    Updated: 2024/02/10 17:07:41 by mobadiah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= cub3d
SRC			:=	SRC/cub3d.c
# LIBMLX		:= ./MLX42
LIBFT		:= ./libft
OBJ			:= $(SRC:.c=.o)
CC			:=	cc
CFLAGS		:= #-Wall -Werror -Wextra # -fsanitize=address
# HEADERS	:= -Iinclude -lglfw 

all: clone_MLX $(NAME) 

clone_MLX:
	@if [ -e "MLX42" ]; then \
		echo "up to date"; \
	else \
		git clone https://github.com/codam-coding-college/MLX42.git; \
		cd MLX42; \
		cmake -B build; \
		make -C build -j4; \
		cd MLX42; cmake .; \
	fi

$(NAME): $(OBJ) $(LIBFT)
	make -C ./libft
	make -C ./MLX42
	@$(CC) $(CFLAGS) $(OBJ) libft/libft.a MLX42/libmlx42.a -lglfw -L ~/.brew/cellar/glfw/3.3.8/lib -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT)

clean:
	make clean -C $(LIBFT)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf libft/libft.a
	@rm -rf ./MLX42
	@rm -f $(NAME)

re: fclean all

.PHONY: cub3d, build_mlx, build_libft, all, clean, fclean, re