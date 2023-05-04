/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:52:46 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 19:09:15 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_order(t_stack *st_a)
{
	int	i;

	i = 0;
	while (i < (st_a->size - 1) && st_a->array[i] < st_a->array[i + 1])
		i++;
	if (i == st_a->size - 1)
		return (1);
	return (0);
}

int	ft_checker(char *cmd, t_stack *st_a, t_stack *st_b)
{
	if (!ft_strncmp(cmd, "sa\n", ft_strlen(cmd)))
		sa_c(st_a);
	else if (!ft_strncmp(cmd, "sb\n", ft_strlen(cmd)))
		sb_c(st_b);
	else if (!ft_strncmp(cmd, "ss\n", ft_strlen(cmd)))
		ss_c(st_a, st_b);
	else if (!ft_strncmp(cmd, "ra\n", ft_strlen(cmd)))
		ra_c(st_a);
	else if (!ft_strncmp(cmd, "rb\n", ft_strlen(cmd)))
		rb_c(st_b);
	else if (!ft_strncmp(cmd, "rr\n", ft_strlen(cmd)))
		rr_c(st_a, st_b);
	else if (!ft_strncmp(cmd, "rra\n", ft_strlen(cmd)))
		rra_c(st_a);
	else if (!ft_strncmp(cmd, "rrb\n", ft_strlen(cmd)))
		rrb_c(st_b);
	else if (!ft_strncmp(cmd, "rrr\n", ft_strlen(cmd)))
		rrr_c(st_a, st_b);
	else if (!ft_strncmp(cmd, "pa\n", ft_strlen(cmd)))
		pa_c(st_a, st_b);
	else if (!ft_strncmp(cmd, "pb\n", ft_strlen(cmd)))
		pb_c(st_a, st_b);
	else
		return (0);
	return (1);
}

void	init_checker(int *ac, char **av, t_stack *st_a, t_stack *st_b)
{
	av = compute_input(ac, av);
	initialize_stack(st_a, ac);
	initialize_stack(st_b, ac);
	st_b->size = 0;
	fill_stack(st_a->array, av, *ac);
	check_duplicate(st_a);
}

void	exit_checker(t_stack *st_a, t_stack *st_b, int a, char **argv)
{
	exit_program(st_a, st_b, NULL);
	if (a < 2)
		free(argv);
	exit(0);
}

int	main(int argc, char **argv)
{
	int		a;
	char	*cmd;
	t_stack	stack_a;
	t_stack	stack_b;

	a = argc;
	if (argc < 2)
		exit(0);
	init_checker(&argc, argv, &stack_a, &stack_b);
	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		if (!ft_checker(cmd, &stack_a, &stack_b))
		{
			free(cmd);
			write(1, "Error\n", 6);
			exit_checker(&stack_a, &stack_b, a, argv);
		}
		free(cmd);
	}
	print_ok_ko(&stack_a, &stack_b);
	exit_checker(&stack_a, &stack_b, a, argv);
}
