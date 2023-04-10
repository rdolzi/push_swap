/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:52:12 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/09 18:33:47 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int is_min(t_stack *stack, int num)
{
	int i;
	int min;

	i = -1;
	min = num;
	while (++i < stack->size)
	{
		if (stack->array[i] < min)
			return (0);
	}
	return (1);
}

int is_max(t_stack *stack, int num)
{
	int i;
	int max;

	i = -1;
	max = num;
	while (++i < stack->size)
	{
		if (stack->array[i] > max)
			return (0);
	}
	return (1);
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

// int	get_index_distance(int min, int max)
// {
// 	return (max - min);
// }

// in uscita fa il free degli stack
void exit_program(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
	// exit(0);
}
