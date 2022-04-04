# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 14:14:56 by bantunes          #+#    #+#              #
#    Updated: 2022/03/29 17:20:23 by bantunes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROG = so_long
NAME = libpush.a 

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS =	so_long.c \
		map.c \
		printcolor.c \
		window.c \
		get_next_line.c \
		get_next_line_utils.c \
		move.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	make bonus -C libft
	make -C printf
	$(AR) $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lft -lftprintf  -lmlx -framework OpenGL -framework AppKit -o $(PROG) -L./printf -L./libft

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all re