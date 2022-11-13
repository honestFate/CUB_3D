/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:19:03 by gtrinida          #+#    #+#             */
/*   Updated: 2022/11/13 10:41:03 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	in_path_error(char *path, int err)
{
	ft_putstr_fd("Error in texture: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (err == WRONG_FILE_TYPE)
		ft_putendl_fd("wrong file type", STDERR_FILENO);
	else if (err == CANT_CONVERT)
		ft_putendl_fd("can't convert img", STDERR_FILENO);
}

static int	get_img(t_mlx *cub, t_config *cfg, int index)
{
	cub->textures[index] = xpg_to_img(cub, cfg->path_to_texture[index]);
	if (!cub->textures[index])
		return (TEXTURE_PATH_ERROR);
	return (CUB_OK);
}

int	convert_img(t_mlx *cub, t_config *config)
{
	int	err;
	int	f_type;
	int	i;

	i = -1;
	while (++i <= EA_INDEX)
	{
		if (!check_file_type(config->path_to_texture[i], ".png"))
			f_type = PNG;
		else if (!check_file_type(config->path_to_texture[i], ".xpm"))
			f_type = XPM;
		else
		{
			in_path_error(config->path_to_texture[i], WRONG_FILE_TYPE);
			return (TEXTURE_PATH_ERROR);
		}
		(void)f_type;
		err = get_img(cub, config, i);
		if (err)
			return (err);
	}
	return (CUB_OK);
}
