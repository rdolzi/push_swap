/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:57:58 by rdolzi            #+#    #+#             */
/*   Updated: 2023/01/31 16:09:09 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		j;

	if (!s)
		return (NULL);
	j = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	while (j < len)
	{
		substr[j] = s[start];
		start ++;
		j ++;
	}
	substr[j] = '\0';
	return (substr);
}
