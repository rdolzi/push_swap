/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:44:47 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/13 22:06:30 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// moves_ = quante mosse deve fare;
// dir_ == -1 se deve salire(ra/rb), == +1 se deve scendere(rra/rrb)
typedef struct s_moves
{
	int	moves_a;
	int	moves_b;
	int	idx_b;
	int	dir_a;
	int	dir_b;
}	t_moves;
typedef struct s_stack
{
	int	*array;
	int	size;
}	t_stack;

// SWAP
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

// ROTATE
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

// REVERSE_ROTATE
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// PUSH
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

// UTILS
char	**compute_input(int *argc, char **argv);
void	initialize_stack(t_stack *stack, int *len);
void	fill_stack(int *stack_a, char **argv, int len);

// ALGORITHM
int		get_min_index(t_stack *stack);
int		get_max_index(t_stack *stack);
int		find_min(t_stack *stack);
void	exit_program(t_stack *stack_a, t_stack *stack_b, t_moves *moves);
void	solve_three(t_stack *stack_a);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);
void	complex_sort(t_stack *stack_a, t_stack *stack_b);
void	lis(t_stack *stack_a, t_stack *stack_b);
t_moves	*calculate_moves(t_stack *stack_a, t_stack *stack_b, t_moves *move);
int		moves_a(t_stack *stack_a, int nbr, t_moves *move);
void	check_duplicate(t_stack *st_a);
int		is_in_lis(int nb, t_stack *lis);
int		shuffle_a(t_stack *st_a, t_stack *lis);
void	ft_sort_int_tab(int *tab, int size);
int		do_things(t_stack *stack_a, t_stack *stack_b, t_stack *lis, int *len);

// TEST
// void	test_print_stack(t_stack *stack);
// void	test_swap(t_stack *stack_a, t_stack *stack_b);
// void	test_rotate(t_stack *stack_a, t_stack *stack_b);
// void	test_reverse_rotate(t_stack *stack_a, t_stack *stack_b);
// void	test_push(t_stack *stack_a, t_stack *stack_b);
// void	test_print_moves(t_moves *m);

//--CHECKER--
void	print_ok_ko(t_stack *st_a, t_stack *st_b);
int		check_order(t_stack *st_a);

// GNL
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(char *s1, char c);
size_t	ft_strlen_gnl(char *str);
void	*ft_free(char *s1, char *s2);
size_t	ft_is_newline(char c);

// SWAP
void	sa_c(t_stack *stack_a);
void	sb_c(t_stack *stack_b);
void	ss_c(t_stack *stack_a, t_stack *stack_b);

// ROTATE
void	ra_c(t_stack *stack_a);
void	rb_c(t_stack *stack_b);
void	rr_c(t_stack *stack_a, t_stack *stack_b);

// REVERSE_ROTATE
void	rra_c(t_stack *stack_a);
void	rrb_c(t_stack *stack_b);
void	rrr_c(t_stack *stack_a, t_stack *stack_b);

// PUSH
void	pa_c(t_stack *stack_a, t_stack *stack_b);
void	pb_c(t_stack *stack_a, t_stack *stack_b);
#endif