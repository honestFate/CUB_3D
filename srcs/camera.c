/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:58:33 by gtrinida          #+#    #+#             */
/*   Updated: 2022/11/03 17:41:50 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	start_turn(t_mlx *mlx, t_pos *info, double rotate)
{
	info->old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(rotate) - info->dir_y * sin(rotate);
	info->dir_y = info->old_dir_x * sin(rotate) + info->dir_y * cos(rotate);
	info->old_plane_x = info->plane_x;
	info->plane_x = info->plane_x
		* cos(rotate) - info->plane_y * sin(rotate);
	info->plane_y = info->old_plane_x
		* sin(rotate) + info->plane_y * cos(rotate);
	redraw_window(mlx);
	gameloop(mlx);
}

void	left_turn(t_mlx *mlx, t_pos *info)
{
	double	rotate;

	rotate = 0.09;
	info->old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(rotate) - info->dir_y * sin(rotate);
	info->dir_y = info->old_dir_x * sin(rotate) + info->dir_y * cos(rotate);
	info->old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(rotate) - info->plane_y * sin(rotate);
	info->plane_y = info->old_plane_x * sin(rotate) + info->plane_y
		* cos(rotate);
	redraw_window(mlx);
	gameloop(mlx);
}

void	right_turn(t_mlx *mlx, t_pos *info)
{
	double	rotate;

	rotate = 0.09;
	info->old_dir_x = info->dir_x;
	info->dir_x = info->dir_x * cos(-rotate) - info->dir_y * sin(-rotate);
	info->dir_y = info->old_dir_x * sin(-rotate) + info->dir_y * cos(-rotate);
	info->old_plane_x = info->plane_x;
	info->plane_x = info->plane_x * cos(-rotate) - info->plane_y * sin(-rotate);
	info->plane_y = info->old_plane_x
		* sin(-rotate) + info->plane_y * cos(-rotate);
	redraw_window(mlx);
	gameloop(mlx);
}
