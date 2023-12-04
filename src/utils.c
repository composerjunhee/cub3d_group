/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:36:13 by rrask             #+#    #+#             */
/*   Updated: 2023/12/04 10:51:39 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	skip_leading_whitespace(char *line)
{
	while (line)
	{
		if (*line == 32 || (*line >= 9 && *line <= 13))
			line++;
		else
			return (0);
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
	else
		ft_putstr_fd("Unknown1 error occurred.\n", 2);
	exit(error_code);
}
