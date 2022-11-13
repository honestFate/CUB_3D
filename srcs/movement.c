/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:24:43 by gtrinida          #+#    #+#             */
/*   Updated: 2022/11/03 03:33:55 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	go_forward(t_mlx *mlx)
{
	int		x_step;
	int		y_step;
	int		flag;

	flag = 0;
	x_step = (int)(mlx->info->pos_x + mlx->info->dir_x * mlx->info->move_speed);
	y_step = (int)(mlx->info->pos_y + mlx->info->dir_y * mlx->info->move_speed);
	if (mlx->map[x_step][(int)(mlx->info->pos_y)] == '0')
	{
		flag = 1;
		mlx->info->pos_x += mlx->info->dir_x * mlx->info->move_speed;
	}
	if (mlx->map[(int)(mlx->info->pos_x)][y_step] == '0')
	{
		flag = 1;
		mlx->info->pos_y += mlx->info->dir_y * mlx->info->move_speed;
	}
	if (!flag)
		return ;
	redraw_window(mlx);
	gameloop(mlx);
}

void	go_back(t_mlx *mlx)
{
	int		x_step;
	int		y_step;

	x_step = (int)(mlx->info->pos_x - mlx->info->dir_x * mlx->info->move_speed);
	y_step = (int)(mlx->info->pos_y - mlx->info->dir_y * mlx->info->move_speed);
	if (mlx->map[x_step][(int)(mlx->info->pos_y)] == '0')
		mlx->info->pos_x -= mlx->info->dir_x * mlx->info->move_speed;
	if (mlx->map[(int)(mlx->info->pos_x)][y_step] == '0')
		mlx->info->pos_y -= mlx->info->dir_y * mlx->info->move_speed;
	else
		return ;
	redraw_window(mlx);
	gameloop(mlx);
}

void	go_left(t_mlx *mlx)
{
	int		x_step;
	int		y_step;

	x_step = (int)(mlx->info->pos_x - mlx->info->plane_x
			* mlx->info->move_speed);
	y_step = (int)(mlx->info->pos_y - mlx->info->plane_y
			* mlx->info->move_speed);
	if (mlx->map[x_step][(int)(mlx->info->pos_y)] == '0')
		mlx->info->pos_x -= mlx->info->plane_x * mlx->info->move_speed;
	if (mlx->map[(int)(mlx->info->pos_x)][y_step] == '0')
		mlx->info->pos_y -= mlx->info->plane_y * mlx->info->move_speed;
	else
		return ;
	redraw_window(mlx);
	gameloop(mlx);
}

void	go_right(t_mlx *mlx)
{
	int		x_step;
	int		y_step;

	x_step = (int)(mlx->info->pos_x + mlx->info->plane_x
			* mlx->info->move_speed);
	y_step = (int)(mlx->info->pos_y + mlx->info->plane_y
			* mlx->info->move_speed);
	if (mlx->map[x_step][(int)(mlx->info->pos_y)] == '0')
		mlx->info->pos_x += mlx->info->plane_x * mlx->info->move_speed;
	if (mlx->map[(int)(mlx->info->pos_x)][y_step] == '0')
		mlx->info->pos_y += mlx->info->plane_y * mlx->info->move_speed;
	else
		return ;
	redraw_window(mlx);
	gameloop(mlx);
}
