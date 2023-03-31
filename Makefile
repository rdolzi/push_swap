NAME = push_swap

SRCS = main.c \

FLAGS = -Wextra -Werror -Wall

CC = gcc ${FLAGS}
RM = rm -f

OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) -Imlx -g -c $< -o ${<:.c=.o}

		
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(NAME)

all: $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	
re: fclean all




