/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:32:56 by rdolzi            #+#    #+#             */
/*   Updated: 2023/04/05 23:01:30 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_word(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			ret++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (ret);
}

void	*free_all(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
		free (s[i]);
	free (s);
	return (NULL);
}

char	**end_str(char **str, int i)
{
	str[i] = 0;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	ret = malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (!ret)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, len);
			if (!ret[i - 1])
				return (free_all(ret));
		}
		else
			s++;
	}
	return (end_str(ret, i));
}
