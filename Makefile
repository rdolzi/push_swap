NAME = push_swap

SRCS = main.c \
	   ./rules/push.c ./rules/swap.c \
	   ./rules/rotate.c ./rules/reverse_rotate.c \
	   ./utils/utils.c \

FLAGS = -Wextra -Werror -Wall

CC = gcc ${FLAGS}
RM = rm -f

OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) -g -c $< -o ${<:.c=.o}

		
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	
re: fclean all




