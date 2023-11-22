/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:28:53 by junheeki          #+#    #+#             */
/*   Updated: 2023/11/21 18:23:25 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

// static mlx_image_t	*image;

// // void	ft_randomize(void *param)
// // {
// // 	for (int32_t i = 0; i < image->width; ++i)
// // 	{
// // 		for (int32_t y = 0; y < image->height; ++y)
// // 		{
// // 			uint32_t color = ft_pixel(rand() % 0xFF, // R
// // 										rand() % 0xFF, // G
// // 										rand() % 0xFF, // B
// // 										rand() % 0xFF  // A
// // 			);
// // 			mlx_put_pixel(image, i, y, color);
// // 		}
// // 	}
// // }

// // void	ft_hook(void *param)
// // {
// // 	mlx_t	*mlx;

// // 	mlx = param;
// // 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// // 		mlx_close_window(mlx);
// // 	if (mlx_is_key_down(mlx, MLX_KEY_UP))
// // 		image->instances[0].y -= 5;
// // 	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
// // 		image->instances[0].y += 5;
// // 	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
// // 		image->instances[0].x -= 5;
// // 	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
// // 		image->instances[0].x += 5;
// // }

// int	main(void)
// {
// 	mlx_t	*mlx;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "MLX42", true)))
// 	{
// 		// puts(mlx_strerror(mlx_errno));
// 		return (EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 128, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		// puts(mlx_strerror(mlx_errno));
// 		return (EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		// puts(mlx_strerror(mlx_errno));
// 		return (EXIT_FAILURE);
// 	}
// 	// mlx_loop_hook(mlx, ft_randomize, mlx);
// 	// mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }
