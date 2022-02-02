CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	client.c \
		server.c
BONUS = client_bonus.c \
		server_bonus.c

#SRCS_OBJS :=$(SRCS:.c=.o)

#BONUS_OBJS :=$(BONUS:.c=.o)

.PHONY : all fclean clean re
all : client server

bonus : client_bonus  server_bonus

% : %.c
	$(CC) $(CFLAGS) $^ -o $@

clean :
	rm -f client server
	rm -f client_bonus server_bonus

fclean : clean

re : fclean all
