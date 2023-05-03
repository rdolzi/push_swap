NAME = push_swap
LIBFT = ./libft
SRCS = main.c ./rules/push.c ./rules/swap.c \
	   ./rules/rotate.c ./rules/reverse_rotate.c \
	   ./utils/initialize_arrays.c \
	   ./algorithm/simple_algo.c ./algorithm/algo_utils.c \
	   ./algorithm/complex_algo.c ./algorithm/lis_algo.c \
	   ./algorithm/greedy_algo.c \

SRCS_BONUS = ./checker_dir/rules/rotate_c.c ./checker_dir/rules/reverse_rotate_c.c \
	   ./checker_dir/rules/swap_c.c  ./checker_dir/rules/push_c.c \
	   ./checker_dir/get_next_line.c ./checker_dir/get_next_line_utils.c \
	   ./checker_dir/checker.c \

FLAGS = -Wextra -Werror -Wall

CC = @gcc ${FLAGS}
RM = @rm -f

OBJS = ${SRCS:.c=.o}


OBJS = ${SRCS:.c=.o}


OBJS_BONUS = ${SRCS_BONUS:.c=.o}


bonus: $(OBJS) $(OBJS_BONUS) $(LIBFT) 
	@make -C $(LIBFT)
	$(CC) $(OBJS) $(OBJS_BONUS) Libft/libft.a -o $(NAME)
	$(CC) ./checker_dir/checker.c $(OBJS) Libft/libft.a $(OBJS_BONUS) -o checker



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