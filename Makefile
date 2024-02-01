CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_C = client.c utilities.c
SRC_S = server.c utilities.c
BSRC_C = client_bonus.c utilities.c
BSRC_S = server_bonus.c utilities.c

OSRC_C = $(SRC_C:.c=.o)
OSRC_S = $(SRC_S:.c=.o)
OBSRC_C = $(BSRC_C:.c=.o)
OBSRC_S = $(BSRC_S:.c=.o)

CLIENT = client
SERVER = server
B_CLIENT = client_bonus
B_SERVER = server_bonus

OBJT = $(OSRC_C) $(OSRC_S)
BOBJT = $(OBSRC_C) $(OBSRC_S)

HEADER = minitalk.h


all: $(CLIENT) $(SERVER)

%.o: %.c $(HEADER)
	@echo "Compiling $< ..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT): $(OSRC_C)
	@echo "Compiling client"
	@$(CC) $(CFLAGS) $(OSRC_C) -o $(CLIENT)

$(SERVER): $(OSRC_S)
	@echo "Compiling server"
	@$(CC) $(CFLAGS) $(OSRC_S) -o $(SERVER)

bonus: $(B_CLIENT) $(B_SERVER)

$(B_CLIENT): $(OBSRC_C)
	@echo "Compiling client_bonus"
	@$(CC) $(CFLAGS) $(OBSRC_C) -o $(B_CLIENT)

$(B_SERVER): $(OBSRC_S)
	@echo "Compiling server_bonus"
	@$(CC) $(CFLAGS) $(OBSRC_S) -o $(B_SERVER)

clean:
	@echo "Removing obj files:"
	@rm -rf $(OSRC_C) $(OSRC_S) $(OBSRC_C) $(OBSRC_S)

fclean: clean
	@echo "Removing all"
	@rm -rf $(CLIENT) $(SERVER) $(B_CLIENT) $(B_SERVER)

.PHONY: clean
