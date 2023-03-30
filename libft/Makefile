# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trsctr <trsctr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 16:51:49 by oandelin          #+#    #+#              #
#    Updated: 2023/03/23 08:20:25 by trsctr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
INCLUDE	= include/
SRCDIR	= src/
OBJDIR	= obj/
HEADER	= $(NAME:.a=.h)
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCFILES 	= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
		ft_toupper ft_tolower ft_strlen ft_memset ft_bzero \
		ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_strchr \
		ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr \
		ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
		ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri \
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_putuint_fd \
		ft_get_next_line ft_printf ft_printf_parse ft_printf_convert_hex \
		ft_printf_convert_uidcs
SRCS 	= $(addprefix $(SRCDIR), $(addsuffix .c, $(SRCFILES)))
OBJS 	= $(addsuffix .o, $(SRCFILES))


all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)


clean:
	@echo "Cleaning libft object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing libft.a"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re