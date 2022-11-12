/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 07:44:03 by gtrinida          #+#    #+#             */
/*   Updated: 2022/11/10 18:22:27 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_handler(int key, t_mlx *mlx)
{
	if (key == 65307 || key == 53)
	{
		exit(0);
	}
	if (key == 123 || key == 65361)
		left_turn(mlx, mlx->info);
	if (key == 124 || key == 65363)
		right_turn(mlx, mlx->info);
	if (key == 13 || key == 119)
		go_forward(mlx);
	if (key == 1 || key == 115)
		go_back(mlx);
	if (key == 0 || key == 97)
		go_left(mlx);
	if (key == 2 || key == 100)
		go_right(mlx);
	return (1);
}

void	side(char c, t_texture *textures)
{
	if (c == 'N')
		textures->side = NORTH;
	if (c == 'S')
		textures->side = SOUTH;
	if (c == 'W')
		textures->side = WEST;
	if (c == 'E')
		textures->side = EAST;
}

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

t_mlx	*mlx_start_init()
{
	t_mlx *mlx;

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

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (is_player(mlx->map[i][j]))
			{
				mlx->info->pos_x = i + 0.5;
				mlx->info->pos_y = j + 0.5;
				mlx->map[i][j] = '0';
				ft_log("inited pos");
				return (CUB_OK);
			}
			if (mlx->map[i][j] == 'W')
				start_turn(mlx, mlx->info, 4.75);
			else if (mlx->map[i][j] == 'S')
				start_turn(mlx, mlx->info, 3.15);
			else if (mlx->map[i][j] == 'E')
				start_turn(mlx, mlx->info, 1.55);
			++j;
		}
		++i;
	}
	return (CUB_ERR);
}

int	main(int argc, char **argv)
{
	int err;
	t_mlx *mlx;
	
	err = check_argv(argc, argv);
	if (err)
		return (print_error(err), CUB_ERR);
	mlx = mlx_start_init();
	if (mlx == NULL)
		return (print_error(err), CUB_ERR);
	initilization(mlx, argv[1]);
	err = parse_config(mlx, mlx->map_path);
	if (err)
	{
		ft_log("parse failed");
		clear_cub(mlx);
		return (print_error(err), CUB_ERR);
	}
	set_map_size(mlx);
	ft_log("init zalupa");
	ft_log("init zalupa");
	ft_log("init zalupa");
	if (init_pos(mlx))
	{
		ft_log("init pos failed");	
		clear_cub(mlx);
		return (print_error(CUB_ERR), CUB_ERR);
	}
	gameloop(mlx);
	mlx_hook(mlx->win_ptr, 2, 1L<<0, key_handler, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_buttonV2, mlx);
	mlx_loop(mlx->mlx_ptr);
	return 1;
}
