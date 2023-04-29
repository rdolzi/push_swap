/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:05:30 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/29 14:45:50 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sa (swap a):
//     Swap the first 2 elements at the top of stack a.
//     Do nothing if there is only one or no elements.
void sa(t_stack *stack_a)
{
	int temp;

	if (stack_a->size < 2)
		return;
	temp = stack_a->array[0];
	stack_a->array[0] = stack_a->array[1];
	stack_a->array[1] = temp;
	write(1, "sa\n", 3);
}

// sb (swap b):
// 	Swap the first 2 elements at the top of stack b.
// 	Do nothing if there is only one or no elements.
void sb(t_stack *stack_b)
{
	int temp;

	if (stack_b->size < 2)
		return;
	temp = stack_b->array[0];
	stack_b->array[0] = stack_b->array[1];
	stack_b->array[1] = temp;
	write(1, "sb\n", 3);
}

// ss : sa and sb at the same time.
void ss(t_stack *stack_a, t_stack *stack_b)
{
	int temp;

	if (stack_a->size > 2)
	{
		temp = stack_a->array[0];
		stack_a->array[0] = stack_a->array[1];
		stack_a->array[1] = temp;
	}
	if (stack_b->size > 2)
	{
		temp = stack_b->array[0];
		stack_b->array[0] = stack_b->array[1];
		stack_b->array[1] = temp;
	}
	write(1, "ss\n", 3);
}

void test_swap(t_stack *stack_a, t_stack *stack_b)
{
	printf("initial value stack_a\n");
	test_print_stack(stack_a);
	printf("initial value stack_b\n");
	test_print_stack(stack_b);
	sa(stack_a);
	printf("post swap stack_a\n");
	test_print_stack(stack_a);
	ss(stack_a, stack_b);
	printf("post swap both stacks\n");
	test_print_stack(stack_a);
	test_print_stack(stack_b);
}