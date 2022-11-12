/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 07:44:11 by gtrinida          #+#    #+#             */
/*   Updated: 2022/11/10 18:20:23 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	textured_raycaster(t_mlx *mlx, int x)
{
	double	step;
	double	tex_pos;
	int		y;
	int		color;

	y = mlx->info->draw_start;
	step = (double) mlx->textures[mlx->info->tex_n]
		->height / mlx->info->line_height;
	tex_pos = (mlx->info->draw_start - (double)
			SCREEN_HEIGHT / 2 + (double) mlx->info->line_height / 2) * step;
	while (y < mlx->info->draw_end)
	{
		mlx->info->tex_y = (int)tex_pos
			& (mlx->textures[mlx->info->tex_n]->height - 1);
		tex_pos += step;
		color = mlx->textures[mlx->info->tex_n]->texture[
			mlx->textures[mlx->info->tex_n]->height
			* mlx->info->tex_y + mlx->info->tex_x];
		put_pixel_img(mlx, x, y, color);
		y++;
	}
}

void	get_tex_n(t_pos *info)
{
	if (info->side == 0 && info->raydir_x > 0)
		info->tex_n = NORTH;
	else if (info->side == 0 && info->raydir_x < 0)
		info->tex_n = SOUTH;
	else if (info->side == 1 && info->raydir_y > 0)
		info->tex_n = WEST;
	else if (info->side == 1 && info->raydir_y < 0)
		info->tex_n = EAST;
}

void	ray_calculate(t_pos *info, t_mlx *mlx)
{
	if (info->side == 0)
		info->perpwalldist = (info->sidedist_x - info->deltadist_x);
	else
		info->perpwalldist = (info->sidedist_y - info->deltadist_y);
	info->line_height = (int)(SCREEN_HEIGHT / info->perpwalldist);
	info->draw_start = (-info->line_height) / 2 + SCREEN_HEIGHT / 2;
	if (info->draw_start < 0)
		info->draw_start = 0;
	info->draw_end = info->line_height / 2 + SCREEN_HEIGHT / 2;
	if (info->draw_end >= SCREEN_HEIGHT)
		info->draw_end = SCREEN_HEIGHT - 1;
	if (info->side == 0)
		info->wall_x = info->pos_y + info->perpwalldist * info->raydir_y;
	else
		info->wall_x = info->pos_x + info->perpwalldist * info->raydir_x;
	info->wall_x -= floor((info->wall_x));
	get_tex_n(info);
	info->tex_x = (int)(info->wall_x * (double)
			(mlx->textures[info->tex_n]->width));
}

void	gameloop(t_mlx *mlx)
{
	int	x;

	x = 0;
	sky_and_floor(mlx);
	while (x < SCREEN_WIDTH)
	{
		init_ray(mlx->info, mlx, x);
		ray_calculate(mlx->info, mlx);
		textured_raycaster(mlx, x);
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
}
