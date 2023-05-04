/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:52:46 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/04 05:33:52 by rdolzi           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		a;
	char	*cmd;
	t_stack	stack_a;
	t_stack	stack_b;

	a = argc;
	if (argc < 2)
		exit(0);
	argv = compute_input(&argc, argv);
	initialize_stack(&stack_a, &argc);
	initialize_stack(&stack_b, &argc);
	stack_b.size = 0;
	fill_stack(stack_a.array, argv, argc);
	check_duplicate(&stack_a);
	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		if (!ft_checker(cmd, &stack_a, &stack_b))
		{
			free(cmd);
			write(1, "Error\n", 6);
			exit_program(&stack_a, &stack_b, NULL);
			if (a < 2)
				free(argv);
			exit(0);
		}
		free(cmd);
	}
	 if (stack_b.size != 0 || !check_order(&stack_a))
		write(1, "KO\n", 3);
	else if (check_order(&stack_a))
		write(1, "OK\n", 3);
	exit_program(&stack_a, &stack_b, NULL);
	if (a < 2)
		free(argv);
	exit(0);
}
