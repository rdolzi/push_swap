/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:11:51 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/02 17:58:31 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ra (rotate a):
//     Shift up all elements of stack a by 1.
//     The first element becomes the last one.
void ra(t_stack *st_a)
{
	int i;
	int temp;

	i = -1;
	temp = st_a->array[0];
	while (++i < st_a->size)
		st_a->array[i] = st_a->array[i + 1];
	st_a->array[st_a->size - 1] = temp;
	write(1, "ra\n", 3);
}

// rb (rotate b):
//     Shift up all elements of stack b by 1.
//     The first element becomes the last one.
void rb(t_stack *st_b)
{
	int i;
	int temp;

	i = -1;
	temp = st_b->array[0];
	while (++i < st_b->size)
		st_b->array[i] = st_b->array[i + 1];
	st_b->array[st_b->size - 1] = temp;
	write(1, "rb\n", 3);
}

// rr : ra and rb at the same time.
void rr(t_stack *st_a, t_stack *st_b)
{
	int i;
	int temp;

	i = -1;
	temp = st_a->array[0];
	while (++i < st_a->size)
		st_a->array[i] = st_a->array[i + 1];
	st_a->array[st_a->size - 1] = temp;
	i = -1;
	temp = st_b->array[0];
	while (++i < st_b->size)
		st_b->array[i] = st_b->array[i + 1];
	st_b->array[st_b->size - 1] = temp;
	write(1, "rr\n", 3);
}
