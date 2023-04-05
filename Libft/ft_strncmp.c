/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdolzi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:41:50 by rdolzi            #+#    #+#             */
/*   Updated: 2023/01/21 12:43:03 by rdolzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	while ((us1[i] != '\0' || us2[i] != '\0') && i < n)
	{
		if (us1[i] == us2[i])
			i++;
		else
			return (us1[i] - us2[i]);
	}
	return (0);
}
