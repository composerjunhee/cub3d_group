/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/12/13 16:10:38 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	init_params(t_params *params)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		error_handler(ALLOCATION_ERROR);
	ft_bzero(params, sizeof(t_params));
	ft_bzero(player, sizeof(t_player));
	params->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Vi dy a gem", true);
	if (!params->mlx)
		error_handler(FD_FAILURE);
	params->player = player;
	params->image = mlx_new_image(params->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!params->image)
	{
		mlx_close_window(params->mlx);
		error_handler(FD_FAILURE);
	}
	if (mlx_image_to_window(params->mlx, params->image, 0, 0) == -1)
	{
		mlx_close_window(params->mlx);
		error_handler(FD_FAILURE);
	}
}

static void	set_player_vals(t_params *param)
{
	param->player->move_speed = 4.0 * param->mlx->delta_time;
	param->player->rot_speed = 3.0 * param->mlx->delta_time;
}

static void	rotation(t_params *params, int direction)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = params->player->dir_x;
	old_plane_x = params->player->plane_x;
	params->player->dir_x = params->player->dir_x * cos(direction
			* params->player->rot_speed) - params->player->dir_y * sin(direction
			* params->player->rot_speed);
	params->player->dir_y = old_dir_x * sin(direction
			* params->player->rot_speed) + params->player->dir_y * cos(direction
			* params->player->rot_speed);
	params->player->plane_x = params->player->plane_x * cos(direction
			* params->player->rot_speed) - params->player->plane_y
		* sin(direction * params->player->rot_speed);
	params->player->plane_y = old_plane_x * sin(direction
			* params->player->rot_speed) + params->player->plane_y
		* cos(direction * params->player->rot_speed);
}

void	my_keyhook(t_params *param)
{
	if (mlx_is_key_down(param->mlx, MLX_KEY_W))
		move_w(param);
	if (mlx_is_key_down(param->mlx, MLX_KEY_W))
		move_w(param);
	if (mlx_is_key_down(param->mlx, MLX_KEY_A))
		move_a(param);
	if (mlx_is_key_down(param->mlx, MLX_KEY_S))
		move_s(param);
	if (mlx_is_key_down(param->mlx, MLX_KEY_D))
		move_d(param);
	if (mlx_is_key_down(param->mlx, MLX_KEY_LEFT))
		rotation(param, -1);
	if (mlx_is_key_down(param->mlx, MLX_KEY_RIGHT))
		rotation(param, 1);
	if (mlx_is_key_down(param->mlx, MLX_KEY_ESCAPE))
	{
		free_map_params(param);
		exit(0);
	}
	set_player_vals(param);
}

void	render(t_params *param)
{
	ft_memset(param->image->pixels, 0, param->image->width
		* param->image->height * sizeof(int32_t));
	draw_floor_ceiling(param);
	raycasting(param->player, param);
}

void	close_game(t_params *param)
{
	free_map_params(param);
	mlx_close_window(param->mlx);
	exit(0);
}

static void	game_loop(t_params *params)
{
	mlx_loop_hook(params->mlx, (void *)render, params);
	mlx_loop_hook(params->mlx, (void *)my_keyhook, params);
	mlx_close_hook(params->mlx, (void *)close_game, params);
	mlx_loop(params->mlx);
	mlx_terminate(params->mlx);
}

int	main(int argc, char **argv)
{
	t_params	params;
	int			fd;

	if (argc != 2)
		error_handler(WRONG_INPUT);
	init_params(&params);
	params.map_path = ft_strdup(argv[1]); // malloc protection
	fd = open(params.map_path, 2);
	if (fd == -1)
		error_handler(FD_FAILURE);
	get_map_params(fd, &params);
	game_loop(&params);
	free_map_params(&params);
	return (0);
}
