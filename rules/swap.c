/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:05:30 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/04 17:04:43 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// sa (swap a): 
//     Swap the first 2 elements at the top of stack a.
//     Do nothing if there is only one or no elements.
void	sa(int *stack_a)
{
	(void)stack_a;
}

// sb (swap b): 
// 	Swap the first 2 elements at the top of stack b.
// 	Do nothing if there is only one or no elements.
void	sb(int *stack_b)
{
	(void)stack_b;
}

// ss : sa and sb at the same time.
void	ss(int *stack_a, int *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
