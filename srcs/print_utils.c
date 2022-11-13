/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:35:22 by fate              #+#    #+#             */
/*   Updated: 2022/11/13 10:41:58 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_image(t_mlx *cub, int index, int width, int height)
{
	cub->textures[index]->img = mlx_new_image(cub->mlx_ptr, width, height);
	cub->textures[index]->texture = (int *)mlx_get_data_addr(
			cub->textures[index]->img,
			&cub->textures[index]->bpp,
			&cub->textures[index]->size_line, &cub->textures[index]->endian);
}

void	put_pixel_img(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x > 1920 || y > 1080 || x < 0 || y < 0)
		return ;
	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	player_pos(float p)
{
	return ((int)roundf((p - BLOCK_SIZE / 2) / BLOCK_SIZE));
}
