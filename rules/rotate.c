/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:11:51 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/04 17:04:23 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ra (rotate a): 
//     Shift up all elements of stack a by 1.
//     The first element becomes the last one.
void	ra(int *stack_a)
{
	(void)stack_a;

}

// rb (rotate b): 
//     Shift up all elements of stack b by 1. 
//     The first element becomes the last one.
void	rb(int *stack_b)
{
	(void)stack_b;
}

// rr : ra and rb at the same time.
void	rr(int *stack_a, int *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
