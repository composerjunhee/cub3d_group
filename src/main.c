/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/11/15 13:50:58 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_file_valid(int fd, t_params *params)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	while (line)
	{
		if (!line)
			break ;
		if (ft_strncmp("NO ", (const char *)line, 2))
			params->no_texture = ft_strdup(line);
		if (ft_strncmp("SO ", (const char *)line, 2))
			params->so_texture = ft_strdup(line);
		if (ft_strncmp("WE ", (const char *)line, 2))
			params->we_texture = ft_strdup(line);
		if (ft_strncmp("EA ", (const char *)line, 2))
			params->ea_texture = ft_strdup(line);
		if (ft_strncmp("F ", (const char *)line, 1))
			params->f_values = ft_strdup(line);
		if (ft_strncmp("C ", (const char *)line, 1))
			params->c_values = ft_strdup(line);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	return (1);
}

static void	get_map_params(int fd, t_params *params)
{
	int		file_is_valid;

	file_is_valid = is_file_valid(fd, params);
	if (file_is_valid)
		ft_printf("What is up? /n");
}

static void	init_params(t_params *params)
{
	ft_bzero(&params, sizeof(params));
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
