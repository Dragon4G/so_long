# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 14:14:56 by bantunes          #+#    #+#              #
#    Updated: 2022/05/23 17:59:34 by bantunes         ###   ########.fr        #
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
		map2.c\
		printcolor.c \
		printcolor2.c \
		window.c \
		get_next_line.c \
		get_next_line_utils.c \
		move.c \
		portals.c \
		portals2.c \
		portals3.c \
		endgame.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	cd libft;make all
	cd libft;make bonus
	cd printf;make all
	$(AR) $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lft -lftprintf  -lmlx -framework OpenGL -framework AppKit -o $(PROG) -L./printf -L./libft

clean:
	$(RM) $(OBJS)
	cd libft;make clean
	cd printf;make clean

fclean: clean
	$(RM) $(NAME)
	cd libft;make fclean
	cd printf;make fclean

re: fclean $(NAME)

.PHONY: clean fclean all re
