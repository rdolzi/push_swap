/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_arrays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:53:46 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/13 22:06:07 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_order(t_stack *st_a)
{
	int	i;

	i = 0;
	while (i < (st_a->size - 1) && st_a->array[i] < st_a->array[i + 1])
		i++;
	if (i == st_a->size - 1)
		return (1);
	return (0);
}

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
				exit(write(2, "Error\n", 6));
		}
	}
}

void	initialize_stack(t_stack *stack, int *len)
{
	stack->size = *len;
	stack->array = malloc(stack->size * sizeof(int));
	if (!stack->array)
		exit(write(2, "Error\n", 6));
}

void	fill_stack(int *stack_a, char **argv, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		stack_a[i] = ft_atoi(argv[i]);
}

char	**compute_input(int *argc, char **argv)
{
	int		i;
	char	*str;
	char	**matrix;

	i = 0;
	str = (char *)malloc(sizeof(char));
	if (!str)
		exit(write(2, "Error\n", 6));
	str[0] = 0;
	while (++i < *argc)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
	}
	matrix = ft_split(str, ' ');
	free(str);
	i = 0;
	while (matrix[i])
		i++;
	*argc = i;
	return (matrix);
}
