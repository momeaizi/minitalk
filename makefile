CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	client.c \
		server.c

.PHONY : all fclean clean re
all : client server

% : %.c
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -f client server

re : fclean all
