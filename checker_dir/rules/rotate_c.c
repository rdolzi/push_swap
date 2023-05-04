/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:28:07 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 04:44:12 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// ra (rotate a):
//     Shift up all elements of stack a by 1.
//     The first element becomes the last one.
void	ra_c(t_stack *st_a)
{
	int	i;
	int	temp;

	i = -1;
	temp = st_a->array[0];
	while (++i < st_a->size)
		st_a->array[i] = st_a->array[i + 1];
	st_a->array[st_a->size - 1] = temp;
}

// rb (rotate b):
//     Shift up all elements of stack b by 1.
//     The first element becomes the last one.
void	rb_c(t_stack *st_b)
{
	int	i;
	int	temp;

	i = -1;
	temp = st_b->array[0];
	while (++i < st_b->size)
		st_b->array[i] = st_b->array[i + 1];
	st_b->array[st_b->size - 1] = temp;
}

// rr : ra and rb at the same time.
void	rr_c(t_stack *st_a, t_stack *st_b)
{
	int	i;
	int	temp;

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
}
