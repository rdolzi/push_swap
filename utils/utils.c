/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:52:53 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/07 00:38:05 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//https://stackoverflow.com/questions/15929869/count-the-number-of-elements-in-an-array-in-c


// determina se l input viene passato come variabile o come semplice parametro
// se e'caso 1 modifica argc e argv, altrimenti setta solo argc

void	test_print_stack(int *stack, int argc)
{
	int i = -1;
	while (++i < argc)
		printf("%d\n",stack[i]);
}

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
