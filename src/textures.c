/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:02:26 by rrask             #+#    #+#             */
/*   Updated: 2023/12/19 15:02:52 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	select_texture(t_params *params)
{
	if (params->player->side == 0)
	{
		if (params->map_x > params->player->pos_x)
			params->text_to_draw = params->we_texture;
		else
			params->text_to_draw = params->ea_texture;
	}
	else if (params->player->side == 1)
	{
		if (params->map_y > params->player->pos_y)
			params->text_to_draw = params->no_texture;
		else
			params->text_to_draw = params->so_texture;
	}
}

void	calculate_texture(t_params *params)
{
	if (params->player->side == 0)
		params->wall_x = params->player->pos_y
			+ params->player->perp_wall_dist * params->player->ray_dir_y;
	else
		params->wall_x = params->player->pos_x
			+ params->player->perp_wall_dist * params->player->ray_dir_x;
	params->wall_x -= floor(params->wall_x);
	params->player->text_x = (int)(params->wall_x * (double)TEXTURE_W);
	if (params->player->side == 0 && params->player->ray_dir_x > 0)
		params->player->text_x = TEXTURE_W - params->player->text_x - 1;
	if (params->player->side == 1 && params->player->ray_dir_y < 0)
		params->player->text_x = TEXTURE_W - params->player->text_x - 1;
}
