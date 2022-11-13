/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:36:36 by fate              #+#    #+#             */
/*   Updated: 2022/11/13 10:37:21 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parse_settings(t_mlx *mlx, t_config *config, int *end_of_config)
{
	int	i;
	int	res;

	i = -1;
	ft_memset(config->path_to_texture, '\0', sizeof(char *) * 4);
	ft_memset(&config->colors, -1, sizeof(int) * 2);
	while (config->config_txt[++i])
	{
		*end_of_config = i;
		res = parse_identefer(config, config->config_txt[i]);
		if (res == END_CONFIG)
			break ;
		if (res != CUB_OK)
		{
			error_in_line(config->config_txt[i], res);
			return (INVALID_CONFIG_PARAM);
		}
	}
	if (check_config_param(config) != CUB_OK)
		return (INVALID_CONFIG_PARAM);
	mlx->floor_color = config->colors[0];
	mlx->ceil_color = config->colors[1];
	return (convert_img(mlx, config));
}

void	free_config(t_config *cfg)
{
	int	i;

	free_strarr(cfg->config_txt);
	i = 0;
	while (i < 4)
	{
		safe_free(cfg->path_to_texture[i]);
		++i;
	}
}

int	parse_config(t_mlx *mlx, char *path_to_cfg)
{
	int			end_of_config;
	int			err;
	t_config	config;

	config.config_txt = NULL;
	err = read_config(&config.config_txt, path_to_cfg);
	if (err)
		return (err);
	err = parse_settings(mlx, &config, &end_of_config);
	if (err)
	{
		free_config(&config);
		return (err);
	}
	err = parse_map(mlx, &config, end_of_config);
	free_config(&config);
	if (err)
		return (err);
	return (CUB_OK);
}
