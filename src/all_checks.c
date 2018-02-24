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

static int		is_in_map(t_global *global, t_shape *shape, int x, int y)
{
	while (shape)
	{
		if (shape->x + x > global->width - 1 || shape->y + y > \
			global->height - 1)
		{
			return (0);
		}
		shape = shape->next;
	}
	return (1);
}

static int		is_valid_overlap(t_global *global, t_shape *shape, int x, int y)
{
	int			overlap;
	int			counter;

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

static int		no_collision_adv(t_global *global, t_shape *shape, int x, int y)
{
	while (shape)
	{
		if (global->map[shape->y + y][shape->x + x] == -global->adversary)
		{
			return (0);
		}
		shape = shape->next;
	}
	return (1);
}

static int		get_score(t_global *global, t_shape *shape, int x, int y)
{
	int			sum;

	sum = 0;
	while (shape)
	{
		if (global->map[shape->y + y][shape->x + x] > 0)
			sum = global->map[shape->y + y][shape->x + x] + sum;
		shape = shape->next;
	}
	return (sum);
}

int				all_checks(t_global *global, t_shape *shape, int x, int y)
{
	int		score;

	score = 0;
	if (!(is_in_map(global, shape, x, y)))
		return (0);
	if (!(is_valid_overlap(global, shape, x, y)))
		return (0);
	if (!(no_collision_adv(global, shape, x, y)))
		return (0);
	score = get_score(global, shape, x, y);
	return (score);
}
