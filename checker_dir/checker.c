/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:52:46 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 02:12:25 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int main(int argc, char **argv)
{
    int a;
    t_stack stack_a;
    t_stack stack_b;
    
    a = argc;
    if (argc < 2)
        exit(0);
    argv = compute_input(&argc, argv);
	initialize_stack(&stack_a, &argc);
	initialize_stack(&stack_b, &argc);
	stack_b.size = 0;
	fill_stack(stack_a.array, argv, argc);
	check_duplicate(&stack_a);
    
    if (a < 2)
		free(argv);
    exit(0);
    
}