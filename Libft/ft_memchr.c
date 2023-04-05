/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:43:31 by rdolzi            #+#    #+#             */
/*   Updated: 2023/01/21 17:11:10 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		ch;
	const unsigned char	*us;
	size_t				i;

	i = 0;
	ch = (unsigned char) c;
	us = (const unsigned char *) s;
	while (i < n)
	{
		if (us[i] == ch)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
