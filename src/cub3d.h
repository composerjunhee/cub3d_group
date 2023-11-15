/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:54:41 by rrask             #+#    #+#             */
/*   Updated: 2023/11/15 13:11:38 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MAP_PATH "../map/basic.cub"
# define TEXTURE_PATH "../textures/"

# include <MLX42/MLX42.h>
# include <fcntl.h>
# include "libft.h"

typedef struct s_params {
	int		x_pos;
	int		y_pos;
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;

	char	*f_values;
	char	*c_values;
}				t_params;

#endif
