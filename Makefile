# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbehra <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 12:20:37 by tbehra            #+#    #+#              #
#    Updated: 2018/04/16 15:20:10 by tmervin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= gcc
NAME 		= fillit
FLAGS 		= -Wall -Werror -Wextra

SRC_PATH 	= ./src
SRC_FILES 	= main.c		\
			  fillit.c		\
			  tetriminos.c	\
			  parsing.c		\
			  functions.c	\
			  error.c		\
			  map.c

OBJ_NAME	= $(SRC_FILES:.c=.o)

SRC			= $(addprefix $(SRC_PATH)/,$(SRC_FILES))
OBJ			= $(addprefix $(SRC_PATH)/,$(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	$(CC) -c $(FLAGS) $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ_NAME)

clean:
	/bin/rm -fv $(OBJ_NAME)

fclean: clean
	/bin/rm -fv $(NAME)

re: fclean all
