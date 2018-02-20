/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:24:35 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/20 16:24:38 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_shape		*lst_shape(t_global *global, int height, int width)
{
	t_shape	*shape;
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
						shape = malloc(sizeof(t_shape));
						shape->x = j;
						shape->y = i;
					}
					else
					{
						// dprintf(2, "creating point %d\n", size + 1);
						shape->next = malloc(sizeof(t_shape));
						shape->next->x = j;
						shape->next->y = i;
						shape = shape->next;
					}
					dprintf(2, "point %d : (%d, %d)\n", size + 1, j, i);
					size++;
				}
			j++;
		}
		i++;
	}
	shape->next = NULL;
	return (shape);
}


static int	get_next_point(int *x, int *y, t_global *global)
{
	int		i;
	int		j;

	// dprintf(2, "get_next_point(%d, %d)\n", *x, *y);
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
						// dprintf(2, "get_next_point: adversary found on (%d, %d)\n", i, j);
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

void	assign_score(t_global *global)
{
	int	i;
	int	j;
	int	x;
	int	y;

	// dprintf(2, "assign score\n");
	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (i < global->height)
	{
		j = 0;
		while (j < global->width)
		{
			while(get_next_point(&x, &y, global) == 1)
			{
				if (global->map[i][j] == 0)
					{
					global->map[i][j] = ft_abs(y - i) + ft_abs(x - j);
					// dprintf(2, "first assignment for (%d, %d) : %d\n", i, j, global->map[i][j]);
					}
				else if (global->map[i][j] > 0)
					{
					global->map[i][j] = ft_min(global->map[i][j], ft_abs(y - i) + ft_abs(x - j));
					// dprintf(2, "replacing (%d, %d) : %d\n", i, j, global->map[i][j]);
					}
				if (x < global->width)
					x++;
				if (x == global->width)
				{
					// dprintf(2, "next line\n");
					x = 0;
					y++;
				}
				// dprintf(2, "new value for (%d, %d) : %d\n", i, j, global->map[i][j]);
			}
			// dprintf(2, "point done\n");
			x = 0;
			y = 0;
			j++;
		}
		i++;
	}
}

void	assign_size(t_global *global, char **line)
{
	char	*str;

	// dprintf(2, "assign_size\n");
	str = *line + 8;
	// ft_putendl_fd(str, 2);
	global->width = ft_atoi(ft_strchr(str, ' '));
	global->height = ft_atoi(str);
}

void	assign_player(t_global *global, char **line)
{
	char	*str;

	// dprintf(2, "assign_player\n");
	// ft_putendl_fd(*line, 2);
	str = *line + 10;
	// ft_putendl_fd(str, 2);
	// write(2, &str[0], 1);
	// write(2, "\n", 1);
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
		ft_putendl_fd("player error", 2);

}

int		*fill_line(char *str, t_global *global)
{
	int	*new_line;
	int	j;

	j = 0;
	new_line = (int *)malloc(global->width * sizeof(int));

	// dprintf(2, "fill_line\n");
	// dprintf(2, "str = %s\n", str);
	while (j < global->width)
	{

		// dprintf(2, "line[%d]\n", j);
		if (str[j] == '.')
			new_line[j] = 0;
		else if (str[j] == 'O')
			new_line[j] = -1;
		else if (str[j] == 'X')
			new_line[j] = -2;
		else
			;
		j++;
	}
	return (new_line);
}