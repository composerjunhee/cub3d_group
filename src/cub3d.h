/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:54:41 by rrask             #+#    #+#             */
/*   Updated: 2023/11/20 08:07:56 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MAP_PATH "../map/basic.cub"
# define SCREEN_WIDTH 960
# define SCREEN_HEIGHT 540

# include "libft.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>

enum codes
{
	WRONG_INPUT = -1,
	FD_FAILURE = -2,
	WRONG_PATH = -3,
	
} code;
typedef struct s_params
{
	int				x_pos;
	int				y_pos;
	int				map_start;
	char			**map;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*so_texture;
	char			*f_values;
	char			*c_values;
}					t_params;

void skip_leading_whitespace(char *line);

#endif
