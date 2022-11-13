/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:40:08 by fate              #+#    #+#             */
/*   Updated: 2022/11/13 10:40:18 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	fill_list(int fd, t_list **list)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (*line == '\n')
			free(line);
		else
		{
			++len;
			ft_lstadd_back(list, ft_lstnew(line));
		}
		line = get_next_line(fd);
	}
	return (len);
}

int	read_config(char ***config, char *path_to_cfg)
{
	int		fd;
	t_list	*list;
	int		len;

	fd = open(path_to_cfg, O_RDONLY);
	if (fd < 0)
		return (CUB_ERR);
	len = 0;
	list = NULL;
	len = fill_list(fd, &list);
	if (!len)
		return (EMPTY_FILE);
	*config = lst_to_arr(list, len);
	if (!*config || close(fd))
	{
		ft_lstclear(&list, free);
		return (CUB_ERR);
	}
	return (CUB_OK);
}
