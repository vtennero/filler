/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:24:35 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/23 18:03:53 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_shape		*lst_shape(t_global *global, int height, int width)
{
	t_shape	*shape;
	t_shape	*tmp;
	int		size;
	int		i;
	int		j;

	size = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (global->shape[i][j] == '*')
			{
				if (size == 0)
				{
					shape = (t_shape *)malloc(sizeof(t_shape));
					shape->x = j;
					shape->y = i;
					tmp = shape;
				}
				else
				{
					shape->next = (t_shape *)malloc(sizeof(t_shape));
					shape->next->x = j;
					shape->next->y = i;
					shape = shape->next;
				}
				size++;
			}
			j++;
		}
		i++;
	}
	shape->next = NULL;
	return (tmp);
}

void		assign_size(t_global *global, int k)
{
	char	*str;
	char	**line;

	line = (char **)malloc(sizeof(char *));
	get_next_line(0, line);
	if (k == 1)
	{
		str = *line + 8;
		global->width = ft_atoi(ft_strchr(str, ' '));
		global->height = ft_atoi(str);
	}
	free(*line);
}

int			assign_player(t_global *global)
{
	char	**line;
	char	*str;

	line = (char **)malloc(sizeof(char *));
	get_next_line(0, line);
	str = *line + 10;
	if (str[0] == '1')
	{
		global->player = 1;
		global->adversary = 2;
	}
	else if (str[0] == '2')
	{
		global->player = 2;
		global->adversary = 1;
	}
	else
	{
		free(*line);
		return (0);
	}
	free(*line);
	return (1);
}
