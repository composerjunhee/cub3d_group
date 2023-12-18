/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:28:14 by rrask             #+#    #+#             */
/*   Updated: 2023/12/18 18:08:29 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_char_check(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (!accepted_char(map_line[i]))
			return (0);
		if (map_line[i] == ' ')
			map_line[i] = '1';
		i++;
	}
	return (1);
}

static void	set_n_s_orientation(t_player *player,
	double one_val, double two_val)
{
	player->dir_x = 0.0;
	player->dir_y = one_val;
	player->plane_x = two_val;
	player->plane_y = 0.0;
}

static void	set_w_e_orientation(t_player *player,
	double one_val, double two_val)
{
	player->dir_x = one_val;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = two_val;
}

static	void	get_orientation(char direction, t_params *params)
{
	if (direction == 'N')
		set_n_s_orientation(params->player, -1.0, FOV);
	if (direction == 'S')
		set_n_s_orientation(params->player, 1.0, -FOV);
	if (direction == 'E')
		set_w_e_orientation(params->player, 1.0, FOV);
	if (direction == 'W')
		set_w_e_orientation(params->player, -1.0, -FOV);
}

static int	valid_char_num_check(t_params *params, char *map_line, int y)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] == 'W' || map_line[i] == 'N' || map_line[i] == 'E'
			|| map_line[i] == 'S')
		{
			get_orientation(map_line[i], params);
			params->player->pos_x = (double)i + 0.3;
			params->player->pos_y = (double)y + 0.3;
			params->player_amount++;
		}
		i++;
	}
	if (params->player_amount > 1)
		return (0);
	else
		return (1);
}

int	map_validator(t_params *params)
{
	int	i;

	i = 0;
	while (params->map[i])
	{
		if (!valid_char_check(params->map[i]))
			error_handler(INVALID_CHAR);
		if (valid_char_num_check(params, params->map[i], i) == 0)
			error_handler(PLAYER_AMOUNT_INCORRECT);
		// space_handler(params->map[i]);
		i++;
	}
	if (params->player_amount == 0)
		error_handler(PLAYER_AMOUNT_INCORRECT);
	return (0);
}

int	multiple_newlines(char *line)
{
	int	i;

	i = 0;

	while (line[i])
	{
		i++;
		if (line[i] == '\n' && line[i - 1] == '\n')
			return (0);
	}
	return (1);
}

void	fill_map_params(t_params *params, int fd)
{
	char	*line;
	char	*read_line;

	line = ft_strdup("");
	read_line = get_next_line(fd);
	if (!read_line)
		error_handler(NOT_ENOUGH_PARAMS);
	if (*read_line != '1' || *read_line != ' ')
	{
		while (1)
		{
			if (ft_strncmp(read_line, "\n", 1))
				break ;
			free(read_line);
			read_line = get_next_line(fd);
		}
	}
	while (read_line)
	{
		line = ft_strjoinfree(line, read_line);
		if (!multiple_newlines(line))
			error_handler(MAP_NOT_CLOSED);
		free(read_line);
		read_line = NULL;
		read_line = get_next_line(fd);
	}
	params->map = ft_split(line, '\n');
	free(line);
	close(fd);
}

void	get_map_params(int fd, t_params *params)
{
	are_params_valid(fd, params);
	fill_map_params(params, fd);
	map_validator(params);
	closed_map_check(params);
}
