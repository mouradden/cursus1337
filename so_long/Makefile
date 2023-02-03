

SOURCES = get_next_line.c get_next_line_utils.c 

OBJECTS = ${SOURCES:.c=.o}
NAME = get_next_line.a
CC = = cc

CFLAGS 	= -Wall -Wextra -Werror

all : ${NAME}
${NAME} : ${OBJECTS}
		ar rcs ${NAME} ${OBJECTS}

%.o:%.c
	${CC} -o $@ -c $^

clean :
	rm -f ${OBJECTS}

fclean : clean
		rm -f $(NAME)

re : fclean all