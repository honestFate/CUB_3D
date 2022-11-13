/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:39:00 by fate              #+#    #+#             */
/*   Updated: 2022/11/13 10:52:13 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_close_line(char *line, int j)
{
	int	len;

	len = ft_strlen(line);
	if (len <= j)
		return (CUB_ERR);
	if (!is_inner_object(line[j])
		&& line[j] != '1')
		return (CUB_ERR);
	return (CUB_OK);
}

int	is_closed(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_inner_object(map[i][j]))
			{
				if (i == 0 || j == 0 || !map[i][j + 1] || !map[i + 1][j]
					|| (!is_inner_object(map[i][j - 1]) && map[i][j - 1] != '1')
					|| (!is_inner_object(map[i][j + 1]) && map[i][j + 1] != '1')
					|| is_close_line(map[i - 1], j)
					|| is_close_line(map[i + 1], j))
					return (UNCLOSED_MAP);
			}
		}
	}
	return (CUB_OK);
}

int	map_chceck_line(char *line, int *player_exist)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (is_player(line[j]))
		{
			if (*player_exist)
				return (TOO_MANY_PLAYERS);
			else
				++(*player_exist);
		}
		else if (!is_map_object(line[j]) && line[j] != '\t')
			return (UNKNOW_SYM);
		++j;
	}
	return (CUB_OK);
}

int	map_check_valid_sym(t_config *cfg, int start_map)
{
	int	player_exist;
	int	err;

	player_exist = 0;
	while (cfg->config_txt[start_map])
	{
		err = map_chceck_line(cfg->config_txt[start_map], &player_exist);
		if (err)
			return (err);
		++start_map;
	}
	if (!player_exist)
		return (NO_PLAYER);
	return (CUB_OK);
}

int	parse_map(t_mlx *cub, t_config *cfg, int end_of_config)
{
	int	err;

	err = map_check_valid_sym(cfg, end_of_config);
	if (err)
		return (err);
	if (copy_map(cub, cfg, end_of_config))
		return (CUB_ERR);
	err = is_closed(cub->map);
	return (err);
}
