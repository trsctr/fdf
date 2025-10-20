# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandelin <oandelin@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2025/10/20 18:26:02 by oandelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fdf
CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
SRCDIR		=	src/
SRCFILES	= 	fdf.c init.c draw.c hooks.c parser.c parser_helpers.c projection.c
INC_DIR		=	include/
INC_FILES	=	fdf.h keys.h 
HEADER		=	$(addprefix $(INC_DIR), $(INC_FILES))
SRCS 		=	$(addprefix $(SRCDIR), $(SRCFILES))
MLX_DIR		=	minilibx-linux/
LIBFT 		= 	libft/libft.a
MINILIBX	=	$(MLX_DIR)/libmlx.a
LIBS		=	-lm libft/libft.a $(MINILIBX) -lXext -lX11
PARSER_SRCS := src/parse_map.c
PARSER_OBJS := $(PARSER_SRCS:.c=.o)
TEST_SRCS := tests/runner.c tests/test_helpers.c tests/test_convert_lines_to_map.c tests/test_get_map_size.c tests/test_count_tokens.c tests/test_read_lines.c
TEST_OBJS := $(TEST_SRCS:.c=.o)

all: $(LIBFT) $(MINILIBX) $(NAME)

$(LIBFT):
	@make -C libft

$(MINILIBX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning minilibx-linux..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@if [ ! -f "$(MINILIBX)" ]; then \
		echo "Compiling mlx library..."; \
		make -C $(MLX_DIR); \
	fi

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
	@echo "NOTE: minilibx-linux directory kept (re-clone with: rm -rf minilibx-linux and then run make)"

re: fclean all

test: $(LIBFT) $(TEST_OBJS) $(PARSER_OBJS)
	$(CC) $(CFLAGS) -o test_runner $(TEST_OBJS) $(PARSER_OBJS) $(LIBFT) -lm 
	./test_runner

CFLAGS += -Iinclude -DTEST

.PHONY: all clean fclean re test