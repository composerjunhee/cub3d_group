/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:54:41 by rrask             #+#    #+#             */
/*   Updated: 2023/11/16 12:24:55 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MAP_PATH "../map/basic.cub"
# define TEXTURE_PATH "../textures/"
# define SCREEN_WIDTH 960
# define SCREEN_HEIGHT 540

# include "libft.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>

typedef struct s_params
{
	int				x_pos;
	int				y_pos;
	char			**map;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*so_texture;
	char			*f_values;
	char			*c_values;
}					t_params;

#endif
