serverSources = server.c utils.c
clientSources = client.c utils.c
serverObjects = $(serverSources:.c=.o)
clientObjects = $(clientSources:.c=.o)
serverSourcesBonus = server_bonus.c utils.c
clientSourcesBonus = client_bonus.c utils.c
serverObjectsBonus = $(serverSourcesBonus:.c=.o)
clientObjectsBonus = $(clientSourcesBonus:.c=.o)

CC = cc
Flags = -Wall -Werror -Wextra
RM		= rm -f

all: server client

server : 
	$(CC) $(Flags) -o server $(serverSources)

client : 
	$(CC) $(Flags) -o client $(clientSources)

client_bonus :
	$(CC) $(Flags) -o client_bonus $(clientSourcesBonus)

server_bonus :
	$(CC) $(Flags) -o server_bonus $(serverSourcesBonus)

clean:

fclean:
			${RM} server client client_bonus server_bonus

re:			fclean all

bonus : client_bonus server_bonus

.PHONY : all clean fclean re 

