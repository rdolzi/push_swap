/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:52:12 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/12 14:13:28 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//./push_swap 11 7 3 6 5 10 -3 -2 -1
// restituisce un array che contiene tutti gli elementi in ordine crescenti
//  dello stack_a partendo dal index indicato, size volte
// N.B: Se index arriva alla fine ricomincia circolarmente dal primo
// il t_stack ritornato avra':
//  1. dimensione dell array == stack_a
//  2. size data dall effettiva lunghezza dell array;
t_stack *get_sequence(t_stack *stack_a, int start_index)
{
	int i;
	int j;
	int count;
	t_stack *stack;

	count = stack_a->size;
	i = 0;
	j = start_index;
	printf("\n>STARRT INDEX%d<\n", j);
	stack = malloc(sizeof(stack));
	if (!stack)
		exit(1);
	stack->array = malloc(stack_a->size * sizeof(int));
	stack->array[i] = stack_a->array[j];
	stack->size = 1;
	printf("\n>:stack->array[0]:%d<\n", stack->array[0]);
	while (count > 0)
	{
		printf("\n>>j:%d||count:%d<<\n", j, count);
		if (stack_a->array[j] > stack->array[i])
		{
			printf("IF get_sequence");
			stack->array[++i] = stack_a->array[j];
			if (j + 1 == stack_a->size)
				j = 0;
			stack->size++;
			count--;
		}
		else
		{
			if (j + 1 == stack_a->size)
				j = -1;
			j++;
			count--;
		}
	}
	printf("\n--get_sequence--\n");
	test_print_stack(stack);
	printf("\n");
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
	a = get_sequence(stack_a, i);
	printf("--STILL get_sequence--\n");
	test_print_stack(a);
	printf("\n");
	while (++i < stack_a->size)
	{
		b = get_sequence(stack_a, i);
		printf("--NEXT ONE get_sequence--\n");
		test_print_stack(b);
		printf("\n");
		if (b->size > a->size)
		{
			free(a->array);
			printf("\nIF>b->size:%d||a->size:%d \n", b->size, a->size);
			a = b;
		}
		else
			free(b->array);

		printf("\nLIS:NEW MAX STACK(size:%d)\n", a->size);
		test_print_stack(a);
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
	printf("\nLa lis maggiore e':\n");
	lis(stack_a);
}