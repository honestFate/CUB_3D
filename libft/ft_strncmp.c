/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:40:45 by gtrinida          #+#    #+#             */
/*   Updated: 2022/11/03 01:48:52 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*dif;
	unsigned char	*source;

	dif = (unsigned char *)s1;
	source = (unsigned char *)s2;
	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (dif[i] != source[i])
			return (dif[i] - source[i]);
		i++;
	}
	if (i != n && dif[i] == '\0')
		return (dif[i] - source[i]);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	res;

	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	res = (unsigned char)*s1 - (unsigned char)*s2;
	return (res);
}
