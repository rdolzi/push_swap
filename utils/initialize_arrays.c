/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_arrays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:53:46 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 04:40:43 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_duplicate(t_stack *st_a)
{
	int	i;
	int	j;

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

void	initialize_stack(t_stack *stack, int *len)
{
	stack->size = *len;
	stack->array = malloc(stack->size * sizeof(int));
	if (!stack->array)
		exit(write(1, "Error\n", 6));
}

void	fill_stack(int *stack_a, char **argv, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		stack_a[i] = ft_atoi(argv[i]);
}

// determina se l input viene passato come variabile
// o come semplice parametro.
// se e'caso 1 modifica argc e argv, altrimenti setta solo argc
char	**compute_input(int *argc, char **argv)
{
	int		i;
	char	**matrix;

	i = 0;
	if (*argc == 2)
	{
		matrix = ft_split(argv[1], ' ');
		while (matrix[i])
			i++;
		*argc = i;
		return (matrix);
	}
	else
		*argc -= 1;
	return (++argv);
}
