# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/21 10:17:15 by mdenguir          #+#    #+#              #
#    Updated: 2023/07/24 10:17:36 by mdenguir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = main.c utils.c init.c death.c check_args.c routine.c time.c clean.c

OBJECTS = ${SOURCES:.c=.o}

NAME = philo

all : ${NAME}

CC = cc

CFLAGS = -Wall -Werror -Wextra

%.o:%.c
	${CC} ${CFLAGS} -o $@ -c $^

${NAME} : ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${NAME}

clean :
	rm -f ${OBJECTS}

fclean : clean
	rm -f ${NAME}

re : fclean all