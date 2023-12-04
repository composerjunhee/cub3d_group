/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/12/04 12:47:52 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_params(t_params *params)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		error_handler(ALLOCATION_ERROR);
	ft_bzero(params, sizeof(*params));
	ft_bzero(player, sizeof(t_player));
	params->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Vi dy a gem", true);
	if (!params->mlx)
		error_handler(FD_FAILURE);
	params->player = player;
	params->image = mlx_new_image(params->mlx, 128, 128);
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

void	my_keyhook(mlx_key_data_t keydata, void *param)
{

	// mlx_is_key_down()
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		// move_w()
		ft_printf("FORWARD MARCH\n");
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		// move_a()
		ft_printf("LEFT MARCH\n");
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		// move_s()
		ft_printf("BACKWARD MARCH\n");
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		// move_d()
		ft_printf("RIGHT MARCH\n");
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_map_params(param);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_params			params;
	int					fd;

	if (argc != 2)
		error_handler(WRONG_INPUT);
	init_params(&params);
	params.map_path = ft_strdup(argv[1]);
	fd = open(params.map_path, 2);
	if (fd == -1)
		error_handler(FD_FAILURE);
	get_map_params(fd, &params);
	mlx_key_hook(params.mlx, &my_keyhook, &params);
	mlx_loop(params.mlx);
	free_map_params(&params);
	return (0);
}
