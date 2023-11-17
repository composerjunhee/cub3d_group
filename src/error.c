/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:21:39 by junheeki          #+#    #+#             */
/*   Updated: 2023/11/17 15:42:44 by junheeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handler(int error_code)
{
	if (error_code == 1)
		ft_putstr_fd("Error 1\n", 2);
	else if (error_code == 2)
		ft_putstr_fd("Error 2\n", 2);
	else
		ft_putstr_fd("Unknown1 error occurred\n", 2);
}
