# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcot <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 10:25:00 by gcot              #+#    #+#              #
#    Updated: 2023/08/19 11:23:23 by gcot             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = serveur

SRC_C = client.c
SRC_S = serveur.c
SRC_U = utils.c error.c

CC = gcc
FLAGS = -Wall -Werror -Wextra

all :
	$(CC) $(FLAGS) $(SRC_C) $(SRC_U) -o $(NAME_C)
	$(CC) $(FLAGS) $(SRC_S) $(SRC_U) -o $(NAME_S)

clean :
	rm -rf *.o

fclean :
	rm -rf $(NAME_C) $(NAME_S)

re : fclean all
