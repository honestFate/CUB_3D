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

void	start_parse_config(t_mlx *mlx, int err)
{
	err = parse_config(mlx, mlx->map_path);
	if (err)
	{
		print_error(err);
		clear_cub(mlx);
	}
}

int	main(int argc, char **argv)
{
	int		err;
	t_mlx	*mlx;

	err = check_argv(argc, argv);
	if (err)
		return (print_error(err), CUB_ERR);
	mlx = mlx_start_init(1);
	if (mlx == NULL)
		return (print_error(err), CUB_ERR);
	initilization(mlx, argv[1]);
	start_parse_config(mlx, err);
	set_map_size(mlx);
	if (init_pos(mlx))
	{	
		clear_cub(mlx);
		return (print_error(CUB_ERR), CUB_ERR);
	}
	gameloop(mlx);
	mlx_hook(mlx->win_ptr, 2, 1L << 0, key_handler, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, close_button, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (1);
}
