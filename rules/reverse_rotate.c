/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:16:51 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/04 12:19:04 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a): 
//     Shift down all elements of stack a by 1.
//     The last element becomes the first one.
void	rra(int *stack_a)
{

}

// rrb (reverse rotate b): 
//     Shift down all elements of stack b by 1. 
//     The last element becomes the first one.
void	rrb(int *stack_b)
{

}

// rrr : rra and rrb at the same time.
void	rrr(int *stack_a, int *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
