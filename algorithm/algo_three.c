/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:16:03 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/08 01:36:39 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	solve_three(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	i;

// 	i = -1;
// 	while (i < stack_a->size)
// 	{
// 		if (is_min(stack_a->array, stack_a->array[i]))
// 		{
// 			i++;
// 			if (!is_max(stack_a->array, stack_a->array[i]))
// 				exit_program(stack_a, stack_b);
// 			else
// 			{
// 				sa(stack_a);
// 				ra(stack_a);
// 			}
// 		}
// 		else
// 		{
// 			if (is_max(stack_a->array, stack_a->array[i]))
// 			{
				
// 			}
// 		}
// 	}
// }

void	solve_three(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;
	int	max_index;
	int	distance;

	min_index = get_min_index(stack_a);
	max_index = get_max_index(stack_a);
	distance = max_index - min_index;
	if (distance == 1)
	{
		sa(stack_a);
		min_index = get_min_index(stack_a);
	}
	if (min_index == 1)
		ra(stack_a);
	if (min_index == 2)
		rra(stack_a);
	exit_program(stack_a, stack_b);
}