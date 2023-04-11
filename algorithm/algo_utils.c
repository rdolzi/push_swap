/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:52:12 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/11 20:21:41 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//restituisce un array che contiene tutti gli elementi in ordine crescenti
// dello stack_a partendo dal index indicato, size volte
//N.B: Se index arriva alla fine ricomincia circolarmente dal primo 
//il t_stack ritornato avra':
// 1. dimensione dell array == stack_a
// 2. size data dall effettiva lunghezza dell array;
t_stack	*get_sequence(t_stack *stack_a, int start_index)
{
	int		i;
	int		j;
	t_stack	*stack;

	i = 0;
	j = 0;
	stack = malloc(sizeof(stack));
	if (!stack)
		exit(1);
	stack->array = malloc(stack_a->size * sizeof(int));
	stack->array[i] = stack_a->array[i];
	while (i < stack_a->size)
	{
		j = 0;
		while (j < stack_a->size)
		{
			if (stack_a->array[j] > stack->array[i])
				stack->array[i++] = stack_a->array[j++];
			else
				j++;
		}
		i++;
	}
	stack->size = i;
	return (stack);
}

//tra tutte le sequenze ritorna quella piu grande.
//quindi le confronta due allavolta.
t_stack	*lis(t_stack *stack_a)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 0;
	a = get_sequence(stack_a, 0);
	while (++i < stack_a->size)
	{
		b = get_sequence(stack_a, i);
		if (b->size > a->size)
		{
			a = b;
			free(a->array);
		}
		else
			free(b->array);
	}
}

int get_min_index(t_stack *stack)
{
	int i;
	int min;

	i = -1;
	min = 0;
	// printf("|%x|%p|", stack->size, stack->size);
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
