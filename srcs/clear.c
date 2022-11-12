/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:18:18 by gtrinida          #+#    #+#             */
/*   Updated: 2022/11/10 18:18:21 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	safe_free(void *data)
{
	if (data)
		free(data);
}

void	free_strarr(char **strings)
{
	int	i;

	i = 0;
	if (strings)
	{
		while (strings[i])
			free(strings[i++]);
		free(strings);
	}
}
