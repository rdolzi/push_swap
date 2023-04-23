/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:50:10 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/20 23:55:28 by rdolzi           ###   ########.fr       */
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

/*  il sort funziona but not as intended
//./push_swap 12 8 -3 -5 20 1 16 2 5 -1 13 14 9 0 10 15 18 17 11 7
int moves_a(t_stack *stack_a, int nbr, t_moves *move)
{
	int i;
	int moves;

	i = -1;
	moves = 0;
	while (++i < stack_a->size)
	{
		/// printf("array[%d]:%d", i, stack_a->array[i]);
		// printf("nbr:%d|array[i]:%d|array[i + 1]:%d\n", nbr, stack_a->array[i], stack_a->array[i + 1]);
		if (nbr > stack_a->array[i] && nbr < stack_a->array[i + 1])
		{
			/// printf("XXX");
			if (i > stack_a->size / 2)
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
			{ // --> verificare con print a cosa punta "i"
				//./push_swap 11 7 3 113 5 10 -3 -2 14  45 56 150 > test.txt ..dove va 11?
				// i dovrebbe puntare a 150 per il momento.

				if (i > stack_a->size / 2)
				{
					printf("YYY");
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
*/

// v2. modifiche da apportare:

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
			printf("\ni:%d\n", i);
			if (i > stack_a->size / 2)
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
			{ // --> verificare con print a cosa punta "i"
				//./push_swap 11 7 3 113 5 10 -3 -2 14  45 56 150 > test.txt ..dove va 11?
				// i dovrebbe puntare a 150 per il momento.
				printf("---dentro caso speciale---\n");
				printf("st_a[%d]:%d\n", i, stack_a->array[i]);
				printf("nbr:%d||st_a[%d + 1]:%d\n", nbr, i, stack_a->array[i + 1]);
				if (i > stack_a->size / 2)
				{
					printf("YYY");
					moves = stack_a->size - i - 1;
					move->dir_a = 1;
				}
				else
				{
					printf("XXX");
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
	// printf("size(b):%d|index:%d", size, index);
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

/*
// non restituisce l elemento con mosse minori ma sempre index 0
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
	move = malloc(sizeof(*move));
	while (++i < stack_b->size)
	{
		m_a = moves_a(stack_a, stack_b->array[i], move);
		m_b = moves_b(i, stack_b->size, move);
		printf("\nmoves_a:%d |moves_b:%d\n", m_a, m_b);
		moves[i] = m_a + m_b;
	}
	// printf("--PRE--\n");
	// test_print_moves(move);
	i = -1;
	to_move = 0;
	printf("\n--moves--\n");
	while (++i < stack_b->size)
	{
		if (moves[i] < to_move) // -----> dovrebbe essere stack_b->array[to_move] ....
			to_move = i;
		printf("moves[%d]:%d\n", i, moves[i]);
	}
	// printf("\nmin index:%d\n", to_move);
	// test_print_stack(moves);
	//  moves_a ritorna il n mosse e setta la direzione
	move->moves_a = moves_a(stack_a, stack_b->array[to_move], move);
	// moves_b ritorna il n mosse e setta la direzione
	move->moves_b = moves_b(to_move, stack_b->size, move);
	// setta l index dell elemento di b da spostare
	move->idx_b = to_move;
	printf("\n--post--\n");
	test_print_moves(move);
	return (move);
}
*/

// V2.
// fix [√]: ora restituisce l elemento con mosse minori anziche sempre index 0
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
	move = malloc(sizeof(*move));
	while (++i < stack_b->size)
	{
		m_a = moves_a(stack_a, stack_b->array[i], move);
		m_b = moves_b(i, stack_b->size, move);
		// printf("\nmoves_a:%d |moves_b:%d\n", m_a, m_b);
		moves[i] = m_a + m_b;
	}
	// printf("--PRE--\n");
	// test_print_moves(move);
	i = -1;
	to_move = 0;
	printf("\n--moves--\n");
	while (++i < stack_b->size)
	{
		if (moves[i] < moves[to_move]) // -----> dovrebbe essere stack_b->array[to_move] ....
			to_move = i;
		printf("moves[%d]:%d\n", i, moves[i]);
	}
	printf("\nmin index:%d\n", to_move);
	// test_print_stack(moves);
	//  moves_a ritorna il n mosse e setta la direzione
	printf("---NBR:%d---\n", stack_b->array[to_move]);
	move->moves_a = moves_a(stack_a, stack_b->array[to_move], move);
	// moves_b ritorna il n mosse e setta la direzione
	move->moves_b = moves_b(to_move, stack_b->size, move);
	// setta l index dell elemento di b da spostare
	move->idx_b = to_move;
	printf("\n--post--\n");
	test_print_moves(move);
	return (move);
}