# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdenguir <mdenguir@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 12:15:21 by mdenguir          #+#    #+#              #
#    Updated: 2022/10/25 12:02:11 by mdenguir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ft_printf.c ft_putstr.c ft_putnbr.c ft_putchar.c ft_print.c ft_print_hexa.c ft_print_address.c ft_print_unsigned.c

OBJECTS = ${SOURCES:.c=.o}

NAME 	= libftprintf.a

CFLAGS 	= -Wall -Wextra -Werror

CC		= gcc $(CFLAGS)

all :	${NAME}

${NAME} : ${OBJECTS}
		ar rcs ${NAME} ${OBJECTS}
	
%.o:%.c
		${CC} ${CFLAGS} -o $@ -c $^
		
clean :
		rm -f ${OBJECTS}

fclean : clean
		rm -f $(NAME)

re : fclean all

