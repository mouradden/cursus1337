# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 22:08:19 by mdenguir          #+#    #+#              #
#    Updated: 2023/01/31 21:40:32 by mdenguir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = push_swap.c stack_utils.c utils.c check_args.c sort_3.c sort_5.c utils_1.c utils_2.c moves.c communes_moves.c free_leaks.c rule_push.c rule_rotate.c rule_reverse_rotate.c rule_swap.c
SOURCES_BONUS = ./bonus/checker_bonus.c ./bonus/get_next_line.c ./bonus/get_next_line_utils.c ./bonus/stack_utils_bonus.c utils.c check_args.c free_leaks.c utils_2.c ./bonus/rule_rotate_bonus.c ./bonus/rule_reverse_rotate_bonus.c ./bonus/rule_swap_bonus.c ./bonus/rule_push_bonus.c

OBJECTS = ${SOURCES:.c=.o}
OBJECTS_BONUS = ${SOURCES_BONUS:.c=.o}

NAME = push_swap

CC = cc

Flags = -Wall -Werror -Wextra

all: ${NAME}

bonus : ${OBJECTS_BONUS}
	${CC} ${Flags} ${OBJECTS_BONUS} -o checker

${NAME} : ${OBJECTS}

project : all bonus clean

%.o:%.c
		${CC} ${Flags} -c $^ -o $@

clean :
		rm -f ${OBJECTS} $(OBJECTS_BONUS)

fclean : clean
		rm -f $(NAME) checker

re : fclean all