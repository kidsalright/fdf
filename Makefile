# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yberries <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:27:22 by yberries          #+#    #+#              #
#    Updated: 2020/02/02 06:34:26 by yberries         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HDR = $(LIBFT_DIR)include/

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./minilibx_macos/
MINILIBX_HDR = $(MINILIBX_DIR)

HDR_LIST = fdf.h
HDR_DIR = ./include/
HDR = $(addprefix $(HDR_DIR), $(HDR_LIST))

INCLUDES = -I$(HDR_DIR) -I$(LIBFT_HDR) -I$(MINILIBX_HDR)

SOURCES_DIR = ./src/
SOURCES_LIST = main.c \
			   read.c \
			   fdf.c \
			   rotation.c \
			   keys.c \
			   draw.c
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_DIR = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MINILIBX_DIR) -framework OpenGL -framework AppKit
FLAGS = -Wall -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIR) $(OBJECTS)
	gcc $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIR):
	mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o : $(SOURCES_DIR)%.c $(HDR)
	gcc $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -sC $(MINILIBX_DIR)

clean:
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MINILIBX_DIR) clean
	rm -rf $(OBJECTS_DIR)

fclean: clean
	rm -f $(MINILIBX)
	rm -f $(LIBFT)
	rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
