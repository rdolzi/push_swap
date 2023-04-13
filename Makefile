NAME = push_swap
LIBFT = ./libft
SRCS = main.c \
	   ./rules/push.c ./rules/swap.c \
	   ./rules/rotate.c ./rules/reverse_rotate.c \
	   ./utils/utils.c ./utils/initialize_arrays.c \
	   ./algorithm/simple_algo.c ./algorithm/algo_utils.c \
	   ./algorithm/complex_algo.c lis.c \

FLAGS = 

CC = @gcc ${FLAGS}
RM = @rm -f

OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) -g -c $< -o ${<:.c=.o}

		
$(NAME): $(OBJS) $(LIBFT)
	@make -C $(LIBFT)
	$(CC) $(OBJS) 	Libft/libft.a -o $(NAME)

all: $(NAME)
	@make -C $(LIBFT)

clean:
	${RM} ${OBJS}
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)
	${RM} ${NAME}
	
re: fclean all

.PHONY: all clean fclean re