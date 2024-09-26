# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2024/09/26 20:09:47 by oandelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fdf
CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
SRCDIR		=	src/
SRCFILES	= 	fdf.c init.c draw.c hooks.c parse_map.c projection.c
INC_DIR		=	include/
INC_FILES	=	fdf.h keys.h 
HEADER		=	$(addprefix $(INC_DIR), $(INC_FILES))
SRCS 		=	$(addprefix $(SRCDIR), $(SRCFILES))
MLX_DIR		=	minilibx-linux/
LIBFT 		= 	libft/libft.a
MINILIBX	=	$(MLX_DIR)/libmlx.a
LIBS		=	-lm libft/libft.a $(MINILIBX) -lXext -lX11

all: $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	@make -C libft

$(MINILIBX):
	@echo "Compiling mlx library.."
	@make -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MINILIBX) $(SRCS) $(HEADER)
	@echo "Compiling fdf.."
	@$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)
	@echo "Done!"

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@make clean -C $(MLX_DIR)
	@echo "Deleting binaries.."
	@rm -f $(NAME)
	@echo "Binaries deleted!"

re: fclean all

.PHONY: all clean fclean re