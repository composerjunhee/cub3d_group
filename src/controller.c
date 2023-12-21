/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:43:12 by junheeki          #+#    #+#             */
/*   Updated: 2023/12/19 14:56:17 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_params *params)
{
	int	x;
	int	y;

	x = (int)(params->player->pos_x + params->player->dir_x
			* params->player->move_speed);
	y = (int)(params->player->pos_y);
	if (params->map[y][x] != '1')
		params->player->pos_x += params->player->dir_x
			* params->player->move_speed;
	x = (int)params->player->pos_x;
	y = (int)(params->player->pos_y + params->player->dir_y
			* params->player->move_speed);
	if (params->map[y][x] != '1')
		params->player->pos_y += params->player->dir_y
			* params->player->move_speed;
}

void	move_a(t_params *params)
{
	int	x;
	int	y;

	x = (int)(params->player->pos_x + params->player->dir_y
			* params->player->move_speed);
	y = (int)(params->player->pos_y);
	if (params->map[y][x] != '1')
		params->player->pos_x += params->player->dir_y
			* params->player->move_speed;
	x = (int)params->player->pos_x;
	y = (int)(params->player->pos_y - params->player->dir_x
			* params->player->move_speed);
	if (params->map[y][x] != '1')
		params->player->pos_y -= params->player->dir_x
			* params->player->move_speed;
}

void	move_s(t_params *params)
{
	int	x;
	int	y;

	x = (int)(params->player->pos_x - params->player->dir_x
			* params->player->move_speed);
	y = (int)(params->player->pos_y);
	if (params->map[y][x] != '1')
		params->player->pos_x -= params->player->dir_x
			* params->player->move_speed;
	x = (int)params->player->pos_x;
	y = (int)(params->player->pos_y - params->player->dir_y
			* params->player->move_speed);
	if (params->map[y][x] != '1')
		params->player->pos_y -= params->player->dir_y
			* params->player->move_speed;
}

void	move_d(t_params *params)
{
	int	x;
	int	y;

	x = (int)(params->player->pos_x - params->player->dir_y
			* params->player->move_speed);
	y = (int)(params->player->pos_y);
	if (params->map[y][x] != '1')
		params->player->pos_x -= params->player->dir_y
			* params->player->move_speed;
	x = (int)params->player->pos_x;
	y = (int)(params->player->pos_y + params->player->dir_x
			* params->player->move_speed);
	if (params->map[y][x] != '1')
		params->player->pos_y += params->player->dir_x
			* params->player->move_speed;
}

void	my_keyhook(t_params *param)
{
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
	param->player->move_speed = 4.0 * param->mlx->delta_time;
	param->player->rot_speed = 3.0 * param->mlx->delta_time;
}
