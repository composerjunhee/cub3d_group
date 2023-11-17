/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:57 by rrask             #+#    #+#             */
/*   Updated: 2023/11/17 15:45:27 by rrask            ###   ########.fr       */
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

// Needs to remove the prefix before each texture string before attempting to load it.
static int	handle_params(char *line, t_params *params)
{
	int	param_count;

	param_count = 0;
	if (ft_strncmp("NO ", (const char *)line, 3) == 0)
	{
		load_texture(line + 3, &(params->no_texture));
		param_count++;
	}
	else if (ft_strncmp("SO ", (const char *)line, 3) == 0)
	{
		load_texture(line + 3, &(params->so_texture));
		param_count++;
	}
	else if (ft_strncmp("WE ", (const char *)line, 3) == 0)
	{
		load_texture(line + 3, &(params->we_texture));
		param_count++;
	}
	else if (ft_strncmp("EA ", (const char *)line, 3) == 0)
	{
		load_texture(line + 3, &(params->ea_texture));
		param_count++;
	}
	else if (ft_strncmp("F ", (const char *)line, 2) == 0)
	{
		params->f_values = ft_strdup(line);
		param_count++;
	}
	else if (ft_strncmp("C ", (const char *)line, 2) == 0)
	{
		params->c_values = ft_strdup(line);
		param_count++;
	}
	return (param_count);
}

static int	handle_map(char *line)
{
	int	count;
	int	idx;

	idx = 0;
	count = 0;
	// This does not handle lines that aren't map legal.
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
	int		count;
	int		param_count;

	count = 0;
	param_count = 0;
	line = get_next_line(fd);
	if (!line)
		exit(0);
	while (line)
	{
		if (!line)
			break ;
		if (param_count == 6)
			count += handle_map(line);
		param_count += handle_params(line, params);
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	return (count);
}

static void	get_map_params(int fd, t_params *params)
{
	int		map_row_amount;
	char	*line;

	line = NULL;
	map_row_amount = 0;
	map_row_amount = are_params_valid(fd, params);
	if (map_row_amount)
	{
		// params->map = malloc(sizeof(char **) * map_row_amount + 1);
		// exit(0);
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
	mlx_t		mlx;
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
	free_map_params(&params);
	return (0);
}
