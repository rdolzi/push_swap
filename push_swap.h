/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:44:47 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/11 19:26:01 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

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
void	exit_program(t_stack *stack_a, t_stack *stack_b);
void	solve_three(t_stack *stack_a);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);
void	complex_sort(t_stack *stack_a, t_stack *stack_b);
t_stack	*lis(t_stack *stack_a);
t_stack	*get_sequence(t_stack *stack_a, int start_index);

// TEST
void	test_print_stack(t_stack *stack);
void	test_swap(t_stack *stack_a, t_stack *stack_b);
void	test_rotate(t_stack *stack_a, t_stack *stack_b);
void	test_reverse_rotate(t_stack *stack_a, t_stack *stack_b);
void	test_push(t_stack *stack_a, t_stack *stack_b);
#endif