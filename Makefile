sources_server = src_server/strlen.c src_server/itoa.c src_server/server.c

sources_client = src_client/atoi.c src_client/client.c

NAME = minitalk
SERVER = server
CLIENT = client

CFLAGS = -Wextra -Werror -Wall

CC = gcc

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(sources_server)
	$(CC) $(CFLAGS) $(sources_server) -o $(SERVER)

$(CLIENT): $(sources_client)
	$(CC) $(CFLAGS) $(sources_client) -o $(CLIENT)

clean:

fclean:
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re: fclean all
