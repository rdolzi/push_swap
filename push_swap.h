/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:44:47 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/04 12:20:28 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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

#endif