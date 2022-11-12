#include "cub.h"

int	is_empty_line(char *line)
{
	while (is_space(*(line++)));
	if (!line)
		return (1);
	return (0);
}

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
	/*if (is_inner_object(map[0][0])
		&& (!map[0][1] || !map[1]))
		return (UNCLOSED_MAP);*/
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
				{
					printf("line - %d sym - %d\n", i, j);
					return (UNCLOSED_MAP);
				}
			}
		}
	}
	return (CUB_OK);
}

int map_chceck_line(char *line, int *player_exist)
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
	int err;

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

int	custom_strlen(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			printf("i = %d, k = %d, 4 - (k %% 4) = %d\n", i, k, 4 - (k % 4));
			k = k + (4 - (k % 4));
		}
		else
			++k;
		++i;
	}
	return (k);
}

int	copy_map(t_mlx *cub, t_config *cfg, int map_start)
{
	int	i;
	int	end;
	int	j;
	int	k;

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
		cub->map[i - map_start] = (char *)malloc(custom_strlen(cfg->config_txt[i]) + 1);
		printf("line - %d, calculated len - %d\n", i, custom_strlen(cfg->config_txt[i]));
		j = 0;
		k = 0;
		while (cfg->config_txt[i][j])
		{
			if (cfg->config_txt[i][j] == '\t')
			{
				int	l = 4 - (k % 4);
				while (l)
				{
					cub->map[i - map_start][k] = ' ';
					++k;
					--l;
				}
			}
			else
			{
				cub->map[i - map_start][k] = cfg->config_txt[i][j];
				++k;
			}
			++j;
		}
		cub->map[i - map_start][k] = '\0';
	}
	cub->map[i - map_start] = NULL;
	return (CUB_OK);
}

int	parse_map(t_mlx *cub, t_config *cfg, int end_of_config)
{
	int	err;

	err = map_check_valid_sym(cfg, end_of_config);
	printf("err in map - %d\n", err);
	if (err)
		return (err);
	if (copy_map(cub, cfg, end_of_config))
		return (CUB_ERR);
	int	i = 0;
	while (cub->map[i])
	{
		ft_putendl_fd(cub->map[i], STDOUT_FILENO);
		++i;
	}
	err = is_closed(cub->map);
	return (err);
}
