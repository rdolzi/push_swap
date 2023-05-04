NAME = push_swap
LIBFT = libft

SRCS = ./rules/push.c ./rules/swap.c \
	   ./rules/rotate.c ./rules/reverse_rotate.c \
	   ./utils/initialize_arrays.c ./algorithm/lis_utils.c \
	   ./algorithm/simple_algo.c ./algorithm/algo_utils.c \
	   ./algorithm/complex_algo.c ./algorithm/lis_algo.c \
	   ./algorithm/greedy_algo.c ./algorithm/algo_utils2.c \

SRCS_BONUS = ./checker_dir/rules/rotate_c.c ./checker_dir/rules/reverse_rotate_c.c \
	   ./checker_dir/rules/swap_c.c  ./checker_dir/rules/push_c.c \
	   ./checker_dir/get_next_line.c ./checker_dir/get_next_line_utils.c \
	   ./checker_dir/checker.c ./checker_dir/checker_utils.c \

FLAGS = -Wextra -Werror -Wall

CC = @gcc ${FLAGS}
RM = @rm -f

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

$(NAME): $(OBJS) 
	@make -C $(LIBFT)
	$(CC) $(OBJS) Libft/libft.a  main.c -o $(NAME)

all: $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	@make -C $(LIBFT)
	$(CC) Libft/libft.a $(OBJS) $(OBJS_BONUS) -o checker


clean:
	${RM} ${OBJS} $(OBJS_BONUS)
	@make clean -C $(LIBFT)

fclean: clean
	@make fclean -C $(LIBFT)
	${RM} ${NAME} checker
	
re: fclean all

.PHONY: all clean fclean re bonus