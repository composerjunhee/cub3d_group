/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/11/22 10:44:29 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map_params(t_params *params)
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

static	void	load_texture(char *line, mlx_texture_t **texture)
{
	int		len;

	len = ft_strlen(line);
	line[len - 1] = '\0';
	*texture = mlx_load_png(line);
}

static int	handle_params(char *line, t_params *params)
{
	if (ft_strncmp("NO ", (const char *)line, 3) == 0)
	{
		load_texture(line + 3, &(params->no_texture));
		return (1);
	}
	else if (ft_strncmp("SO ", (const char *)line, 3) == 0)
	{
		load_texture(line + 3, &(params->so_texture));
		return (1);
	}
	else if (ft_strncmp("WE ", (const char *)line, 3) == 0)
	{
		load_texture(line + 3, &(params->we_texture));
		return (1);
	}
	else if (ft_strncmp("EA ", (const char *)line, 3) == 0)
	{
		load_texture(line + 3, &(params->ea_texture));
		return (1);
	}
	else if (ft_strncmp("F ", (const char *)line, 2) == 0)
	{
		params->f_values = ft_strdup(line);
		return (1);
	}
	else if (ft_strncmp("C ", (const char *)line, 2) == 0)
	{
		params->c_values = ft_strdup(line);
		return (1);
	}
	return (0);
}


static void	fill_map(t_params *params, int fd)
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
		free (read_line);
		read_line = NULL;
		read_line = get_next_line(fd);
	}
	params->map = ft_split(line, '\n');
	free (line);
}

static void	are_params_valid(int fd, t_params *params)
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
			free (line);
			return ;
		}
		param_count += handle_params(line, params);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
}

static void	get_map_params(int fd, t_params *params)
{
	int		map_row_amount;

	map_row_amount = 0;
	are_params_valid(fd, params);
	fill_map(params, fd);
}

static void	init_params(t_params *params, mlx_t *mlx)
{
	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Vi dy a gem", true);
	ft_bzero(params, sizeof(*params));
}

int	main(int argc, char **argv)
{
	t_params	params;
	mlx_t		mlx;
	int			fd;

	if (argc != 2)
		error_handler(WRONG_INPUT);
	init_params(&params, &mlx);
	params.map_path = ft_strdup(argv[1]);
	fd = open(params.map_path, 2);
	if (fd == -1)
		error_handler(FD_FAILURE);
	get_map_params(fd, &params);
	free_map_params(&params);
	return (0);
}
