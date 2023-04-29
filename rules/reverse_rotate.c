/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:16:51 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/29 14:41:31 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rra (reverse rotate a):
//     Shift down all elements of stack a by 1.
//     The last element becomes the first one.
void rra(t_stack *st_a)
{
	int i;
	int temp;

	i = st_a->size;
	temp = st_a->array[st_a->size - 1];
	while (--i > 0)
		st_a->array[i] = st_a->array[i - 1];
	st_a->array[0] = temp;
	write(1, "rra\n", 4);
}

// rrb (reverse rotate b):
//     Shift down all elements of stack b by 1.
//     The last element becomes the first one.
void rrb(t_stack *st_b)
{
	int i;
	int temp;

	i = st_b->size;
	temp = st_b->array[st_b->size - 1];
	while (--i > 0)
		st_b->array[i] = st_b->array[i - 1];
	st_b->array[0] = temp;
	write(1, "rrb\n", 4);
}

// rrr : rra and rrb at the same time.
void rrr(t_stack *st_a, t_stack *st_b)
{
	int i;
	int temp;

	i = st_a->size;
	temp = st_a->array[st_a->size - 1];
	while (--i > 0)
		st_a->array[i] = st_a->array[i - 1];
	st_a->array[0] = temp;
	i = st_b->size;
	temp = st_b->array[st_b->size - 1];
	while (--i > 0)
		st_b->array[i] = st_b->array[i - 1];
	st_b->array[0] = temp;
	write(1, "rrr\n", 4);
}

void test_reverse_rotate(t_stack *stack_a, t_stack *stack_b)
{
	printf("initial value stack_a\n");
	test_print_stack(stack_a);
	printf("initial value stack_b\n");
	test_print_stack(stack_b);
	sa(stack_a);
	printf("post swap stack_a\n");
	test_print_stack(stack_a);
	rra(stack_a);
	printf("post reverse rotate stack_a\n");
	test_print_stack(stack_a);
	rrb(stack_b);
	printf("post reverse rotate stack_b\n");
	test_print_stack(stack_b);
	rrr(stack_a, stack_b);
	printf("post rotate both stack\n");
	printf("stack_a\n");
	test_print_stack(stack_a);
	printf("stack_b\n");
	test_print_stack(stack_b);
}
