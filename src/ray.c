/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:59:48 by rrask             #+#    #+#             */
/*   Updated: 2023/12/19 15:01:34 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_calc(t_player *player, t_params *params)
{
	if (player->ray_dir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = (player->pos_x - (double)params->map_x)
			* player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = ((double)params->map_x + 1.0 - player->pos_x)
			* player->delta_dist_x;
	}
	if (player->ray_dir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = (player->pos_y - (double)params->map_y)
			* player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = ((double)params->map_y + 1.0 - player->pos_y)
			* player->delta_dist_y;
	}
}

void	ray_calc(t_player *player, int i)
{
	player->camera_x = 2 * i / (double)SCREEN_WIDTH - 1;
	player->ray_dir_x = player->dir_x + player->plane_x * player->camera_x;
	player->ray_dir_y = player->dir_y + player->plane_y * player->camera_x;
}

void	dda_algo(t_player *player, t_params *params)
{
	while (player->hit == 0)
	{
		if (player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_dist_x;
			params->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_dist_y;
			params->map_y += player->step_y;
			player->side = 1;
		}
		if (params->map[params->map_y][params->map_x] == '1')
			player->hit = 1;
	}
}
