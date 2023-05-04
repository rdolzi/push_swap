/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:12:15 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 19:15:22 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// controlla se il numero e' presente in lis
int	is_in_lis(int nb, t_stack *lis)
{
	int	i;
	int	len;

	i = -1;
	len = lis->size;
	while (++i < len)
	{
		if (lis->array[i] == nb)
			return (1);
	}
	return (0);
}

// mando avanti(ra || rra) n volte finche non posso fare pb
int	shuffle_a(t_stack *st_a, t_stack *lis)
{
	int	i;
	int	index;

	i = -1;
	index = -1;
	while (++i < st_a->size / 2 + st_a->size % 2)
	{
		if (is_in_lis(st_a->array[i], lis))
		{
			index = i;
			break ;
		}
		if (is_in_lis(st_a->array[st_a->size - i - 1], lis))
		{
			index = i;
			break ;
		}
	}
	return (index);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
