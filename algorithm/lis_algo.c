/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:13:20 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 20:18:23 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Push elementi di STACK_A, non presenti in LIS, in STACK_B.
void	push_lis(t_stack *stack_a, t_stack *stack_b, t_stack *lis)
{
	int	i;
	int	len;

	i = 0;
	len = stack_a->size - lis->size;
	while (len > 0)
	{
		if (do_things(stack_a, stack_b, lis, &len))
		{
			i = shuffle_a(stack_a, lis);
			if (i == -1)
				break ;
			if (i > stack_a->size / 2)
				rra(stack_a);
			else
				ra(stack_a);
		}
	}
	free(lis->array);
	free(lis);
}

// restituisce un array che contiene tutti gli elementi in ordine crescenti
//  dello stack_a partendo dal index indicato, size volte
// N.B: Se index arriva alla fine ricomincia circolarmente dal primo
// il t_stack ritornato avra':
//  1. dimensione dell array == stack_a
//  2. size data dall effettiva lunghezza dell array;
t_stack	*setup_stack(t_stack *stack_a, int start_index)
{
	t_stack	*stack;

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

t_stack	*get_sequence(t_stack *stack_a, int count, int start_index)
{
	int		i;
	int		j;
	t_stack	*stack;

	i = 0;
	j = start_index;
	stack = setup_stack(stack_a, start_index);
	while (count-- > 0)
	{
		if (stack_a->array[j] > stack->array[i])
		{
			stack->array[++i] = stack_a->array[j++];
			stack->size++;
			if (j == stack_a->size)
				j = 0;
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
void	lis(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

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
	push_lis(stack_a, stack_b, a);
}
