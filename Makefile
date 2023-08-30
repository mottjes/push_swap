# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mottjes <mottjes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 13:35:42 by mottjes           #+#    #+#              #
#    Updated: 2023/08/11 14:25:07 by mottjes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =  	main.c				\
		stack_init.c		\
		stack_utils.c		\
		stack_error.c		\
		stack_sort.c		\
		radix_sort.c		\
		push_swap.c			\
		rotate.c			\
		reverse_rotate.c	\

OBJS = $(SRC:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

LIBS = libft/libft.a

all: ${NAME}

${NAME}: $(OBJS)
	@${MAKE} -C ./libft
	@echo comiled libft
	$(CC) $(FLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJS): $(SRC)
	$(CC) $(FLAGS) $(SRC) -c

clean: 
	@${MAKE} -C ./libft clean
	rm -f $(OBJS)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)
