/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:11:27 by rrask             #+#    #+#             */
/*   Updated: 2023/12/12 14:52:13 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	raycast_calc(t_player *player, t_params *params)
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

static void	dda_algo(t_player *player, t_params *params)
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

uint32_t	wall_color(t_params *params, t_player *player)
{
	uint32_t	color;
	int			x;
	int			y;
	int			index;

	y = player->text_y;
	x = player->text_x;
	index = y * (int)params->ea_texture->height
		* (int)params->ea_texture->bytes_per_pixel + x
		* (int)params->ea_texture->bytes_per_pixel;
	color = params->ea_texture->pixels[index] << 24 | params->ea_texture->pixels[index
		+ 1] << 16 | params->ea_texture->pixels[index + 2] << 8 | 255;
	return (color);
}

static void	vertical_draw(int x, t_player *player, t_params *params)
{
	int		y;
	double	step;
	double	texture_pos;

	y = player->draw_start;
	step = 1.0 * ((double)TEXTURE_H) / (double)player->line_height;
	texture_pos = ((double)player->draw_start - ((double)SCREEN_HEIGHT / 2.0)
			+ ((double)player->line_height / 2.0)) * step;
	while (y < player->draw_end)
	{
		player->text_y = (int)texture_pos & (TEXTURE_H - 1);
		texture_pos += step;
		if (player->side == 1)
			params->wall_c = (params->wall_c >> 1) & 8355711;
		params->wall_c = wall_color(params, player);
		mlx_put_pixel(params->image, x, y, params->wall_c);
		y++;
	}
}

void	calculate_walls(t_player *player)
{
	player->draw_start = 0;
	player->draw_end = 0;
	if (player->side == 0)
		player->perp_wall_dist = (player->side_dist_x - player->delta_dist_x);
	else
		player->perp_wall_dist = (player->side_dist_y - player->delta_dist_y);
	player->line_height = (int)(SCREEN_HEIGHT / player->perp_wall_dist);
	player->draw_start = -(player->line_height) / 2 + SCREEN_HEIGHT / 2;
	if (player->draw_start < 0)
		player->draw_start = 0;
	player->draw_end = player->line_height / 2 + SCREEN_HEIGHT / 2;
	if (player->draw_end >= SCREEN_HEIGHT)
		player->draw_end = SCREEN_HEIGHT - 1;
}

void	check_for_hit(t_params *params, t_player *player)
{
	params->map_x = (int)player->pos_x;
	params->map_y = (int)player->pos_y;
	if (player->delta_dist_x == 0)
		player->delta_dist_x = MASSIVE_NUM;
	else
		player->delta_dist_x = fabs(1 / player->ray_dir_x);
	if (player->delta_dist_y == 0)
		player->delta_dist_y = MASSIVE_NUM;
	else
		player->delta_dist_y = fabs(1 / player->ray_dir_y);
	player->hit = 0;
}

void	raycasting(t_player *player, t_params *params)
{
	int	i;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		ray_calc(player, i);
		check_for_hit(params, player);
		raycast_calc(player, params);
		dda_algo(player, params);
		calculate_walls(player);
		vertical_draw(i, player, params);
		i++;
	}
}
