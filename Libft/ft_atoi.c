/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:12:47 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/07 00:32:55 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
		else
			exit(write(1, "Error\n", 6) * 0);
	}
	return (sign * result);
}
