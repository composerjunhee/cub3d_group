/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:12:35 by rrask             #+#    #+#             */
/*   Updated: 2023/11/28 12:26:43 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_out_of_bounds(char *row, int pos)
{
	int	len;

	if (!row)
		error_handler(MAP_NOT_CLOSED);
	if (row[pos] == ' ' || row[pos] == '\n' || \
		row[pos] == '\t' || row[pos] == '\0')
		error_handler(MAP_NOT_CLOSED);
	len = ft_strlen(row);

	if (pos > len || pos < 0)
		return (1);
	else
		return (0);
}

int	is_player(char c)
{
	static char	arr[] = {'N', 'S', 'W', 'E'};
	int			i;

	i = 0;
	while (i < 4)
	{
		if (c == arr[i])
			return (arr[i]);
		i++;
	}
	return (0);
}
