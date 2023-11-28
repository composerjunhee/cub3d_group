/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/11/28 14:43:19 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_params(t_params *params, mlx_t **mlx, mlx_image_t *image)
{
	*mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Vi dy a gem", true);
	if (!mlx)
		error_handler(FD_FAILURE);
	image = mlx_new_image(*mlx, 128, 128);
	if (!image)
	{
		mlx_close_window(*mlx);
		error_handler(FD_FAILURE);
	}
	if (mlx_image_to_window(*mlx, image, 0, 0) == -1)
	{
		mlx_close_window(*mlx);
		error_handler(FD_FAILURE);
	}
	ft_bzero(params, sizeof(*params));
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	(void)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
	{
		// move_w()
		ft_printf("FORWARD MARCH\n");
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
	{
		// move_a()
		ft_printf("LEFT MARCH\n");
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
	{
		// move_s()
		ft_printf("BACKWARD MARCH\n");
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
	{
		// move_d()
		ft_printf("RIGHT MARCH\n");
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		// destroy everything(map, player, images)
		// exit_game()
		ft_printf("EXIT\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_params			params;
	mlx_t				*mlx;
	int					fd;
	static mlx_image_t	image;

	if (argc != 2)
		error_handler(WRONG_INPUT);
	init_params(&params, &mlx, &image);
	params.map_path = ft_strdup(argv[1]);
	fd = open(params.map_path, 2);
	if (fd == -1)
		error_handler(FD_FAILURE);
	get_map_params(fd, &params);
	mlx_key_hook(mlx, &my_keyhook, &params);
	mlx_loop(mlx);
	free_map_params(&params);
	return (0);
}
