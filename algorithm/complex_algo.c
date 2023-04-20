/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:39:16 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/20 21:35:07 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
void push_top_b(t_stack *st_b, int index)
{
	int moves;

	if (index == 0)
		return;
	if (index > st_b->size / 2)
	{
		moves = st_b->size - index;
		while (moves-- > 0)
			rrb(st_b);
	}
	else
	{
		moves = index;
		while (moves-- >= 0)
			rb(st_b);
	}
	// printf("\n--POST push_to_b--\n");
	// test_print_stack(st_b);
}
*/

void test_print_moves(t_moves *m)
{
	printf("\nmoves_a:%d, \nmoves_b:%d\n", m->moves_a, m->moves_b);
	printf("dir_a:%d, \ndir_b:%d\n, \nidx_b:%d\n", m->dir_a, m->dir_a, m->idx_b);
}

// NEW > TO TEST
void push_top_b(t_stack *st_a, t_stack *st_b, t_moves *moves)
{
	// test_print_moves(moves);
	if (moves->idx_b == 0)
		return;
	if (moves->dir_b == 1)
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
		while (moves->moves_b-- >= 0)
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
	// printf("\n--POST push_to_b--\n");
	// test_print_stack(st_b);
}

// simile a moves_a ma esegue lo shuffle dello stack_a, che alla fine
// si trova nella posizione corretta per inserimento di B[0], che inserisce.
void push_a(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int nbr;
	int moves;

	i = -1;
	nbr = stack_b->array[0];
	moves = 0;
	// if (!moves_a(stack_a, nbr))
	// 	{
	// 		printf("\nin out IF\n");
	// 		pa(stack_a, stack_b);
	// 		return ;
	// 	}
	while (++i < stack_a->size)
	{
		/// printf("\nnbr:%d|array[%d]:%d|array[size - 1]:%d\n", nbr,i, stack_a->array[i], stack_a->array[stack_a->size - 1]);
		// z./push_swap 6 2 1 3 4 5
		if (nbr > stack_a->array[i] && nbr < stack_a->array[i + 1])
		{
			/// printf("xxx");
			if (i > stack_a->size / 2)
			{
				moves = stack_a->size - i - 1;
				while (moves-- > 0)
					rra(stack_a);
			}
			else
			{
				moves = i + 1;
				while (moves-- > 0)
					ra(stack_a);
			}
			break;
		}
		else
		{
			if (nbr < stack_a->array[i] && nbr < stack_a->array[i + 1] && stack_a->array[i] > stack_a->array[i + 1])
			{
				/// printf("yyy");
				if (i > stack_a->size / 2)
				{
					moves = stack_a->size - i - 1;
					while (moves-- > 0)
						rra(stack_a);
				}
				else
				{
					moves = i + 1;
					while (moves-- > 0)
						ra(stack_a);
				}
				break;
			}
		}
	}
	// printf("\nafter WHILE\n");
	pa(stack_a, stack_b);
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

void sort_a(t_stack *stack)
{
	int moves;
	int min_idx;

	// test_print_stack(stack);
	min_idx = find_min(stack);
	// printf("MIN_IDX:%d", min_idx);
	if (min_idx > stack->size / 2)
	{
		moves = stack->size - min_idx - 1;
		// printf("MOVES,if:%d", moves);
		while (moves-- > 0)
		{
			// printf("move:%d", moves);
			rra(stack);
		}
	}
	else
	{
		moves = min_idx;
		// printf("MOVES,else:%d", moves);
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
	// printf("\n--PREstack_a(SIZE:%d)--\n", stack_a->size);
	// test_print_stack(stack_a);
	// printf("\n--PREstack_b(SIZE:%d)--\n", stack_b->size);
	// test_print_stack(stack_b);
	lis(stack_a, stack_b);
	// printf("\n--POSTstack_a(SIZE:%d)--\n", stack_a->size);
	// test_print_stack(stack_a);
	// printf("\n--POSTstack_b(SIZE:%d)--\n", stack_b->size);
	// test_print_stack(stack_b);
	len = stack_b->size;
	while (len-- > 0)
	{
		moves = calculate_moves(stack_a, stack_b, moves);
		push_top_b(stack_a, stack_b, moves);
		push_a(stack_a, stack_b);
		/*
		index_to_move = calculate_moves(stack_a, stack_b);
		push_top_b(stack_b, index_to_move);
		push_a(stack_a, stack_b);
		*/
	}
	sort_a(stack_a);
}
