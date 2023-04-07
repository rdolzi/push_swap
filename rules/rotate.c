/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:11:51 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/07 04:04:14 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ra (rotate a): 
//     Shift up all elements of stack a by 1.
//     The first element becomes the last one.
void	ra(t_stack *st_a)
{
	int	i;
	int	temp;

	i = -1;
	temp = st_a->array[0];
	while (++i < st_a->size)
		st_a->array[i] = st_a->array[i + 1];
	st_a->array[st_a->size - 1] = temp;
}

// rb (rotate b): 
//     Shift up all elements of stack b by 1. 
//     The first element becomes the last one.
void	rb(t_stack *st_b)
{
	int	i;
	int	temp;

	i = -1;
	temp = st_b->array[0];
	while (++i < st_b->size)
		st_b->array[i] = st_b->array[i + 1];
	st_b->array[st_b->size - 1] = temp;
}

// rr : ra and rb at the same time.
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	test_rotate(t_stack *stack_a, t_stack *stack_b)
{
	printf("initial value stack_a\n");
	test_print_stack(stack_a);
	printf("initial value stack_b\n");
	test_print_stack(stack_b);
	sa(stack_a);
	printf("post swap stack_a\n");
	test_print_stack(stack_a);
	ra(stack_a);
	printf("post rotate stack_a\n");
	test_print_stack(stack_a);
	rb(stack_b);
	printf("post rotate stack_b\n");
	test_print_stack(stack_b);
	rr(stack_a, stack_b);
	printf("post rotate both stack\n");
	printf("stack_a\n");
	test_print_stack(stack_a);
	printf("stack_b\n");
	test_print_stack(stack_b);
}
