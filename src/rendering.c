/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:11:27 by rrask             #+#    #+#             */
/*   Updated: 2023/12/19 15:02:44 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	wall_color(t_params *params, t_player *player)
{
	uint32_t	color;
	int			x;
	int			y;
	int			index;

	y = player->text_y;
	x = player->text_x;
	index = y * (int)params->text_to_draw->height
		* (int)params->text_to_draw->bytes_per_pixel + x
		* (int)params->text_to_draw->bytes_per_pixel;
	color = params->text_to_draw->pixels[index] << 24
		| params->text_to_draw->pixels[index + 1]
		<< 16 | params->text_to_draw->pixels[index + 2] << 8 | 255;
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
	player->draw_start = SCREEN_HEIGHT / 2 - player->line_height / 2;
	if (player->draw_start < 0)
		player->draw_start = 0;
	player->draw_end = SCREEN_HEIGHT / 2 + player->line_height / 2;
	if (player->draw_end >= SCREEN_HEIGHT)
		player->draw_end = SCREEN_HEIGHT - 1;
}

void	check_for_hit(t_params *params, t_player *player)
{
	params->map_x = (int)player->pos_x;
	params->map_y = (int)player->pos_y;
	if (player->ray_dir_x == 0)
		player->delta_dist_x = MASSIVE_NUM;
	else
		player->delta_dist_x = fabs(1 / player->ray_dir_x);
	if (player->ray_dir_y == 0)
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
		select_texture(params);
		calculate_texture(params);
		vertical_draw(i, player, params);
		i++;
	}
}
