/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 12:33:20 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/24 22:21:48 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				get_shape_size(int *shape_height, int *shape_width)
{
	char		*line;
	char		*str;

	if (!get_next_line(0, &line))
		return (0);
	str = line + 6;
	if (ft_strlen(str) == 0)
	{
		free(line);
		return (0);
	}
	*shape_width = ft_atoi(ft_strchr(str, ' '));
	*shape_height = ft_atoi(str);
	free(line);
	if (*shape_height <= 0 || *shape_width <= 0)
		return (0);
	return (1);
}

int				get_shape(t_global *global, int shape_height)
{
	char		*line;
	int			j;

	j = 0;
	while (j < shape_height)
	{
		if (!get_next_line(0, &line))
		{
			free(global->shape);
			return (0);
		}
		global->shape[j] = ft_strdup(line);
		free(line);
		j++;
	}
	return (1);
}

static t_shape	*create_shape(int x, int y)
{
	t_shape		*shape;

	shape = (t_shape *)malloc(sizeof(t_shape));
	if (shape)
	{
		shape->x = x;
		shape->y = y;
		shape->next = NULL;
	}
	return (shape);
}

static t_shape	*pushback_shape(t_shape *start, t_shape *new)
{
	t_shape		*tmp;

	tmp = NULL;
	if (!start)
		return (new);
	if (new)
	{
		tmp = start;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (start);
}

t_shape			*build_shape(t_global *global, int height, int width)
{
	t_shape		*start;
	t_shape		*new;
	int			i;
	int			j;

	i = 0;
	start = NULL;
	new = NULL;
	if (!global->shape)
		return (0);
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (global->shape[i][j] == '*')
			{
				new = create_shape(j, i);
				start = pushback_shape(start, new);
			}
			j++;
		}
		i++;
	}
	return (start);
}
