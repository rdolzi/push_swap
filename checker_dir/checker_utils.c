/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:30:21 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/13 22:07:39 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	checker_order(t_stack *st_a)
{
	int	i;

	i = 0;
	while (i < (st_a->size - 1) && st_a->array[i] < st_a->array[i + 1])
		i++;
	if (i == st_a->size - 1)
		return (1);
	return (0);
}

void	print_ok_ko(t_stack *st_a, t_stack *st_b)
{
	if (st_b->size != 0 || !checker_order(st_a))
		write(1, "KO\n", 3);
	else if (checker_order(st_a))
		write(1, "OK\n", 3);
}
