# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2023/06/03 14:03:51 by oandelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fdf
SRCS	= src/fdf.c src/init.c src/draw.c src/events.c src/parse_map.c src/projection.c
HFILES = fdf.h
HEADERS = $(addprefix $(INCDIR),$(HFILES))
CC	= cc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address
INCFLAG	= $(addprefix -I,$(INCDIR))

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	$(CC) $(SRCS) -L. libft/libft.a -I libft/include -lmlx -framework OpenGL -framework AppKit -o $(NAME)

testlinux:
	$(CC) $(SRCS)  -L. libft/libft.a -I libft/include -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz -o $(NAME)

.PHONY: all clean fclean re test