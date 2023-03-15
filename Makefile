# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oandelin <oandelin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2023/03/15 19:08:04 by oandelin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fdf
SRCS	= fdf.c fdf_init.c fdf_draw.c
HFILES = fdf.h
HEADERS = $(addprefix $(INCDIR),$(HFILES))
CC	= cc
CFLAGS	= -Wall -Werror -Wextra
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
	$(CC) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.PHONY: all clean fclean re test