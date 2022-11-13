/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:42:07 by gtrinida          #+#    #+#             */
/*   Updated: 2022/11/10 18:15:06 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	sky_and_floor(t_mlx *mlx)
{
	int	x;
	int	horizon;
	int	height;

	height = 0;
	horizon = SCREEN_HEIGHT / 2;
	x = 0;
	height = SCREEN_HEIGHT - 1;
	while (x < SCREEN_WIDTH)
	{
		while (height > horizon)
		{
			put_pixel_img(mlx, x, height, 0x9acd32);
			height--;
		}
		while (height != 0)
		{
			put_pixel_img(mlx, x, height, 0x87ceeb);
			height--;
		}
		height = SCREEN_HEIGHT - 1;
		x++;
	}
}

void	redraw_window(t_mlx *mlx)
{
	ft_bzero(mlx->addr, (SCREEN_HEIGHT * SCREEN_WIDTH
			* (mlx->bits_per_pixel / 8)));
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
}

int	close_window(int key, t_mlx *mlx)
{
	if (key == 57 || key == 65307)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	return (0);
}

int	close_button(t_mlx *mlx)
{
	clear_cub(mlx);
	return (0);
}
