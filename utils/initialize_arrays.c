/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_arrays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:53:46 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/04 18:39:07 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//se errore fare i free degli array
void	fill_stack(int *stack_a, char **argv, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack_a = ft_atoi((*argv)++);
	}
}
