/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:10:15 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/07 03:25:17 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO:
// 1.  In lettura:
//     a. Ci sono almeno 2 argomenti
//     b. Gli argomenti sono tutti numeri, ovvero sono
//        convertibili in int da func ft_atoi
//     c. I numeri possono essere positivi o negativi.
//     d. I numeri non possono essere duplicati
//	   e. Contare il numero di elementi con argc
// 2.  Dopo aver convertito i numeri, è necessario
//     contare quanti sono per initializzazione dei stack.
// 3.  Cosa significa (give the prompt back) in caso non ci siano parametri ??
// 4.  Gestione errori numeri:
//     it must display "Error" followed by a ’\n’ on the standard error.
//     Errors include:
//         A. some arguments aren’t integers
//         B. some arguments are bigger than an integer 
//         C. there are duplicates.

// SUBJECT
// You have 2 stacks named a and b.
// • At the beginning:
//     1. The stack a contains a random amount of negative 
//     and/or positive numbers which cannot be duplicated.
//     2. The stack b is empty.
// • The goal is to sort in ascending order numbers into stack a.

// 3. You have to write a program named push_swap that takes as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).

// 4. Instructions must be separated by a ’\n’ and nothing else. ????

// 5. If no parameters are specified, the program must not display anything and give the prompt back.

// 6. In case of error, it must display "Error" followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer and/or there are duplicates.

// BONUS:
// If after executing those instructions, the stack a is actually sorted and the stack b is empty, then the program must display "OK" followed by a ’\n’ on the standard output.   verificare che per empty si intende index zero null(?)


//controllare validità messaggio argc == 1
//come controllare che stack_b sia vuoto durante output, va fatto il free?
//rename file initialize_arrays.c in initialize.c
//gestione input (se len == 1 bisogna usare ft_split)
//ARG="0 -1 2 -5 7"; ./push_swap $ARG
//./push_swap "0 -1 2 -5 7"
//leaks --atExit -- ./push_swap 0 -1 2 -5 7
//come verificare che la string e'maggiore del max int?
// il make non funziona sempre(make re si)
int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	(void)argv;
	if (argc == 1)
	{
		exit(0);
	}
	argv = compute_input(&argc, argv);
	initialize_stack(&stack_a, &argc);
	initialize_stack(&stack_b, &argc);
	fill_stack(stack_a.array, argv, argc);
	//to test stack_b
	fill_stack(stack_b.array, argv, argc);
	//test_swap(&stack_a, &stack_b);
	//test_print_stack(&stack_a);
	//test_rotate(&stack_a, &stack_b);
}
