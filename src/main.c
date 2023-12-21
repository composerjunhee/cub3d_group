/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/12/19 14:58:00 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_params(t_params *params)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		error_handler(ALLOCATION_ERROR);
	ft_bzero(params, sizeof(t_params));
	ft_bzero(player, sizeof(t_player));
	params->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Vi dy a gem", true);
	if (!params->mlx)
		error_handler(FD_FAILURE);
	params->player = player;
	params->image = mlx_new_image(params->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!params->image)
	{
		mlx_close_window(params->mlx);
		error_handler(FD_FAILURE);
	}
	if (mlx_image_to_window(params->mlx, params->image, 0, 0) == -1)
	{
		mlx_close_window(params->mlx);
		error_handler(FD_FAILURE);
	}
}

void	render(t_params *param)
{
	ft_memset(param->image->pixels, 0, param->image->width
		* param->image->height * sizeof(int32_t));
	draw_floor_ceiling(param);
	raycasting(param->player, param);
}

void	close_game(t_params *param)
{
	free_map_params(param);
	mlx_close_window(param->mlx);
	exit(0);
}

static void	game_loop(t_params *params)
{
	mlx_loop_hook(params->mlx, (void *)render, params);
	mlx_loop_hook(params->mlx, (void *)my_keyhook, params);
	mlx_close_hook(params->mlx, (void *)close_game, params);
	mlx_loop(params->mlx);
	mlx_terminate(params->mlx);
}

int	main(int argc, char **argv)
{
	t_params	params;
	int			fd;

	if (argc != 2)
		error_handler(WRONG_INPUT);
	init_params(&params);
	params.map_path = ft_strdup(argv[1]);
	if (!params.map_path || !ft_strnstr(params.map_path, ".cub",
			ft_strlen(params.map_path)))
		error_handler(WRONG_INPUT);
	fd = open(params.map_path, 2);
	if (fd == -1)
		error_handler(FD_FAILURE);
	get_map_params(fd, &params);
	game_loop(&params);
	free_map_params(&params);
	return (0);
}
