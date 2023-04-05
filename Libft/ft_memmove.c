/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:15:45 by rdolzi            #+#    #+#             */
/*   Updated: 2023/01/27 16:56:40 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	len;

	len = 0;
	if (!src && !dst)
		return (NULL);
	if (src < dst)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *) dst)[len] = ((unsigned char *) src)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *) dst)[len] = ((unsigned char *) src)[len];
			len++;
		}
	}
	return (dst);
}
