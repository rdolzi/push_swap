/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:16:03 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/08 05:40:20 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	solve_three(t_stack *stack_a)
{
	int	min_index;
	int	max_index;
	int	distance;

	min_index = get_min_index(stack_a);
	max_index = get_max_index(stack_a);
	distance = max_index - min_index;
	if (distance == 1 || distance == -2)
	{
		sa(stack_a);
		min_index = get_min_index(stack_a);
	}
	if (min_index == 1)
		ra(stack_a);
	if (min_index == 2)
		rra(stack_a);
	//exit_program(stack_a, stack_b); non e'da chiamare qua perche la func viene utilizzata anche in s4 & s5
}

void	solve_four(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;

	min_index = get_min_index(stack_a);
	if (min_index <= 2)
	{
		while (min_index-- > 0)
			ra(stack_a);
	}
	else
		rra(stack_a);
	pb(stack_a, stack_b);
	solve_three(stack_a);
	pa(stack_a, stack_b);
}

void	solve_five(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min_index;

	i = 2;
	while (i-- > 0)
	{
		min_index = get_min_index(stack_a);
		if (min_index <= 2)
		{
			while (min_index-- > 0)
				ra(stack_a);
		}
		else
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	solve_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
//S1+2
void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 3)
		solve_three(stack_a);
	else if (stack_a->size == 4)
		solve_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		solve_five(stack_a, stack_b);
}
