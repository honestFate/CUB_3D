/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 07:44:07 by gtrinida          #+#    #+#             */
/*   Updated: 2022/11/10 18:21:05 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	set_map_size(t_mlx *mlx)
{
	int	i;
	int	j;
	int	max_width;

	max_width = 0;
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
			++j;
		if (j > max_width)
			max_width = j;
		++i;
	}
	mlx->map_height = i;
	mlx->map_width = max_width;
}

void	tex_start_init(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx->textures[i] = NULL;
		i++;
	}
}

t_mlx	*mlx_start_init(int norm)
{
	t_mlx	*mlx;

	(void)norm;
	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->info = malloc(sizeof(t_pos));
	if (!mlx->info)
	{
		free(mlx);
		return (NULL);
	}
	mlx->textures = malloc(sizeof(t_texture) * 4);
	if (!mlx->textures)
	{
		free(mlx->info);
		free(mlx);
		return (NULL);
	}
	tex_start_init(mlx);
	mlx->map = NULL;
	return (mlx);
}

int	init_pos(t_mlx *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (mlx->map[++i])
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (is_player(mlx->map[i][j]))
			{
				mlx->info->pos_x = i + 0.5;
				mlx->info->pos_y = j + 0.5;
				mlx->map[i][j] = '0';
				return (CUB_OK);
			}
			if (mlx->map[i][j] == 'W')
				start_turn(mlx, mlx->info, 4.75);
			else if (mlx->map[i][j] == 'S')
				start_turn(mlx, mlx->info, 3.15);
			else if (mlx->map[i][j] == 'E')
				start_turn(mlx, mlx->info, 1.55);
		}
	}
	return (CUB_ERR);
}

void	initilization(t_mlx *mlx, char *line)
{
	mlx->info->pos_x = 0;
	mlx->info->pos_y = 0;
	mlx->info->dir_x = -1;
	mlx->info->dir_y = 0;
	mlx->info->plane_x = 0;
	mlx->info->plane_y = 0.66;
	mlx->info->color = 0xe0ffff;
	mlx->mlx_ptr = mlx_init();
	mlx->info->move_speed = 0.3;
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, SCREEN_WIDTH,
			SCREEN_HEIGHT, "Raycaster");
	mlx->img = mlx_new_image(mlx->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	mlx->map_path = ft_strdup(line);
}
