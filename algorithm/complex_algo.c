/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:39:16 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/29 15:09:50 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void test_print_moves(t_moves *m)
{
	printf("\nmoves_a:%d, \nmoves_b:%d\n", m->moves_a, m->moves_b);
	printf("dir_a:%d, \ndir_b:%d\n, \nidx_b:%d\n", m->dir_a, m->dir_b, m->idx_b);
}

void push_top_b(t_stack *st_a, t_stack *st_b, t_moves *moves)
{
	if (moves->idx_b == 0)
		return;
	else if (moves->dir_b == 1)
	{
		while (moves->moves_b-- > 0)
		{
			if (moves->dir_a == 1 && moves->moves_a > 0)
			{
				rrr(st_a, st_b);
				moves->moves_a--;
			}
			else
				rrb(st_b);
		}
	}
	else
	{
		while (moves->moves_b-- > 0)
		{
			if ((moves->dir_a == -1 && moves->moves_a > 0))
			{
				rr(st_a, st_b);
				moves->moves_a--;
			}
			else
				rb(st_b);
		}
	}
}

// restituisce index del min value
int find_min(t_stack *stack)
{
	int i;
	int min_index;

	i = -1;
	min_index = 0;
	while (++i < stack->size)
	{
		if (stack->array[min_index] < stack->array[i])
			min_index = i;
	}
	return (min_index);
}

int find_min_with(t_stack *stack, int nbr)
{
	int i;
	int distance_first;
	int distance_second;
	int min_index;

	i = -1;
	distance_first = 1000;
	min_index = 0;
	while (++i < stack->size)
	{
		distance_second = nbr - stack->array[i];
		if (distance_second < 0)
			distance_second *= -1;
		if (distance_second > 0 && distance_second < distance_first)
		{
			distance_first = distance_second;
			min_index = i;
		}
	}
	return (min_index);
}

// // V3 con inserimento t_moves
// // ./push_swap 11 7 3 113 5 10 4 2 14  45 56 150 > test.txt (non gira per il nbr 2)
// void push_a(t_stack *stack_a, t_stack *stack_b, t_moves *move)
// {
// 	int i;
// 	int nbr;

// 	i = -1;
// 	nbr = stack_b->array[0];
// 	while (++i < stack_a->size)
// 	{
// 		printf("\nnbr:%d|array[i(%d)]:%d|array[i + i]:%d\n", nbr,i, stack_a->array[i], stack_a->array[i + 1]);
// 		if (nbr > stack_a->array[i] && nbr < stack_a->array[i + 1])
// 		{
// 			if (i > stack_a->size / 2)
// 			{
// 				printf("1\n");
// 				while (move->moves_a-- > 0)
// 					ra(stack_a);
// 			}
// 			else
// 			{
// 				printf("2\n");
// 				while (move->moves_a-- > 0)
// 					rra(stack_a);
// 			}
// 			break;
// 		}
// 		else
// 		{
// 			if (find_min_with(stack_a, nbr) > (stack_a->size / 2))
// 			{
// 				printf("3\n");
// 				while (move->moves_a-- > 0)
// 					ra(stack_a);
// 			}
// 			else
// 			{
// 				printf("4\n");
// 				while (move->moves_a-- > 0)
// 					rra(stack_a);
// 			}
// 			break;
// 		}
// 	}
// 	pa(stack_a, stack_b);
// }

// V3  split del while
// ./push_swap 11 7 3 113 5 10 4 2 14  45 56 150 > test.txt (non gira per il nbr 2)
void push_a(t_stack *stack_a, t_stack *stack_b, t_moves *move)
{
	int i;
	int nbr;

	i = -1;
	nbr = stack_b->array[0];
	while (++i < stack_a->size)
	{
		if (move->dir_a == -1)
		{
			while (move->moves_a-- > 0)
				ra(stack_a);
		}
		else
		{
			while (move->moves_a-- > 0)
				rra(stack_a);
		}
		break;
	}
	pa(stack_a, stack_b);
}

void sort_a(t_stack *stack)
{
	int moves;
	int min_idx;

	min_idx = find_min(stack);
	if (min_idx > stack->size / 2)
	{
		moves = stack->size - min_idx - 1;
		while (moves-- > 0)
			rra(stack);
	}
	else
	{
		moves = min_idx;
		while (moves-- >= 0)
			ra(stack);
	}
}

//  ./push_swap 11 7 3 -6 5 10 -3 -2  bug
void complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int len;
	t_moves *moves;
	int index_to_move;

	moves = malloc(sizeof(*moves));
	lis(stack_a, stack_b);
	/// printf("\n--POST LIS stack_a(SIZE:%d)--\n", stack_a->size);
	/// test_print_stack(stack_a);
	/// printf("\n--POST LIS stack_b(SIZE:%d)--\n", stack_b->size);
	/// test_print_stack(stack_b);
	len = stack_b->size;
	while (len-- > 0)
	{
		moves = calculate_moves(stack_a, stack_b, moves);
		push_top_b(stack_a, stack_b, moves);
		push_a(stack_a, stack_b, moves);
		/// printf("\n--POST MOVES stack_a(SIZE:%d)--\n", stack_a->size);
		/// test_print_stack(stack_a);
		/// printf("\n--POST MOVES stack_b(SIZE:%d)--\n", stack_b->size);
		/// test_print_stack(stack_b);
		free(moves);
	}
	sort_a(stack_a);
	exit_program(stack_a, stack_b, moves);
	// printf("STACK_A SORTED\n");
	// test_print_stack(stack_a);
} // ./push_swap 11 1 3 2 4 5 9 6 10 12 8 7
