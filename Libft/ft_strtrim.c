/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:55:07 by rdolzi            #+#    #+#             */
/*   Updated: 2023/01/24 14:12:44 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_in_string(char c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*strcast;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && is_in_string(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && is_in_string(s1[j], set))
		j--;
	strcast = (char *)malloc((j - i + 2) * sizeof(char));
	if (!strcast)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		strcast[k++] = s1[i];
		i++;
	}
	strcast[k] = '\0';
	return (strcast);
}
