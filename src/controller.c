/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:43:12 by junheeki          #+#    #+#             */
/*   Updated: 2023/11/28 14:45:05 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_w(t_params *params)
{
	int	i;

	(void)params;
	i = 0;
	// check players positon
	// if player's y position + 1 is not wall, player's y positon++;
	// if it's a wall, nothing happen
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