/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/11/14 14:51:13 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_map_params(int fd, t_params *params)
{
	char	*line;
	int		

	line = get_next_line(fd);
	while (line)
	{
		if (!line)
			line = get_next_line(fd);
		params->map[0] = malloc(sizeof(char *) + ft_strlen(line) + 1);
	}
}

// Function that returns a bool which checks for the beginning of the map.
// Return value is the number of lines! 
// If there is 

int	main(void)
{
	t_params	*params;
	char		*read_map;
	int			fd;

	fd = open(MAP_PATH, 2);
	if (fd == -1)
	{
		ft_putstr_fd("FD failed to open", 2);
		return (-1);
	}
	get_map_params(fd, &params);

	while (1)
	{
	}
	return (0);
}
