/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:36:13 by rrask             #+#    #+#             */
/*   Updated: 2023/12/19 18:35:18 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	accepted_char(char c)
{
	if (c == '1' || c == '0' || c == 'E'
		|| c == 'N' || c == 'S' || c == 'W' || c == ' ')
		return (1);
	else
		return (0);
}

int	accepted_map_line(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!accepted_char(str[i]))
			error_handler(MAP_NOT_CLOSED);
		i++;
	}
	return (1);
}

static void	check_surroundings(t_params *params, int i, int j)
{
	if (is_out_of_bounds(params->map[i], j + 1))
		error_handler(MAP_NOT_CLOSED);
	if (is_out_of_bounds(params->map[i], j - 1))
		error_handler(MAP_NOT_CLOSED);
	if (is_out_of_bounds(params->map[i + 1], j))
		error_handler(MAP_NOT_CLOSED);
	if (is_out_of_bounds(params->map[i - 1], j))
		error_handler(MAP_NOT_CLOSED);
}

void	closed_map_check(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (params->map[i])
	{
		j = 0;
		while (params->map[i][j])
		{
			if (params->map[i][j] == '0' || is_player(params->map[i][j]))
				check_surroundings(params, i, j);
			j++;
		}
		i++;
	}
}

void	error_handler(int error_code)
{
	if (error_code == WRONG_INPUT)
		ft_putstr_fd("Please provide proper path to map.\n", 2);
	else if (error_code == FD_FAILURE)
		ft_putstr_fd("Fd failed to open.\n", 2);
	else if (error_code == WRONG_PATH)
		ft_putstr_fd("Given path is not valid.\n", 2);
	else if (error_code == GNL_FAILURE)
		ft_putstr_fd("GetNextLine has failed.\n", 2);
	else if (error_code == INVALID_CHAR)
		ft_putstr_fd("Invalid char found.\n", 2);
	else if (error_code == PLAYER_AMOUNT_INCORRECT)
		ft_putstr_fd("Incorrect amount of player positions.\n", 2);
	else if (error_code == NOT_ENOUGH_PARAMS)
		ft_putstr_fd("The parameter amount in the map file is incorrect.\n", 2);
	else if (error_code == MAP_NOT_CLOSED)
		ft_putstr_fd("The map is not closed.\n", 2);
	else if (error_code == ALLOCATION_ERROR)
		ft_putstr_fd("Allocation failed.\n", 2);
	else if (error_code == INVALID_COLOR)
		ft_putstr_fd("Color is not within the RGB range.\n", 2);
	else if (error_code == NO_MAP)
		ft_putstr_fd("No map in file.\n", 2);
	else
		ft_putstr_fd("Unknown1 error occurred.\n", 2);
	exit(error_code);
}
