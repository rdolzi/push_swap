/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:28:40 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 04:44:37 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// sa (swap a):
//     Swap the first 2 elements at the top of stack a.
//     Do nothing if there is only one or no elements.
void	sa_c(t_stack *stack_a)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->array[0];
	stack_a->array[0] = stack_a->array[1];
	stack_a->array[1] = temp;
}

// sb (swap b):
// 	Swap the first 2 elements at the top of stack b.
// 	Do nothing if there is only one or no elements.
void	sb_c(t_stack *stack_b)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->array[0];
	stack_b->array[0] = stack_b->array[1];
	stack_b->array[1] = temp;
}

// ss : sa and sb at the same time.
void	ss_c(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

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
}
