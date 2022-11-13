/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:02:51 by gtrinida          #+#    #+#             */
/*   Updated: 2022/11/10 17:58:57 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_steps(t_pos *info)
{
	if (info->raydir_x < 0)
	{
		info->step_x = -1;
		info->sidedist_x
			= (info->pos_x - info->map_x) * info->deltadist_x;
	}
	else
	{
		info->step_x = 1;
		info->sidedist_x
			= (info->map_x + 1.0 - info->pos_x) * info->deltadist_x;
	}
	if (info->raydir_y < 0)
	{
		info->step_y = -1;
		info->sidedist_y
			= (info->pos_y - info->map_y) * info->deltadist_y;
	}
	else
	{
		info->step_y = 1;
		info->sidedist_y
			= (info->map_y + 1.0 - info->pos_y) * info->deltadist_y;
	}
}

void	check_wall_hit(t_pos *info, t_mlx *mlx)
{
	while (info->hit == 0)
	{
		if (info->sidedist_x < info->sidedist_y)
		{
			info->sidedist_x += info->deltadist_x;
			info->map_x += info->step_x;
			info->side = 0;
		}
		else
		{
			info->sidedist_y += info->deltadist_y;
			info->map_y += info->step_y;
			info->side = 1;
		}
		if (mlx->map[info->map_x][info->map_y] > '0')
			info->hit = 1;
	}
}

void	init_ray(t_pos *info, t_mlx *mlx, int x)
{
	info->camera_x = 2 * x / (double) SCREEN_WIDTH - 1;
	info->raydir_x = info->dir_x + info->plane_x * info->camera_x;
	info->raydir_y = info->dir_y + info->plane_y * info->camera_x;
	info->map_x = (int) info->pos_x;
	info->map_y = (int) info->pos_y;
	if (info->raydir_x == 0)
		info->deltadist_x = INT_MAX;
	else
		info->deltadist_x = fabs(1 / info->raydir_x);
	if (info->raydir_y == 0)
		info->deltadist_y = INT_MAX;
	else
		info->deltadist_y = fabs(1 / info->raydir_y);
	info->hit = 0;
	check_steps(info);
	check_wall_hit(info, mlx);
}
