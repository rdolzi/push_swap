/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:50:10 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/02 17:06:55 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// https://www.programiz.com/dsa/greedy-algorithm
// https://www.geeksforgeeks.org/greedy-algorithms/

//              -----Greedy Algorithm------

// Def: A greedy algorithm is an approach for solving a problem by selecting the best option available at the moment.

// In other words: Greedy is an algorithmic paradigm that builds up a solution piece by piece, always choosing the next piece that offers the most obvious and immediate benefit. So the problems where choosing locally optimal also leads to global solution are the best fit for Greedy.

// 1. It doesn't worry whether the current best result will bring the overall optimal result.

// 2. The algorithm never reverses the earlier decision even if the choice is wrong. It works in a top-down approach.

// 3. This algorithm may not produce the best result for all the problems. It's because it always goes for the local best choice to produce the global best result.However, we can determine if the algorithm can be used with any problem if the problem has the following properties:

// 1. Greedy Choice Property

// If an optimal solution to the problem can be found by choosing the best choice at each step without reconsidering the previous steps once chosen, the problem can be solved using a greedy approach. This property is called greedy choice property.

// 2. Optimal Substructure

// If the optimal overall solution to the problem corresponds to the optimal solution to its subproblems, then the problem can be solved using a greedy approach. This property is called optimal substructure.

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

int moves_a(t_stack *stack_a, int nbr, t_moves *move)
{
	int i;
	int moves;

	i = -1;
	moves = 0;
	while (++i < stack_a->size)
	{
		if (nbr > stack_a->array[i] && nbr < stack_a->array[i + 1])
		{
			if (i + 1 > stack_a->size / 2)
			{
				moves = stack_a->size - i - 1;
				move->dir_a = 1;
			}
			else
			{
				moves = i + 1;
				move->dir_a = -1;
			}
			break;
		}
		else
		{
			if (nbr < stack_a->array[i] && nbr < stack_a->array[i + 1] && stack_a->array[i] > stack_a->array[i + 1])
			{
				if (i + 1 > stack_a->size / 2)
				{
					moves = stack_a->size - i - 1;
					move->dir_a = 1;
				}
				else
				{
					moves = i + 1;
					move->dir_a = -1;
				}
				break;
			}
		}
	}
	return (moves);
}

int moves_b(int index, int size, t_moves *move)
{
	int moves;

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

t_moves *calculate_moves(t_stack *stack_a, t_stack *stack_b, t_moves *move)
{
	int i;
	int m_a;
	int m_b;
	int to_move;
	int moves[stack_b->size];

	m_a = 0;
	m_b = 0;
	i = -1;
	while (++i < stack_b->size)
	{
		m_a = moves_a(stack_a, stack_b->array[i], move);
		m_b = moves_b(i, stack_b->size, move);
		moves[i] = m_a + m_b;
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
