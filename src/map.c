/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:28:14 by rrask             #+#    #+#             */
/*   Updated: 2023/12/19 14:58:51 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		i++;
	}
	if (params->player_amount == 0)
		error_handler(PLAYER_AMOUNT_INCORRECT);
	return (0);
}

int	check_illegal_content(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	fill_map(char *read_line, char *line, int fd, t_params *params)
{
	while (read_line)
	{
		if (read_line && read_line[0] == '\n')
		{
			while (read_line)
			{
				if (!check_illegal_content(read_line))
					error_handler(MAP_NOT_CLOSED);
				free(read_line);
				read_line = NULL;
				read_line = get_next_line(fd);
			}
			break ;
		}
		line = ft_strjoinfree(line, read_line);
		free(read_line);
		read_line = NULL;
		read_line = get_next_line(fd);
	}
	params->map = ft_split(line, '\n');
	free(line);
	close(fd);
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
	fill_map(read_line, line, fd, params);
}

void	get_map_params(int fd, t_params *params)
{
	are_params_valid(fd, params);
	fill_map_params(params, fd);
	map_validator(params);
	closed_map_check(params);
}
