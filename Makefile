# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2024/09/26 14:36:51 by oandelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fdf
CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra -fsanitize=address -g
SRCDIR		=	src/
SRCFILES	= 	fdf.c init.c draw.c hooks.c parse_map.c projection.c
MLX_DIR		=	minilibx-linux
LIBS		=	-lm libft/libft.a $(MLX_DIR)/libmlx.a -lXext -lX11
SRCS 		=	$(addprefix $(SRCDIR), $(SRCFILES))

all: $(NAME)


$(NAME):
	@make -C libft
	@echo "Compiling mlx library.."
	@make -C $(MLX_DIR)
	@echo "Compiling fdf.."
	@$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)
	@echo "Done!"

clean:
	@make clean -C libft
	@make clean -C $(MLX_DIR)

fclean: clean
	@make fclean -C libft
	@echo "Deleting binaries.."
	@rm -f $(NAME)
	@echo "Binaries deleted!"

re: fclean all

.PHONY: all clean fclean re