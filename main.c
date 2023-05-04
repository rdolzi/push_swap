/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:10:15 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 22:10:04 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  limite mosse(per voto massimo scegliere il tier minore):
//  1. 3   2-3  mosse
//  2. 5   8-12 mosse
//  3. 100 700-900 mosse
//  4. 500 5500-7000 mosse
int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		exit(0);
	argv = compute_input(&argc, argv);
	initialize_stack(&stack_a, &argc);
	initialize_stack(&stack_b, &argc);
	stack_b.size = 0;
	fill_stack(stack_a.array, argv, argc);
	check_duplicate(&stack_a);
	if (stack_a.size <= 5)
		simple_sort(&stack_a, &stack_b);
	else
		complex_sort(&stack_a, &stack_b);
	exit(0);
}
