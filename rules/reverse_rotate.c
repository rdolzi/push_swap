/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:16:51 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/07 01:20:54 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// rra (reverse rotate a): 
//     Shift down all elements of stack a by 1.
//     The last element becomes the first one.
void	rra(t_stack *stack_a)
{
	(void)stack_a;
}

// rrb (reverse rotate b): 
//     Shift down all elements of stack b by 1. 
//     The last element becomes the first one.
void	rrb(t_stack *stack_b)
{
	(void)stack_b;
}

// rrr : rra and rrb at the same time.
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
