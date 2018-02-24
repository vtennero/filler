/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:23:31 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/22 19:12:50 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_next_point(int *x, int *y, t_global *global)
{
	int		i;
	int		j;

	i = *y;
	j = *x;
	if (*y > global->height || *x > global->width)
		return (0);
	while (i < global->height)
	{
		while (j < global->width)
		{
			if (global->map[i][j] == -global->adversary)
			{
				*y = i;
				*x = j;
				return (1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

static void	assign_score_to_point(t_global *global, int i, int j)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (get_next_point(&x, &y, global) == 1)
	{
		if (global->map[i][j] == 0)
			global->map[i][j] = ft_abs(y - i) + ft_abs(x - j);
		else if (global->map[i][j] > 0)
			global->map[i][j] = ft_min(global->map[i][j], \
				ft_abs(y - i) + ft_abs(x - j));
		if (x < global->width)
			x++;
		if (x == global->width)
		{
			x = 0;
			y++;
		}
	}
}

static void	assign_score(t_global *global)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < global->height)
	{
		j = 0;
		while (j < global->width)
		{
			assign_score_to_point(global, i, j);
			j++;
		}
		i++;
	}
}

static int	*fill_line(char *str, t_global *global)
{
	int	*new_line;
	int	j;

	j = 0;
	new_line = (int *)malloc(global->width * sizeof(int));
	if (new_line)
	{
		while (j < global->width)
		{
			if (str[j] == 'O')
				new_line[j] = -1;
			else if (str[j] == 'X')
				new_line[j] = -2;
			else
				new_line[j] = 0;
			j++;
		}
	}
	return (new_line);
}

int			get_map(t_global *global)
{
	int		i;
	char	*line;
	char	*str;

	i = 0;
	if (!get_next_line(0, &line) || !global->map)
		return (0);
	free(line);
	while (i < global->height)
	{
		if (!get_next_line(0, &line))
			return (0);
		str = line + 4;
		global->map[i] = fill_line(str, global);
		free(line);
		i++;
	}
	assign_score(global);
	return (1);
}
