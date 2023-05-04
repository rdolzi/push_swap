/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:50:10 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 20:56:04 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_move_a(t_stack *stack_a, t_moves *move, int *i, int *moves)
{
	if (*i + 1 > stack_a->size / 2)
	{
		*moves = stack_a->size - *i - 1;
		move->dir_a = 1;
	}
	else
	{
		*moves = *i + 1;
		move->dir_a = -1;
	}
}

// https://www.programiz.com/dsa/greedy-algorithm
// https://www.geeksforgeeks.org/greedy-algorithms/

// TODO: Push elementi (B -> A) ottimizzando per il n° mosse
//       necessarie ad inserire l elemento nell index corretto A.
//       Verrà inserito l elemento che ha le minor mosse della seguente
//       combinazione:
//     1. Mosse per andare in B[0]
//     2. Mosse per posizionare A tale che:
//        A[0] > B[0] && A[size - 1] < B[0]

// HowTO:
//       1. Creare array int (TEMP)con size B tale che:
//          a. index TEMP == index B
//          b. value of index TEMP == mosse per inserimento
//       2. Trovare elemento con valore più basso.
//       3. Muovere in B[0] tale elemento
//       4. Ruotare A && pa(B)
int	moves_a(t_stack *stack_a, int nbr, t_moves *move)
{
	int	i;
	int	moves;

	i = -1;
	moves = 0;
	while (++i < stack_a->size)
	{
		if (nbr > stack_a->array[i] && nbr < stack_a->array[i + 1])
		{
			set_move_a(stack_a, move, &i, &moves);
			break ;
		}
		else
		{
			if (nbr < stack_a->array[i] && nbr < stack_a->array[i + 1]
				&& stack_a->array[i] > stack_a->array[i + 1])
			{
				set_move_a(stack_a, move, &i, &moves);
				break ;
			}
		}
	}
	return (moves);
}

int	moves_b(int index, int size, t_moves *move)
{
	int	moves;

	moves = 0;
	if (index > size / 2)
	{
		moves = size - index;
		move->dir_b = 1;
	}
	else
	{
		moves = index;
		move->dir_b = -1;
	}
	return (moves);
}

t_moves	*calculate_moves(t_stack *stack_a, t_stack *stack_b, t_moves *move)
{
	int	i;
	int	to_move;
	int	moves[10000];

	i = -1;
	while (++i < stack_b->size)
	{
		moves[i] = moves_a(stack_a, stack_b->array[i], move)
			+ moves_b(i, stack_b->size, move);
	}
	i = -1;
	to_move = 0;
	while (++i < stack_b->size)
	{
		if (moves[i] < moves[to_move])
			to_move = i;
	}
	move->moves_a = moves_a(stack_a, stack_b->array[to_move], move);
	move->moves_b = moves_b(to_move, stack_b->size, move);
	move->idx_b = to_move;
	return (move);
}
