/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:30:21 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 18:32:50 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_ok_ko(t_stack *st_a, t_stack *st_b)
{
	if (st_b->size != 0 || !check_order(st_a))
		write(1, "KO\n", 3);
	else if (check_order(st_a))
		write(1, "OK\n", 3);
}
