/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:36:13 by rrask             #+#    #+#             */
/*   Updated: 2023/11/25 09:12:33 by rrask            ###   ########.fr       */
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

static	int check_perimeter(t_params *params, int i, int j)
{
	if (params->map[i + 1][j] != '1' && params->map[i + 1][j] != 'W' && params->map[i + 1][j] != 'E' \
		&& params->map[i + 1][j] != 'S' && params->map[i + 1][j] != 'N')
		{
			ft_printf("Trigger1\n");
			return (0);
		}
	if (params->map[i - 1][j] != '1' || params->map[i - 1][j] != 'W' || params->map[i - 1][j] != 'E' \
		|| params->map[i - 1][j] != 'S' || params->map[i - 1][j] != 'N')
		{
			ft_printf("Trigger2\n");
			return (0);
		}
	if (params->map[i][j + 1] != '1' && params->map[i][j + 1] != 'W' && params->map[i][j + 1] != 'E' \
		&& params->map[i][j + 1] != 'S' && params->map[i][j + 1] != 'N')
		{
			ft_printf("Trigger3\n");
			return (0);
		}
	if (params->map[i][j - 1] != '1' && params->map[i][j - 1] != 'W' && params->map[i][j - 1] != 'E' \
		&& params->map[i][j - 1] != 'S' && params->map[i][j - 1] != 'N')
		{
			ft_printf("Trigger4\n");
			return (0);
		}
	return(1);
}

void	closed_map_check(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (params->map[i])
	{
		while (params->map[i][j])
		{
			if (params->map[i][j] == '0')
				if (!check_perimeter(params, i, j))
					error_handler(MAP_NOT_CLOSED);
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
		ft_putstr_fd("The map is not closed off.\n", 2);
	else
		ft_putstr_fd("Unknown1 error occurred.\n", 2);
	exit(error_code);
}
