# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 13:47:07 by mottjes           #+#    #+#              #
#    Updated: 2023/07/26 13:49:56 by mottjes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	./ft_atoi.c			\
		./ft_bzero.c		\
		./ft_calloc.c		\
      	./ft_isalnum.c		\
		./ft_isalpha.c		\
		./ft_isascii.c		\
		./ft_isdigit.c		\
		./ft_isprint.c		\
		./ft_itoa.c			\
		./ft_memchr.c		\
		./ft_memcmp.c		\
		./ft_memcpy.c		\
		./ft_memmove.c		\
		./ft_memset.c		\
		./ft_putchar_fd.c	\
		./ft_putendl_fd.c	\
		./ft_putnbr_fd.c	\
		./ft_putstr_fd.c	\
		./ft_split.c		\
		./ft_strchr.c		\
		./ft_strdup.c		\
		./ft_striteri.c		\
		./ft_strjoin.c		\
		./ft_strlcat.c		\
		./ft_strlcpy.c		\
		./ft_strlen.c		\
		./ft_strmapi.c		\
		./ft_strncmp.c		\
		./ft_strnstr.c		\
		./ft_strrchr.c		\
		./ft_strtrim.c		\
		./ft_substr.c		\
		./ft_tolower.c		\
		./ft_toupper.c		\

OBJS = $(SRC:.c=.o)

HDRS = libft.h

all: $(NAME)

$(NAME):
	@cc -c -Wall -Wextra -Werror $(HDRS) $(SRC)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	rm -f $(OBJS) $(HDRS).gch

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
