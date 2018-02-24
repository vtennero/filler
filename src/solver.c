/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:44:44 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/22 17:26:22 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		free_objects(t_shape *start, t_point *best_spot)
{
	t_shape		*tmp;

	while (start)
	{
		tmp = start->next;
		free(start);
		start = tmp;
	}
	free(best_spot);
}

static void		print_optimal_coord(int x, int y)
{
	ft_putnbr(y);
	write(1, " ", 1);
	ft_putnbr(x);
}

static int		get_best_score(t_global *global, t_shape *s, t_point *spot)
{
	int			score;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < global->height)
	{
		j = 0;
		while (j < global->width)
		{
			if ((score = all_checks(global, s, j, i)) >= 1)
			{
				if (spot->score == 0 || score < spot->score)
				{
					spot->score = score;
					spot->x = j;
					spot->y = i;
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int				solver(t_global *global, t_shape *shape)
{
	t_point		*best_spot;
	int			x;
	int			y;

	if (!shape)
		return (0);
	best_spot = malloc(sizeof(t_point));
	best_spot->score = 0;
	best_spot->x = 0;
	best_spot->y = 0;
	if (get_best_score(global, shape, best_spot) == 1)
	{
		x = best_spot->x;
		y = best_spot->y;
		free_objects(shape, best_spot);
		print_optimal_coord(x, y);
		return (1);
	}
	free(best_spot);
	return (0);
}
