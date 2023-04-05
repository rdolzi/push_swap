/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_arrays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:53:46 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/05 15:50:29 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_arrays(int *stack_a, int *stack_b, char **argv, int *len)
{
	stack_b = (int *) malloc(*len * sizeof(int));
	if (!stack_b)
		exit(write(1, "Error\n", 6) * 0);
}

//se errore fare i free degli array
void	fill_stack(int *stack_a, char **argv, int len)
{
	int	i;
	(void)argv;
	(void)stack_a;
	i = 0;
	while (i < len)
	{
		i++;
		//stack_a = ft_atoi((*argv)++);
	}
}
