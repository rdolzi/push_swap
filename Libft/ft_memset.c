/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:38:07 by rdolzi            #+#    #+#             */
/*   Updated: 2023/01/21 12:05:05 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uchar;
	size_t			i;
	unsigned char	*d;

	d = b;
	i = 0;
	uchar = (unsigned char) c;
	while (i < len)
	{
		d[i] = uchar;
		i++;
	}
	return (b);
}
