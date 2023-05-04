/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:52:12 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 18:59:30 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// restituisce index del min value
int	find_min(t_stack *stack)
{
	int	i;
	int	min_index;

	i = -1;
	min_index = 0;
	while (++i < stack->size)
	{
		if (stack->array[min_index] < stack->array[i])
			min_index = i;
	}
	return (min_index);
}

int	get_min_index(t_stack *stack)
{
	int	i;
	int	min;

	i = -1;
	min = 0;
	while (++i < stack->size)
	{
		if (stack->array[i] < stack->array[min])
			min = i;
	}
	return (min);
}

int	get_max_index(t_stack *stack)
{
	int	i;
	int	max;

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
void	exit_program(t_stack *stack_a, t_stack *stack_b, t_moves *moves)
{
	if (stack_a->array)
		free(stack_a->array);
	if (stack_b->array)
		free(stack_b->array);
	if (moves)
		free(moves);
}
