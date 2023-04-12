/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:52:12 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/12 15:06:53 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//./push_swap -11 7 3 6 5 10 -3 -2 -1
// restituisce un array che contiene tutti gli elementi in ordine crescenti
//  dello stack_a partendo dal index indicato, size volte
// N.B: Se index arriva alla fine ricomincia circolarmente dal primo
// il t_stack ritornato avra':
//  1. dimensione dell array == stack_a
//  2. size data dall effettiva lunghezza dell array;

t_stack *setup_stack(t_stack *stack_a, int start_index)
{
	t_stack *stack;

	stack = malloc(sizeof(stack));
	if (!stack)
		exit(1);
	stack->array = malloc(stack_a->size * sizeof(int));
	if (!stack->array)
		exit(1);
	stack->array[0] = stack_a->array[start_index];
	stack->size = 1;
	return (stack);
}

t_stack *get_sequence(t_stack *stack_a, int count, int start_index)
{
	int i;
	int j;
	t_stack *stack;

	i = 0;
	j = start_index;
	stack = setup_stack(stack_a, start_index);
	while (count-- > 0)
	{
		if (stack_a->array[j] > stack->array[i])
		{
			stack->array[++i] = stack_a->array[j++];
			if (j + 1 == stack_a->size)
				j = 0;
			stack->size++;
		}
		else
		{
			if (j + 1 == stack_a->size)
				j = -1;
			j++;
		}
	}
	return (stack);
}

// tra tutte le sequenze ritorna quella piu grande.
// quindi le confronta due allavolta.
t_stack *lis(t_stack *stack_a)
{
	int i;
	t_stack *a;
	t_stack *b;

	i = 0;
	a = get_sequence(stack_a, stack_a->size, i);
	while (++i < stack_a->size)
	{
		b = get_sequence(stack_a, stack_a->size, i);
		if (b->size > a->size)
		{
			free(a->array);
			free(a);
			a = b;
		}
		else
		{
			free(b->array);
			free(b);
		}
	}
	return (a);
}

int get_min_index(t_stack *stack)
{
	int i;
	int min;

	i = -1;
	min = 0;
	while (++i < stack->size)
	{
		if (stack->array[i] < stack->array[min])
			min = i;
	}
	return (min);
}

int get_max_index(t_stack *stack)
{
	int i;
	int max;

	i = -1;
	max = 0;
	while (++i < stack->size)
	{
		if (stack->array[i] > stack->array[max])
			max = i;
	}
	return (max);
}

// in uscita fa il free degli stack
void exit_program(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
	// exit(0);
}

void test_print_lis(t_stack *stack_a)
{
	t_stack *test;

	test = lis(stack_a);
	printf("\nLa lis maggiore e':\n");
	test_print_stack(test);
	free(test->array);
	free(test);
}