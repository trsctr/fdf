# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2023/06/07 13:00:59 by oandelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fdf
CC			= 	cc
CFLAGS		= 	-Wall -Werror -Wextra
LIBFT 		= 	libft/libft.a
SRCDIR		=	src/
SRCFILES	= 	fdf.c init.c draw.c hooks.c parse_map.c projection.c
LIBS		=	-lmlx -framework OpenGL -framework AppKit
SRCS 		=	$(addprefix $(SRCDIR), $(SRCFILES))

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME):
	@echo "Compiling fdf.."
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(LIBS) -o $(NAME)
	@echo "Done!"

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@echo "Deleting binaries.."
	@rm -f $(NAME)
	@echo "Binaries deleted!"

re: fclean all

.PHONY: all clean fclean re