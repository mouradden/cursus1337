# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 22:08:19 by mdenguir          #+#    #+#              #
#    Updated: 2023/01/30 22:15:56 by mdenguir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = push_swap.c stack_utils.c utils.c check_args.c sort_3.c sort_5.c utils_1.c utils_2.c moves.c communes_moves.c free_leaks.c rule_push.c rule_rotate.c rule_reverse_rotate.c rule_swap.c

OBJECTS = ${SOURCES:.c=.o}

NAME = push_swap

CC = cc

Flags = -Wall -Werror -Wextra

all: ${NAME}

# bonus : checker

${NAME} : ${OBJECTS}

%.o:%.c
		${CC} ${Flags} -c $^ -o $@

clean :
		rm -f ${OBJECTS}

fclean : clean
		rm -f $(NAME)

re : fclean all