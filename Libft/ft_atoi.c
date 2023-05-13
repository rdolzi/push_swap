/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:12:47 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/13 21:54:05 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			result = result * 10 + (str[i++] - '0');
		else
			exit(write(2, "Error\n", 6) * 0);
	}
	result *= sign;
	if (result < -2147483648 || result > 2147483647)
		exit(write(2, "Error\n", 6) * 0);
	return ((int) result);
}
