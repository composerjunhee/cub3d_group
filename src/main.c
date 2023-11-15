/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/11/15 16:30:52 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_file_valid(int fd, t_params *params)
{
	char	*line;
	int		count;
	int		idx;

	count = 0;
	idx = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		if (!line)
			break ;
		if (ft_strncmp("NO ", (const char *)line, 3) == 0)
			params->no_texture = ft_strdup(line);
		else if (ft_strncmp("SO ", (const char *)line, 3) == 0)
			params->so_texture = ft_strdup(line);
		else if (ft_strncmp("WE ", (const char *)line, 3) == 0)
			params->we_texture = ft_strdup(line);
		else if (ft_strncmp("EA ", (const char *)line, 3) == 0)
			params->ea_texture = ft_strdup(line);
		else if (ft_strncmp("F ", (const char *)line, 2) == 0)
			params->f_values = ft_strdup(line);
		else if (ft_strncmp("C ", (const char *)line, 2) == 0)
			params->c_values = ft_strdup(line);
		else
		{
			while (line[idx])
			{
				if (line[idx] != ' ' && line [idx] != '\t' && line [idx] != '\n' && line [idx] != '\0')
				{
					ft_printf("%s", line);
					count++;
					idx = 0;
					break ;
				}
				idx++;
			}
		}
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (count);
}

static void	get_map_params(int fd, t_params *params)
{
	int		file_is_valid;

	file_is_valid = is_file_valid(fd, params);
	ft_printf("lines are: %d\n", file_is_valid);
	if (file_is_valid)
	{

	}
}

static void	init_params(t_params *params)
{
	ft_bzero(params, sizeof(*params));
}

int	main(int argc, char **argv)
{
	t_params	params;
	int			fd;

	if (argc != 2)
	{
		ft_putstr_fd("Need a path to the .cub file.", 2);
		return (-1);
	}
	init_params(&params);
	fd = open(argv[1], 2);
	if (fd == -1)
	{
		ft_putstr_fd("FD failed to open\n", 2);
		return (-1);
	}
	get_map_params(fd, &params);
	return (0);
}
