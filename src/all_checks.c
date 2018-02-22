/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:12:33 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/22 17:12:56 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				is_in_map(t_global *global, t_shape *shape, int x, int y)
{
	// dprintf(2, "Initiating inmap check\n");
	while (shape)
	{
		if (shape->x + x > global->width - 1 || shape->y + y > global->height - 1)
		{
			// dprintf(2, "out of map\n");
			return (0);
		}
		shape = shape->next;
	}
	return (1);
}

int				is_valid_overlap(t_global *global, t_shape *shape, int x, int y)
{
	int			overlap;
	int			counter;

	// dprintf(2, "Initiating valid overlap check\n");
	overlap = 0;
	counter = 0;
	while (shape)
	{
		if (global->map[shape->y + y][shape->x + x] == -global->player)
			overlap++;
		shape = shape->next;
		counter++;
	}
	if (counter == overlap || overlap != 1)
	{
		overlap = 0;
	}
	return (overlap);
}

int				no_collision_adv(t_global *global, t_shape *shape, int x, int y)
{
	// dprintf(2, "Initiating no collision check\n");
	while (shape)
	{
		if (global->map[shape->y + y][shape->x + x] == -global->adversary)
		{
			// dprintf(2, "colliding with adv on %d\n", global->map[shape->y + y][shape->x + x]);
			return (0);
		}
		shape = shape->next;
	}
	return (1);
}

int				get_score(t_global *global, t_shape *shape, int x, int y)
{
	int			sum;

	// dprintf(2, "Initiating get score\n");
	sum = 0;
	while (shape)
	{
		if (global->map[shape->y + y][shape->x + x] > 0)
			sum = global->map[shape->y + y][shape->x + x] + sum;
		shape = shape->next;
	}
	return (sum);
}

int				all_checks(t_global *global, t_shape *shape, int *score, \
		int x, int y)
{
	// dprintf(2, "Initiating all checks for %d, %d\n", x, y);
	if (!(is_in_map(global, shape, x, y)))
		return (0);
	if (!(is_valid_overlap(global, shape, x, y)))
		return (0);
	if (!(no_collision_adv(global, shape, x, y)))
		return (0);
	*score = get_score(global, shape, x, y);
	return (1);
}

