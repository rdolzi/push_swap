/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:00:29 by rdolzi            #+#    #+#             */
/*   Updated: 2023/01/30 16:07:15 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*uchar;
	const unsigned char	*cuchar;

	if (!dst && !src)
		return (NULL);
	uchar = (unsigned char *) dst;
	cuchar = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		uchar[i] = cuchar[i];
		i++;
	}
	return (dst);
}
