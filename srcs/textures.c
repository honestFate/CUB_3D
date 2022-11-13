/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:10:33 by gtrinida          #+#    #+#             */
/*   Updated: 2022/10/12 13:21:57 by gtrinida         ###   ########.fr       */
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
		clear_cub(mlx);
		exit(1);
	}
	t->texture = (int *)mlx_get_data_addr(t->img, &(t->bpp),
			&(t->size_line), &(t->endian));
	return (t);
}
