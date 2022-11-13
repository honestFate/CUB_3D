/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:40:44 by fate              #+#    #+#             */
/*   Updated: 2022/11/13 10:42:25 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**lst_to_arr(t_list *list, int len)
{
	int		i;
	char	**arr;
	t_list	*ptr;

	i = -1;
	arr = ft_calloc(len + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (++i < len)
	{
		arr[i] = ft_strtrim(list->content, "\n");
		free(list->content);
		ptr = list;
		list = list->next;
		free(ptr);
	}
	return (arr);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	is_map_object(char c)
{
	if (c == ' ' || c == '0'
		|| c == '1')
		return (1);
	return (0);
}

int	is_inner_object(char c)
{
	if (is_player(c) || c == '0')
		return (1);
	return (0);
}
