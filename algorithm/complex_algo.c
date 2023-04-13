/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:39:16 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/14 00:28:31 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*lis_stack;

	lis(stack_a, stack_a);
	printf("\n--stack_a--\n");
	test_print_stack(stack_a);
	printf("\n--stack_b--\n");
	test_print_stack(stack_b);
}
