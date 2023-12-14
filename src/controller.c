/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:43:12 by junheeki          #+#    #+#             */
/*   Updated: 2023/12/14 14:35:25 by rrask            ###   ########.fr       */
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
