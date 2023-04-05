/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:12:47 by rdolzi            #+#    #+#             */
/*   Updated: 2023/01/23 14:54:05 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;
	int	check_sign;

	i = 0;
	check_sign = 0;
	sign = 1;
	result = 0;
	while (str[i] && is_space(str[i]))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign *= -1;
		check_sign++;
	}
	if (check_sign > 1)
		return (result);
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
