/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:33:29 by rrask             #+#    #+#             */
/*   Updated: 2023/12/15 15:13:18 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_texture(char *line, mlx_texture_t **texture)
{
	int	len;

	len = ft_strlen(line);
	line[len - 1] = '\0';
	*texture = mlx_load_png(line);
	if (!*texture)
		error_handler(FD_FAILURE);
}

int	inner_handle_params(char *line, t_params *params)
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
}

int	handle_params(char *line, t_params *params)
{
	if (!multiple_newlines(line))
		return (0);
	inner_handle_params(line, params);
	if (ft_strncmp("F ", (const char *)line, 2) == 0)
	{
		params->f_values = get_color(line);
		return (1);
	}
	else if (ft_strncmp("C ", (const char *)line, 2) == 0)
	{
		params->c_values = get_color(line);
		return (1);
	}
	return (0);
}

void	free_map_params(t_params *params)
{
	int	i;

	i = 0;
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
