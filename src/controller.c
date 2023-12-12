/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:43:12 by junheeki          #+#    #+#             */
/*   Updated: 2023/12/12 10:18:40 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_params *params)
{
	if (params->map[(int)(params->player->pos_x + params->player->dir_x * params->player->move_speed)][(int)params->player->pos_y] != '1')
		params->player->pos_x += params->player->dir_x * params->player->move_speed;
	if (params->map[(int)params->player->pos_x][(int)(params->player->pos_y + params->player->dir_y * params->player->move_speed)] != '1')
		params->player->pos_y += params->player->dir_y * params->player->move_speed;
	ft_printf("Foward");
}

void	move_a(t_params *params)
{
	int	i;

	(void)params;
	i = 0;
	// check players positon
	// if player's x position - 1 is not wall, player's x positon--;
	// if it's a wall, nothing happen
	ft_printf("LEFT");
}

void	move_s(t_params *params)
{
	int	i;

	(void)params;
	i = 0;
	// check players positon
	// if player's y position - 1 is not wall, player's y positon--;
	// if it's a wall, nothing happen
	ft_printf("BACK");
}

void	move_d(t_params *params)
{
	int i;

	(void)params;
	i = 0;
	// check players positon
	// if player's x position + 1 is not wall, player's x positon++;
	// if it's a wall, nothing happen
	ft_printf("RIGHT");
}
