/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:22:03 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/20 16:22:06 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		print_map(t_global *global)
{
	int		i;
	int		j;

	dprintf(2, "PRINT MAP\n");
	i = 0;
	while (i < global->height)
	{
		// dprintf(2, "line[%d]\n", i);
		j = 0;
		while (j < global->width)
		{
			// dprintf(2, "map[%d][%d] = %d\n", i, j, map[i][j]);
			dprintf(2, "%d", global->map[i][j]);
			j++;
			if (j == global->width)
				write(2, "\n", 1);
			else
				write(2, "\t", 1);
		}
		i++;
	}
}

void		print_coord_shape(t_shape *shape)
{
	while (shape)
	{
		dprintf(2, "(%d, %d)\n", shape->x, shape->y);
		shape = shape->next;
	}
}

void		print_shape(t_global *global, int shape_height)
{
	int		j;

	dprintf(2, "PRINT SHAPE\n");
	j = 0;
	while (j < shape_height)
	{
		dprintf(2, "%s\n", global->shape[j++]);
	}	
}