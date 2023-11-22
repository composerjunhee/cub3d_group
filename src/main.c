/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/11/22 13:24:09 by rrask            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_params			params;
	mlx_t				*mlx;
	int					fd;
	static mlx_image_t	image;
	int i = 0;

	if (argc != 2)
		error_handler(WRONG_INPUT);
	init_params(&params, &mlx, &image);
	params.map_path = ft_strdup(argv[1]);
	fd = open(params.map_path, 2);
	if (fd == -1)
		error_handler(FD_FAILURE);
	get_map_params(fd, &params);
	while (params.map[i])
	{
		ft_printf("%s\n", params.map[i]);
		i++;
	}
	mlx_loop(mlx);
	free_map_params(&params);
	return (0);
}
