/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:54:41 by rrask             #+#    #+#             */
/*   Updated: 2023/12/08 10:46:20 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MAP_PATH "../map/basic.cub"
# define SCREEN_WIDTH 960
# define SCREEN_HEIGHT 540
# define MASSIVE_NUM 1e30
# define TEXTURE_H 64
# define TEXTURE_W 64
# define FOV 66

# include "libft.h"
# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <math.h>

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
	INVALID_COLOR = -10,
}					code;

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	double	move_speed;
	double	rot_speed;
	int		draw_start;
	int		draw_end;
	int		text_x;
	int		text_y;
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
	int				map_x;
	int				map_y;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*text_to_draw;
	int				f_values;
	int				c_values;
	uint32_t		wall_c;
}					t_params;

/* UTILITIES */
int					skip_leading_whitespace(char *line);
int					is_player(char c);
int					is_out_of_bounds(char *row, int pos);
void				error_handler(int error_code);
int					get_color(char *line);
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
/* RENDERING */
void				raycasting(t_player *player, t_params *params);
void				check_for_hit(t_params *params, t_player *player);
void				fish_eye_correction(t_player *player);
void				ray_calc(t_player *player, int i);
uint32_t			wall_color(t_params *params, t_player *player);
void				render(t_params *param);
void				draw_floor_ceiling(t_params *param);

/* CONTROLLER */
void				move_w(t_params *params);
void				move_a(t_params *params);
void				move_s(t_params *params);
void				move_d(t_params *params);

#endif
