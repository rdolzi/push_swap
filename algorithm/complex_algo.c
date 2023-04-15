/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:39:16 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/15 16:01:13 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//  ./push_swap 11 7 3 -6 5 10 -3 -2  bug
void complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	printf("\n--PREstack_a(SIZE:%d)--\n", stack_a->size);
	test_print_stack(stack_a);
	printf("\n--PREstack_b(SIZE:%d)--\n", stack_b->size);
	test_print_stack(stack_b);
	lis(stack_a, stack_b);
	printf("\n--POSTstack_a(SIZE:%d)--\n", stack_a->size);
	test_print_stack(stack_a);
	printf("\n--POSTstack_b(SIZE:%d)--\n", stack_b->size);
	test_print_stack(stack_b);
}
