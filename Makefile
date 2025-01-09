CC = gcc
flags= -Wall -Wextra -Werror
NAME = minitalk

SRC_MANDATORY_server = utils.c mandatory/server.c
SRC_MANDATORY_client = utils.c mandatory/client.c

OBJ_MANDATORY_CLIENT = $(SRC_MANDATORY_client:.c=.o);
OBJ_MANDATORY_SERVER = $(SRC_MANDATORY_server:.c=.o)



all: $(NAME)
$(NAME) : server client

%.o:%.c minitalk.h
	$(CC) $(flags) -c $< -o $@

server: $(OBJ_MANDATORY_SERVER)
	$(CC) $(flags) -o server $(OBJ_MANDATORY_SERVER)
client: $(OBJ_MANDATORY_CLIENT)
	$(CC) $(flags) -o client $(OBJ_MANDATORY_CLIENT)

clean:
	rm -f $(OBJ_MANDATORY_SERVER) $(OBJ_MANDATORY_CLIENT)

fclean: clean
	rm -f server client

re: fclean all
