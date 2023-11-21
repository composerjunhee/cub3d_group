/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:21:39 by junheeki          #+#    #+#             */
/*   Updated: 2023/11/21 13:42:11 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler(int error_code)
{
	if (error_code == WRONG_INPUT)
	{
		ft_putstr_fd("Please provide proper path to map.\n", 2);
	}
	else if (error_code == FD_FAILURE)
	{
		ft_putstr_fd("Fd failed to open.\n", 2);
		exit(0);
	}
	else if (error_code == WRONG_PATH)
	{
		ft_putstr_fd("Given path is not valid.\n", 2);
		exit(0);
	}
	else if (error_code == GNL_FAILURE)
	{
		ft_putstr_fd("GetNextLine has failed.\n", 2);
		exit(0);
	}
	else
		ft_putstr_fd("Unknown1 error occurred.\n", 2);
}

