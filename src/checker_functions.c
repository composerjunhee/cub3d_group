/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:12:35 by rrask             #+#    #+#             */
/*   Updated: 2023/11/27 14:14:28 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_edge(char *row, int pos)
{
	int	len;

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
			return (i);
		i++;
	}
	return (0);
}
