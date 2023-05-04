/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:22:38 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 04:43:08 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// pa (push a):
//     Take the first element at the top of b
//     and put it at the top of a.
//     Do nothing if b is empty.
void	pa_c(t_stack *st_a, t_stack *st_b)
{
	int	i;

	if (st_b->size == 0)
		return ;
	st_a->size++;
	i = st_a->size;
	while (--i > 0)
		st_a->array[i] = st_a->array[i - 1];
	st_a->array[0] = st_b->array[0];
	st_b->size--;
	i = -1;
	while (++i < st_b->size)
		st_b->array[i] = st_b->array[i + 1];
}

// pb (push b):
//     Take the first element at the top of a
//     and put it at the top of b.
//     Do nothing if a is empty.
void	pb_c(t_stack *st_a, t_stack *st_b)
{
	int	i;

	if (st_a->size == 0)
		return ;
	st_b->size++;
	i = st_b->size;
	while (--i > 0)
		st_b->array[i] = st_b->array[i - 1];
	st_b->array[0] = st_a->array[0];
	st_a->size--;
	i = -1;
	while (++i < st_a->size)
		st_a->array[i] = st_a->array[i + 1];
}
