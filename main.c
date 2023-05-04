/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:10:15 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 04:37:24 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// BONUS:
// If after executing those instructions, the stack a is actually
// sorted and the stack b is empty, then the program must display
//"OK" followed by a ’\n’ on the standard output.
// verificare che per empty si intende index zero null(?)

// ./push_swap -11 7 3 6 5 10 -3 -2 -10 -6 9 1 4
// leaks --atExit -- ./push_swap 0 -1 2 -5 7
// ./push_swap -11 7 3 6 5 10 -3 -2 -1
// come verificare che la string e'maggiore del max int?
//  verifica max/min int > gestire atoi con long long
//  limite mosse(per voto massimo scegliere il tier minore):
//  1. 3   2-3  mosse
//  2. 5   8-12 mosse
//  3. 100 700-900 mosse
//  4. 500 5500-7000 mosse

// TODO:
//  pre push: remove test in .h && <stdio>
//  norminette + 2func over 25 lines
//  checker
// 	input 
int	main(int argc, char **argv)
{
	int		a;
	t_stack	stack_a;
	t_stack	stack_b;

	a = argc;
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
	if (a < 2)
		free(argv);
	exit(0);
}
