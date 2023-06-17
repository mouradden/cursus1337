
SOURCES = so_long.c check_map.c map_outils.c init_map.c window.c movements.c check_path.c check_args.c exit.c map_outils_1.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
SOURCES_BONUS = ./bonus/so_long_bonus.c ./bonus/check_map_bonus.c ./bonus/map_outils_bonus.c ./bonus/map_outils_1_bonus.c ./bonus/init_map_bonus.c ./bonus/window_bonus.c ./bonus/movements_bonus.c ./bonus/movements_utils_bonus.c ./bonus/enemy_movements.c ./bonus/check_args_bonus.c ./bonus/check_path_bonus.c ./bonus/exit_bonus.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c ./bonus/ft_itoa.c

OBJECTS = ${SOURCES:.c=.o}
OBJECTS_BONUS = ${SOURCES_BONUS:.c=.o}

NAME 	= so_long

CFLAGS 	= -Wall -Wextra -Werror

CC		= cc

all :	${NAME}
		

${NAME} : ${OBJECTS}
		make -C ./ft_printf
		${CC} ${Flags} ${OBJECTS} ./ft_printf/libftprintf.a -o so_long -lmlx -framework OpenGL -framework AppKit
	
%.o:%.c
		${CC} ${CFLAGS} -c $^ -o $@
		
clean :
		rm -f ${OBJECTS} ${OBJECTS_BONUS}
		make clean -C ./ft_printf

fclean : clean
		rm -f $(NAME) ./ft_printf/libftprintf.a

re : fclean all

bonus : ${OBJECTS_BONUS}
		make -C ./ft_printf
		${CC} ${Flags} ${OBJECTS_BONUS} ./ft_printf/libftprintf.a -o so_long -lmlx -framework OpenGL -framework AppKit