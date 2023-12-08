/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:28:14 by rrask             #+#    #+#             */
/*   Updated: 2023/12/08 16:50:32 by rrask            ###   ########.fr       */
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
			&& map_line[i] != 'N' && map_line[i] != 'E' && map_line[i] != 'S'
			&& map_line[i] != ' ' && map_line[i] != '\t'
			&& map_line[i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static int	valid_char_num_check(t_params *params, char *map_line, int x)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (map_line[i] == 'W' || map_line[i] == 'N' || map_line[i] == 'E'
			|| map_line[i] == 'S')
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

	i = 0;
	while (params->map[i])
	{
		// ft_printf("%s\n", params->map[i]);
		if (!valid_char_check(params->map[i]))
			error_handler(INVALID_CHAR);
		if (valid_char_num_check(params, params->map[i], i) == 0)
			error_handler(PLAYER_AMOUNT_INCORRECT);
		i++;
	}
	if (params->player_amount == 0)
		error_handler(PLAYER_AMOUNT_INCORRECT);
	return (0);
}

void	get_map_params(int fd, t_params *params)
{
	are_params_valid(fd, params);
	fill_map_params(params, fd);
	map_validator(params);
	closed_map_check(params);
}

void	fill_map_params(t_params *params, int fd)
{
	char	*line;
	char	*read_line;

	line = ft_strdup("");
	read_line = get_next_line(fd);
	if (!read_line)
		error_handler(NOT_ENOUGH_PARAMS);
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
