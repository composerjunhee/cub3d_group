/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:30:01 by rrask             #+#    #+#             */
/*   Updated: 2023/12/12 18:24:17 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceiling(t_params *param)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				mlx_put_pixel(param->image, x, y, param->f_values);
			else
				mlx_put_pixel(param->image, x, y, param->c_values);
			x++;
		}
		y++;
	}
}

int	get_rgba(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

static int	convert_string_to_color(char *line)
{
	char	*tmp;
	int		result;

	while (!ft_isdigit(*line))
		line++;
	tmp = ft_strtrim(line, "\t");
	result = 0;
	if (!tmp)
		error_handler(ALLOCATION_ERROR);
	if (!ft_isdigit(*tmp))
		error_handler(INVALID_COLOR);
	result = ft_atoi(line);
	if (result < 0 || result > 255)
		error_handler(INVALID_COLOR);
	free(tmp);
	return (result);
}

int	get_color(char *line)
{
	char	**tmp;
	int		rgb[3];
	int		i;
	int		res;

	i = 0;
	res = 0;
	tmp = ft_split(line, ',');
	if (!tmp)
		error_handler(ALLOCATION_ERROR);
	while (tmp[i])
	{
		if (i >= 3)
			error_handler(WRONG_INPUT);
		rgb[i] = convert_string_to_color(tmp[i]);
		i++;
	}
	if (i < 3)
		error_handler(WRONG_INPUT);
	res = get_rgba(rgb[0], rgb[1], rgb[2]);
	while (*tmp)
		free(*tmp++);
	return (res);
}
