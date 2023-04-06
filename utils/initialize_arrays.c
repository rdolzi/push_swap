/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_arrays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:53:46 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/07 01:08:46 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	initialize_stack(t_stack *stack, int *len)
{
	stack->size = *len;
	stack->array = (int *) malloc(stack->size * sizeof(int));
	if (!stack->array)
		exit(write(1, "Error\n", 6) * 0);
}

//se errore fare i free degli array
void	fill_stack(int *stack_a, char **argv, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		stack_a[i] = ft_atoi( argv[i]);
}

//https://stackoverflow.com/questions/15929869/count-the-number-of-elements-in-an-array-in-c


// determina se l input viene passato come variabile o come semplice parametro
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