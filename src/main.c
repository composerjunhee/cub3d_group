/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/11/20 12:36:35 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map_params(t_params *params)
{
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
	// if (params->map)
	// {
	// 	while (*params->map)
	// 	{
	// 		free(params->map);
	// 		params->map++;
	// 	}
	// 	free(params->map);
	// }
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

// static void fill_map(char **map, int fd)
// {
// 	char	*line;
// 	int		params;

// 	line = NULL;

// 	line = get_next_line(fd);
// 	if (!line)
// 		exit(0);
// 	while (line)
// 	{
// 		if (!line)
// 			exit(0);

// 		//iterate through the map file for the start of the map.
// 	}
// }

static int	handle_map(char *line)
{
	int	count;
	int	idx;

	idx = 0;
	count = 0;
	while (line[idx])
	{
		if (line[idx] != ' ' && line[idx] != '\t' && line[idx] != '\n'
			&& line[idx] != '\0')
		{
			count++;
			idx = 0;
			break ;
		}
		idx++;
	}
	return (count);
}

static int	are_params_valid(int fd, t_params *params)
{
	char	*line;
	int		map_height;
	int		param_count;

	map_height = 0;
	param_count = 0;
	line = get_next_line(fd);
	if (!line)
		exit(0);
	while (line)
	{
		if (!line)
			exit(0);
		if (param_count == 6)
			map_height += handle_map(line);
		if (map_height == 0)
			params->map_start++;
		param_count += handle_params(line, params);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	ft_printf("%d\n", map_height);
	return (map_height);
}

static void	get_map_params(int fd, t_params *params)
{
	int		map_row_amount;


	map_row_amount = 0;
	map_row_amount = are_params_valid(fd, params);
	if (map_row_amount)
	{
		ft_printf("%d\n", params->map_start);
		// params->map = malloc(sizeof(char **) * map_row_amount + 1);
		// fill_map(params->map, fd);
		// Set all the params->map[indexes] to the map rows.
		// Then check them for validity.
		// exit(0);
	}
}

static void	init_params(t_params *params, mlx_t *mlx)
{
	mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Vi dy a gem", true);
	ft_bzero(params, sizeof(*params));
	(void)mlx;
}

int	main(int argc, char **argv)
{
	t_params	params;
	mlx_t		mlx;
	int			fd;

	if (argc != 2)
		error_handler(WRONG_INPUT);
	init_params(&params, &mlx);
	fd = open(argv[1], 2);
	if (fd == -1)
		error_handler(FD_FAILURE);
	get_map_params(fd, &params);
	free_map_params(&params);
	return (0);
}
