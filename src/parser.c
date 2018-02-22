/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:24:35 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/22 17:29:13 by vtennero         ###   ########.fr       */
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
					// dprintf(2, "creating 1st point\n");
					shape = (t_shape *)malloc(sizeof(t_shape));
					shape->x = j;
					shape->y = i;
					tmp = shape;
				}
				else
				{
					// dprintf(2, "creating point %d\n", size + 1);
					shape->next = (t_shape *)malloc(sizeof(t_shape));
					shape->next->x = j;
					shape->next->y = i;
					shape = shape->next;
				}
				// dprintf(2, "point %d : (%d, %d)\n", size + 1, j, i);
				size++;
			}
			j++;
		}
		i++;
	}
	shape->next = NULL;
	return (tmp);
}

void	assign_size(t_global *global, char **line)
{
	char	*str;

	// dprintf(2, "assign_size\n");
	str = *line + 8;
	global->width = ft_atoi(ft_strchr(str, ' '));
	global->height = ft_atoi(str);
}

void	assign_player(t_global *global, char **line)
{
	char	*str;

	// dprintf(2, "assign_player\n");
	str = *line + 10;
	if (str[0] == '1')
	{
		global->player = 1;
		global->adversary = 2;
	}
	if (str[0] == '2')
	{
		global->player = 2;
		global->adversary = 1;
	}
	else
		;
}


