/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:54:41 by rrask             #+#    #+#             */
/*   Updated: 2023/11/22 15:13:38 by rrask            ###   ########.fr       */
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

enum e_codes
{
	WRONG_INPUT = -1,
	FD_FAILURE = -2,
	WRONG_PATH = -3,
	GNL_FAILURE = -4,
	INVALID_CHAR = -5,
} code;
typedef struct s_params
{
	int				x_pos;
	int				y_pos;
	int				map_start;
	char			*map_path;
	char			**map;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*so_texture;
	char			*f_values;
	char			*c_values;
}					t_params;

/* UTILITIES */
int		skip_leading_whitespace(char *line);
void	error_handler(int error_code);
/* MAP HANDLING */
void	get_map_params(int fd, t_params *params);
void	fill_map(t_params *params, int fd);
void	free_map_params(t_params *params);
/* PARAMETER HANDLING */
void	are_params_valid(int fd, t_params *params);
int		handle_params(char *line, t_params *params);
void	load_texture(char *line, mlx_texture_t **texture);
int		map_validator(t_params *params);

#endif
