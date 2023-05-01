/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:13:20 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/01 19:07:09 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// controlla se il numero e' presente in lis
int is_in_lis(int nb, t_stack *lis)
{
	int i;
	int len;

	i = -1;
	len = lis->size;
	while (++i < len)
	{
		if (lis->array[i] == nb)
			return (1);
	}
	return (0);
}

// mando avanti(ra || rra) n volte finche non posso fare pb
int shuffle_a(t_stack *st_a, t_stack *lis)
{
	int i;
	int index;

	i = -1;
	index = -1;
	//printf("%d\n", st_a->size);
	while (++i < st_a->size / 2 + st_a->size % 2)
	{
		//printf("E\n");
		if (is_in_lis(st_a->array[i], lis))
		{
			index = i;
			break;
		}
		if (is_in_lis(st_a->array[st_a->size - i - 1], lis))
		{
			index = i;
			break;
		}
	}
	return (index);
}

// restituisce il valore dell elemento medio, ovvero con index 249
// int	get_medium(t_stack *st_a)
// {

// }


void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

// void	shuffle_b(t_stack *st_b)
// {
// 	int nbr;

// 	nbr = st_b->array[0];
// 	if (st_b->size > 1 && nbr < st_b->array[1])
// 		rb(st_b);
// }

int *ft_copy(t_stack *st_a)
{
	int i;
	int *copy;

	i = -1;
	copy = malloc(st_a->size * sizeof(int));
	while (++i < st_a->size)
		copy[i] = st_a->array[i];
	return (copy);
}

// Push elementi di STACK_A, non presenti in LIS, in STACK_B.
void push_lis(t_stack *stack_a, t_stack *stack_b, t_stack *lis)
{
	int i;
	int len;

	i = 0;
	len = stack_a->size - lis->size;
	int *copy = ft_copy(stack_a);
	ft_sort_int_tab(copy, stack_a->size);
	int med;

	med = copy[stack_a->size / 2];
	free(copy);
	/// printf("\n stack_a->size:%d, lis->size:%d\n", stack_a->size, lis->size);
	/// printf("len:%d (elem to move)\n", len);
	while (len > 0)
	{
		/// printf("\n---LEN:%d---\n",len);
		/// printf("\nstack_a->size:%d\n", stack_a->size);
		if (!is_in_lis(stack_a->array[0], lis))
		{
			/// printf("stack_a->array[0]:%d", stack_a->array[0]);
			pb(stack_a, stack_b);
			//shuffle_b(stack_b);
			if (stack_b->array[0] < med)
				rb(stack_b);
			/// printf("\n--,stack_a--\n");
			/// test_print_stack(stack_a);
			/// printf("\n--,stack_b--\n");
			/// test_print_stack(stack_b);
			len--;
		}
		else if (!is_in_lis(stack_a->array[1], lis))
		{
			/// printf("stack_a->array[0]:%d", stack_a->array[0]);
			ra(stack_a);
			pb(stack_a, stack_b);
			//shuffle_b(stack_b);
			if (stack_b->array[0] < med)
				rb(stack_b);
			/// printf("\n--,stack_a--\n");
			/// test_print_stack(stack_a);
			/// printf("\n--,stack_b--\n");
			/// test_print_stack(stack_b);
			len--;
		}
		else if (!is_in_lis(stack_a->array[stack_a->size - 1], lis))
		{
			/// printf("stack_a->array[0]:%d", stack_a->array[0]);
			rra(stack_a);
			pb(stack_a, stack_b);
			//shuffle_b(stack_b);
			if (stack_b->array[0] < med)
				rb(stack_b);
			/// printf("\n--,stack_a--\n");
			/// test_print_stack(stack_a);
			/// printf("\n--,stack_b--\n");
			/// test_print_stack(stack_b);
			len--;
		}
		else
		{
		//  ra(stack_a); // per ottimizzare usare anche rra
			i = shuffle_a(stack_a, lis);
			if (i == -1)
				break ;
			if (i > stack_a->size / 2)
			{
				// i = stack_a->size - i;
				// while (i > 0)
				// {
					rra(stack_a);
				// 	i--;
				// }
			}
			else
			{
				// while (i > 0)
				// {
					ra(stack_a);
				// 	i--;
				// }
			}
		// 	pb(stack_a, stack_b);
		// 	len--;
		}
	}
	free(lis->array);
	free(lis);
}

//./push_swap -11 7 3 6 5 10 -3 -2 -1
// restituisce un array che contiene tutti gli elementi in ordine crescenti
//  dello stack_a partendo dal index indicato, size volte
// N.B: Se index arriva alla fine ricomincia circolarmente dal primo
// il t_stack ritornato avra':
//  1. dimensione dell array == stack_a
//  2. size data dall effettiva lunghezza dell array;
t_stack *setup_stack(t_stack *stack_a, int start_index)
{
	t_stack *stack;

	stack = malloc(sizeof(stack));
	if (!stack)
		exit(1);
	stack->array = malloc(stack_a->size * sizeof(int));
	if (!stack->array)
		exit(1);
	stack->array[0] = stack_a->array[start_index];
	stack->size = 1;
	return (stack);
}

t_stack *get_sequence(t_stack *stack_a, int count, int start_index)
{
	int i;
	int j;
	t_stack *stack;

	i = 0;
	j = start_index;
	stack = setup_stack(stack_a, start_index);
	// printf("\n>STARRT INDEX%d<\n", j);
	// printf("\n>:stack->array[0]:%d<\n", stack->array[0]);
	while (count-- > 0)
	{
		// printf("\n>>j:%d||count:%d<<\n", j, count);
		if (stack_a->array[j] > stack->array[i])
		{
			// printf("IF get_sequence|i:%d,j:%d stack_a->array[j]>%d, stack->array[i]%d", i, j, stack_a->array[j], stack->array[i]);
			stack->array[++i] = stack_a->array[j++];
			stack->size++;
			if (j == stack_a->size)
				j = 0;
		}
		else
		{
			if (j + 1 == stack_a->size)
				j = -1;
			j++;
		}
	}
	// printf("\n--get_sequence--\n");
	// test_print_stack(stack);
	// printf("\n");
	return (stack);
}

// tra tutte le sequenze ritorna quella piu grande.
// quindi le confronta due allavolta.
void lis(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	t_stack *a;
	t_stack *b;

	i = 0;
	a = get_sequence(stack_a, stack_a->size, i);
	/// printf("--STILL get_sequence--\n");
	while (++i < stack_a->size)
	{
		b = get_sequence(stack_a, stack_a->size, i);
		/// printf("--NEXT ONE get_sequence--\n");
		if (b->size > a->size)
		{
			free(a->array);
			free(a);
			/// printf("\nIF>b->size:%d||a->size:%d \n", b->size, a->size);
			a = b;
		}
		else
		{
			free(b->array);
			free(b);
		}
		/// printf("\nLIS:NEW MAX STACK(size:%d)\n", a->size);
		/// test_print_stack(a);
	}
	// printf("\n--last lis--\n");
	// test_print_stack(a);
	push_lis(stack_a, stack_b, a);
}
