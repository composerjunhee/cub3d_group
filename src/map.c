/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:28:14 by rrask             #+#    #+#             */
/*   Updated: 2023/11/23 10:37:07 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	valid_char_check(char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != '1' && map_line[i] != '0' && map_line[i] != 'W'
			&& map_line[i] != 'N'
			&& map_line[i] != 'E' && map_line[i] != 'S' && map_line[i] != ' '
			&& map_line[i] != '\t' && map_line[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	valid_char_num_check(t_params *params, char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] == 'W' || map_line[i] == 'N' ||
			map_line[i] == 'E' || map_line[i] == 'S')
			params->player_amount++;
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
	int	j;

	i = 0;
	j = 0;
	while (params->map[i])
	{
		if (!valid_char_check(params->map[i]))
			error_handler(INVALID_CHAR);
		if (!valid_char_num_check(params, params->map[i]))
			error_handler(PLAYER_AMOUNT_EXCEED);
		i++;
	}
	return (0);
}

// Map has an only one spawn point.
// valid characters (E, W, N, S, 0, 1)
// Surrounded by 1

void	get_map_params(int fd, t_params *params)
{
	int	map_row_amount;

	map_row_amount = 0;
	are_params_valid(fd, params);
	fill_map(params, fd);
	map_validator(params);
}

void	fill_map(t_params *params, int fd)
{
	char	*line;
	char	*read_line;

	line = ft_strdup("");
	read_line = get_next_line(fd);
	if (!read_line)
		error_handler(GNL_FAILURE);
	while (read_line)
	{
		line = ft_strjoinfree(line, read_line);
		free(read_line);
		read_line = NULL;
		read_line = get_next_line(fd);
	}
	params->map = ft_split(line, '\n');
	free(line);
	close(fd);
}

void	free_map_params(t_params *params)
{
	int	i;

	i = 0;
	if (params->c_values)
		free(params->c_values);
	if (params->f_values)
		free(params->f_values);
	if (params->ea_texture)
		mlx_delete_texture(params->ea_texture);
	if (params->no_texture)
		mlx_delete_texture(params->no_texture);
	if (params->we_texture)
		mlx_delete_texture(params->we_texture);
	if (params->so_texture)
		mlx_delete_texture(params->so_texture);
	if (params->map)
	{
		if (params->map[i])
		{
			while (params->map[i])
				free(params->map[i++]);
		}
		free(params->map);
	}
	if (params->map_path)
		free(params->map_path);
}
