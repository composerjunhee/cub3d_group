/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/11/16 12:35:59 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Needs to remove the prefix before each texture string before attempting to load it.
static void	handle_params(char *line, t_params *params)
{
	if (ft_strncmp("NO ", (const char *)line, 3) == 0)
		params->no_texture = mlx_load_png(line);
	else if (ft_strncmp("SO ", (const char *)line, 3) == 0)
		params->so_texture = mlx_load_png(line);
	else if (ft_strncmp("WE ", (const char *)line, 3) == 0)
		params->we_texture = mlx_load_png(line);
	else if (ft_strncmp("EA ", (const char *)line, 3) == 0)
		params->ea_texture = mlx_load_png(line);
	else if (ft_strncmp("F ", (const char *)line, 2) == 0)
		params->f_values = ft_strdup(line);
	else if (ft_strncmp("C ", (const char *)line, 2) == 0)
		params->c_values = ft_strdup(line);
}

static int	handle_map(char *line, t_params *params)
{
	int		count;
	int		idx;

	idx = 0;
	count = 0;
		// This does not handle lines that aren't map legal.
	while (line[idx])
	{
		if (line[idx] != ' ' && line [idx] != '\t' \
			&& line [idx] != '\n' && line [idx] != '\0')
		{
			count++;
			idx = 0;
			break ;
		}
		idx++;
	}
	return (count);
}

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
		handle_params(line, params);
		count = handle_map(line, params);
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

static void	init_params(t_params *params, mlx_t *mlx)
{
	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Vi dy a gem", true);
	ft_bzero(params, sizeof(*params));
}

int	main(int argc, char **argv)
{
	t_params	params;
	mlx_t		*mlx;
	int			fd;

	if (argc != 2)
	{
		ft_putstr_fd("Need a path to the .cub file.", 2);
		return (-1);
	}
	init_params(&params, &mlx);
	fd = open(argv[1], 2);
	if (fd == -1)
	{
		ft_putstr_fd("FD failed to open\n", 2);
		return (-1);
	}
	get_map_params(fd, &params);
	return (0);
}
