/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fate <fate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:35:12 by fate              #+#    #+#             */
/*   Updated: 2022/11/13 10:35:13 by fate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_config_format(void)
{
	printf("USAGE\n");
	printf("./cub3d path_to_config\n");
	printf("CONFIG FILE\n");
	printf("NO ./path_to_the_north_texture\n");
	printf("SO ./path_to_the_south_texture\n");
	printf("WE ./path_to_the_west_texture\n");
	printf("EA ./path_to_the_east_texture\n");
	printf("F [0,255], [0,255], [0,255]\n");
	printf("C [0,255], [0,255], [0,255]\n");
	printf("map closed/surrounded by walls, and N,S,E or W for ");
	printf("the player's start position and spawning orientation.\n");
}
