/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:33:29 by rrask             #+#    #+#             */
/*   Updated: 2023/11/23 15:08:42 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(char *line, mlx_texture_t **texture)
{
	int	len;

	len = ft_strlen(line);
	line[len - 1] = '\0';
	*texture = mlx_load_png(line);
}

int	handle_params(char *line, t_params *params)
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

void	free_map_params(t_params *params)
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