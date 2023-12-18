/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:12:35 by rrask             #+#    #+#             */
/*   Updated: 2023/12/18 17:23:10 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_out_of_bounds(char *row, int pos)
{
	int	len;

	if (!row)
		error_handler(MAP_NOT_CLOSED);
	if (row[pos] == '\n' || \
		row[pos] == '\t' || row[pos] == '\0')
		error_handler(MAP_NOT_CLOSED);
	len = ft_strlen(row);
	if (pos > len || pos < 0)
		return (1);
	else
		return (0);
}

int	is_player(char c)
{
	static char	arr[] = {'N', 'S', 'W', 'E'};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (c == arr[i])
			return (arr[i]);
		i++;
	}
	return (0);
}

void	are_params_valid(int fd, t_params *params)
{
	char	*line;
	int		param_count;

	param_count = 0;
	line = get_next_line(fd);
	if (!line)
		error_handler(GNL_FAILURE);
	while (line)
	{
		if (!line)
			error_handler(GNL_FAILURE);
		if (param_count == 6)
		{
			free(line);
			return ;
		}
		param_count += handle_params(line, params);
		free(line);
		line = NULL;
		if (param_count != 6)
			line = get_next_line(fd);
	}
}
