/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:46:21 by fate              #+#    #+#             */
/*   Updated: 2022/11/13 10:58:55 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_empty_line(char *line)
{
	while (is_space(*line))
		++line;
	if (!line)
		return (CUB_ERR);
	return (CUB_OK);
}

static int	custom_strlen(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			k += (4 - (k % 4));
		else
			++k;
		++i;
	}
	return (k);
}

void	copy_line(t_mlx *cub, t_config *cfg, int i, int map_start)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	k = 0;
	while (cfg->config_txt[i][j])
	{
		if (cfg->config_txt[i][j] == '\t')
		{
			l = 4 - (k % 4);
			while (l)
			{
				cub->map[i - map_start][k] = ' ';
				++k;
				--l;
			}
		}
		else
			cub->map[i - map_start][k++] = cfg->config_txt[i][j];
		++j;
	}
	cub->map[i - map_start][k] = '\0';
}

int	copy_map(t_mlx *cub, t_config *cfg, int map_start)
{
	int	i;
	int	end;

	i = map_start;
	end = -1;
	while (cfg->config_txt[i])
	{
		end = i;
		++i;
	}
	cub->map = malloc((end - map_start + 2) * sizeof(char *));
	if (!cub->map)
		return (CUB_ERR);
	i = map_start - 1;
	while (++i <= end)
	{
		cub->map[i - map_start] = (char *)
			malloc(custom_strlen(cfg->config_txt[i]) + 1);
		copy_line(cub, cfg, i, map_start);
	}
	cub->map[i - map_start] = NULL;
	return (CUB_OK);
}
