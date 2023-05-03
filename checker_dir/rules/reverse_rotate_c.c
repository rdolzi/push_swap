/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:25:51 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/03 17:27:38 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// rra (reverse rotate a):
//     Shift down all elements of stack a by 1.
//     The last element becomes the first one.
void rra_c(t_stack *st_a)
{
	int i;
	int temp;

	i = st_a->size;
	temp = st_a->array[st_a->size - 1];
	while (--i > 0)
		st_a->array[i] = st_a->array[i - 1];
	st_a->array[0] = temp;
}

// rrb (reverse rotate b):
//     Shift down all elements of stack b by 1.
//     The last element becomes the first one.
void rrb_c(t_stack *st_b)
{
	int i;
	int temp;

	i = st_b->size;
	temp = st_b->array[st_b->size - 1];
	while (--i > 0)
		st_b->array[i] = st_b->array[i - 1];
	st_b->array[0] = temp;
}

// rrr : rra and rrb at the same time.
void rrr_c(t_stack *st_a, t_stack *st_b)
{
	int i;
	int temp;

	i = st_a->size;
	temp = st_a->array[st_a->size - 1];
	while (--i > 0)
		st_a->array[i] = st_a->array[i - 1];
	st_a->array[0] = temp;
	i = st_b->size;
	temp = st_b->array[st_b->size - 1];
	while (--i > 0)
		st_b->array[i] = st_b->array[i - 1];
	st_b->array[0] = temp;
}