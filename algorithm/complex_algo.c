/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:39:16 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 04:45:57 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_top_b(t_stack *st_a, t_stack *st_b, t_moves *moves)
{
	if (moves->idx_b == 0)
		return ;
	else if (moves->dir_b == 1)
	{
		while (moves->moves_b-- > 0)
		{
			if (moves->dir_a == 1 && moves->moves_a > 0)
			{
				rrr(st_a, st_b);
				moves->moves_a--;
			}
			else
				rrb(st_b);
		}
	}
	else
	{
		while (moves->moves_b-- > 0)
		{
			if ((moves->dir_a == -1 && moves->moves_a > 0))
			{
				rr(st_a, st_b);
				moves->moves_a--;
			}
			else
				rb(st_b);
		}
	}
}

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

int	find_min_with(t_stack *stack, int nbr)
{
	int	i;
	int	distance_first;
	int	distance_second;
	int	min_index;

	i = -1;
	distance_first = 1000;
	min_index = 0;
	while (++i < stack->size)
	{
		distance_second = nbr - stack->array[i];
		if (distance_second < 0)
			distance_second *= -1;
		if (distance_second > 0 && distance_second < distance_first)
		{
			distance_first = distance_second;
			min_index = i;
		}
	}
	return (min_index);
}

void	push_a(t_stack *stack_a, t_stack *stack_b, t_moves *move)
{
	int	i;
	int	nbr;

	i = -1;
	nbr = stack_b->array[0];
	while (++i < stack_a->size)
	{
		if (move->dir_a == -1)
		{
			while (move->moves_a-- > 0)
				ra(stack_a);
		}
		else
		{
			while (move->moves_a-- > 0)
				rra(stack_a);
		}
		break ;
	}
	pa(stack_a, stack_b);
}

void	sort_a(t_stack *stack)
{
	int	moves;
	int	min_idx;

	min_idx = find_min(stack);
	if (min_idx > stack->size / 2)
	{
		moves = stack->size - min_idx - 1;
		while (moves-- > 0)
			rra(stack);
	}
	else
	{
		moves = min_idx;
		while (moves-- >= 0)
			ra(stack);
	}
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		len;
	t_moves	*moves;

	moves = malloc(sizeof(*moves));
	lis(stack_a, stack_b);
	len = stack_b->size;
	while (len-- > 0)
	{
		moves = calculate_moves(stack_a, stack_b, moves);
		push_top_b(stack_a, stack_b, moves);
		push_a(stack_a, stack_b, moves);
	}
	sort_a(stack_a);
	exit_program(stack_a, stack_b, moves);
}
