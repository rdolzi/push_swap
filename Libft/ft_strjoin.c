/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <rdolzi@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:06:57 by rdolzi            #+#    #+#             */
/*   Updated: 2023/05/05 17:36:17 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str1;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	str1 = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str1)
		return (0);
	i = -1;
	while (s1[++i])
		str1[i] = s1[i];
	j = 0;
	while (s2[j])
		str1[i++] = s2[j++];
	str1[i] = '\0';
	free(s1);
	return (str1);
}
