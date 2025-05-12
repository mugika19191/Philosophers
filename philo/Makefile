NAME = philo

SRCS =	main.c \
	list.c \
	input_check.c \
	lib_utils.c \
	philo_moves.c \
	philo_move2.c \

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re