/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:44:47 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/05 23:05:36 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

//SWAP
void	sa(int *stack_a);
void	sb(int *stack_b);
void	ss(int *stack_a, int *stack_b);

//ROTATE
void	ra(int *stack_a);
void	rb(int *stack_b);
void	rr(int *stack_a, int *stack_b);

//REVERSE_ROTATE
void	rra(int *stack_a);
void	rrb(int *stack_b);
void	rrr(int *stack_a, int *stack_b);

//PUSH
void	pa(int *stack_a, int *stack_b);
void	pb(int *stack_a, int *stack_b);

//UTILS
void	fill_stack(int *stack_a, char **argv, int len);
void	initialize_arrays(int *stack_a, int *stack_b, char **argv, int *len);
char    **compute_input(int argc, char **argv);

#endif