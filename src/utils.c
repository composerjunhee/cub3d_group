/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 07:36:13 by rrask             #+#    #+#             */
/*   Updated: 2023/11/22 16:15:51 by rrask            ###   ########.fr       */
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
	else
		ft_putstr_fd("Unknown1 error occurred.\n", 2);
	exit(error_code);
}