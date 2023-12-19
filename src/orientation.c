/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:49:22 by rrask             #+#    #+#             */
/*   Updated: 2023/12/19 14:57:31 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_n_s_orientation(t_player *player,
	double one_val, double two_val)
{
	player->dir_x = 0.0;
	player->dir_y = one_val;
	player->plane_x = two_val;
	player->plane_y = 0.0;
}

static void	set_w_e_orientation(t_player *player,
	double one_val, double two_val)
{
	player->dir_x = one_val;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = two_val;
}

void	get_orientation(char direction, t_params *params)
{
	if (direction == 'N')
		set_n_s_orientation(params->player, -1.0, FOV);
	if (direction == 'S')
		set_n_s_orientation(params->player, 1.0, -FOV);
	if (direction == 'E')
		set_w_e_orientation(params->player, 1.0, FOV);
	if (direction == 'W')
		set_w_e_orientation(params->player, -1.0, -FOV);
}

void	rotation(t_params *params, int direction)
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
