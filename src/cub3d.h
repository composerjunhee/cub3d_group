/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:54:41 by rrask             #+#    #+#             */
/*   Updated: 2023/12/04 10:53:57 by rrask            ###   ########.fr       */
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

enum				e_codes
{
	WRONG_INPUT = -1,
	FD_FAILURE = -2,
	WRONG_PATH = -3,
	GNL_FAILURE = -4,
	INVALID_CHAR = -5,
	PLAYER_AMOUNT_INCORRECT = -6,
	NOT_ENOUGH_PARAMS = -7,
	MAP_NOT_CLOSED = -8,
	ALLOCATION_ERROR = -9,
}					code;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
}				t_player;

typedef struct s_params
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_player		*player;
	int				player_amount;
	int				map_start;
	char			*map_path;
	char			**map;
	int				x;
	int				y;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*so_texture;
	char			*f_values;
	char			*c_values;
}					t_params;


/* UTILITIES */
int					skip_leading_whitespace(char *line);
int					is_player(char c);
int					is_out_of_bounds(char *row, int pos);
void				error_handler(int error_code);
/* MAP HANDLING */
void				get_map_params(int fd, t_params *params);
void				fill_map_params(t_params *params, int fd);
void				closed_map_check(t_params *params);
void				free_map_params(t_params *params);
/* PARAMETER HANDLING */
void				are_params_valid(int fd, t_params *params);
int					handle_params(char *line, t_params *params);
void				load_texture(char *line, mlx_texture_t **texture);
int					map_validator(t_params *params);
void				my_keyhook(mlx_key_data_t keydata, void *param);
/* CONTROLLER */
void				move_w(t_params *params);
void				move_a(t_params *params);
void				move_s(t_params *params);
void				move_d(t_params *params);

#endif
