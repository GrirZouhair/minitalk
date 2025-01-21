CC    = gcc
flags = -Wall -Wextra -Werror
NAME  = minitalk

SRC_MANDATORY_server =  utils.c mandatory/server.c
SRC_MANDATORY_client =  utils.c mandatory/client.c
SRC_BONUS_server     =  utils.c bonus/server_bonus.c
SRC_BONUS_client     =  utils.c bonus/client_bonus.c


OBJ_MANDATORY_SERVER = $(SRC_MANDATORY_server:.c=.o)
OBJ_MANDATORY_CLIENT = $(SRC_MANDATORY_client:.c=.o)
OBJ_BONUS_SERVER     = $(SRC_BONUS_server:.c=.o)
OBJ_BONUS_CLIENT     = $(SRC_BONUS_client:.c=.o)

# OBJ_COMMON			 = $(SRC_COMMON:.c=.o)

all: $(NAME)

$(NAME) : server client
bonus: server_bonus client_bonus

%.o:%.c minitalk.h
	$(CC) $(flags) -c $< -o $@

server: $(OBJ_MANDATORY_SERVER)
	$(CC) $(flags) -o server $(OBJ_MANDATORY_SERVER)
client: $(OBJ_MANDATORY_CLIENT)
	$(CC) $(flags) -o client $(OBJ_MANDATORY_CLIENT)


server_bonus: $(OBJ_BONUS_SERVER)
	$(CC) $(flags) -o server_bonus $(OBJ_BONUS_SERVER)
client_bonus: $(OBJ_BONUS_CLIENT)
	$(CC) $(flags) -o client_bonus $(OBJ_BONUS_CLIENT)


clean:
	rm -f $(OBJ_MANDATORY_SERVER) $(OBJ_MANDATORY_CLIENT) $(OBJ_BONUS_SERVER) $(OBJ_BONUS_CLIENT)

fclean: clean
	rm -f server client server_bonus client_bonus

re: fclean all
