# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberries <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:27:22 by yberries          #+#    #+#              #
#    Updated: 2020/02/04 20:55:34 by yberries         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = libft/
LIBFT_HDR = $(LIBFT_DIR)include/

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = minilibx_macos/
MLX_HDR = $(MLX_DIR)

HDRS = fdf.h
HDR_DIR = include/
HDR = $(addprefix $(HDR_DIR), $(HDRS))

INCLUDES = -I$(HDR_DIR) -I$(LIBFT_HDR) -I$(MLX_HDR)

SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), $(SRCS))
SRCS = main.c \
	   read.c \
	   fdf.c \
	   rotation.c \
	   keys.c \
	   draw.c

OBJ_DIR = objects/
OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJ	= $(addprefix $(OBJ_DIR), $(OBJS))

LIBS = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
	gcc $(FLAGS) $(LIBS) $(INCLUDES) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HDR)
	gcc $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	$(MAKE) -sC $(MLX_DIR)

clean:
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(MLX)
	rm -f $(LIBFT)
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
