/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:54:49 by rdolzi            #+#    #+#             */
/*   Updated: 2023/01/23 16:56:11 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	size_t	slen;
	size_t	i;

	i = 0;
	ch = (char) c;
	slen = ft_strlen(s);
	while (i <= slen)
	{
		if (s[i] == ch)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
