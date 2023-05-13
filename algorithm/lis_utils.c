/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:16:02 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/13 21:15:24 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_copy(t_stack *st_a)
{
	int	i;
	int	*copy;

	i = -1;
	copy = malloc(st_a->size * sizeof(int));
	if (!copy)
		exit(write(2, "Error\n", 6));
	while (++i < st_a->size)
		copy[i] = st_a->array[i];
	return (copy);
}

int	get_med(t_stack *stack_a)
{
	int	med;
	int	*copy;

	copy = ft_copy(stack_a);
	ft_sort_int_tab(copy, stack_a->size);
	med = copy[stack_a->size / 2];
	free(copy);
	return (med);
}

void	check_rb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->array[0] < get_med(stack_a))
		rb(stack_b);
}

int	do_things(t_stack *stack_a, t_stack *stack_b, t_stack *lis, int *len)
{
	if (!is_in_lis(stack_a->array[0], lis))
	{
		pb(stack_a, stack_b);
		check_rb(stack_a, stack_b);
		return (((*len)--) * 0);
	}
	else if (!is_in_lis(stack_a->array[1], lis))
	{
		ra(stack_a);
		pb(stack_a, stack_b);
		check_rb(stack_a, stack_b);
		return (((*len)--) * 0);
	}
	else if (!is_in_lis(stack_a->array[stack_a->size - 1], lis))
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		check_rb(stack_a, stack_b);
		return (((*len)--) * 0);
	}
	return (1);
}
