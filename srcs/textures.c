/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:10:33 by gtrinida          #+#    #+#             */
/*   Updated: 2022/11/13 18:52:25 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_texture	*xpg_to_img(t_mlx *mlx, char *path_to_file)
{
	t_texture	*t;

	t = malloc(sizeof(t_texture));
	t->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			path_to_file, &(t->width), &(t->height));
	if (!t->img)
	{
		free(t);
		return (NULL);
	}
	t->texture = (int *)mlx_get_data_addr(t->img, &(t->bpp),
			&(t->size_line), &(t->endian));
	return (t);
}
