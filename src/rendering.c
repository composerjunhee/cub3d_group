/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:11:27 by rrask             #+#    #+#             */
/*   Updated: 2023/12/04 12:54:04 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_player *player)
{
	int	i;

	i = 0;

	while (i < SCREEN_WIDTH)
	{
		player->camera_x = 2 * i / (double)SCREEN_WIDTH - 1;
		player->ray_dir_x = player->dir_x + player->plane_x * player->camera_x;
		player->ray_dir_y = player->dir_y + player->plane_y * player->camera_x;
		i++;
	}
}
