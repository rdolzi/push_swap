/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:52:53 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/02 16:21:59 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void check_duplicate(t_stack *st_a)
{
	int i;
	int j;

	i = -1;
	while (++i < st_a->size)
	{
		j = i;
		while (++j < st_a->size)
		{
			if (st_a->array[j] == st_a->array[i])
				exit(write(1, "Error\n", 6));
		}
	}
}

void test_print_stack(t_stack *stack)
{
	int i = -1;
	while (++i < stack->size)
		printf("%d\n", stack->array[i]);
}
