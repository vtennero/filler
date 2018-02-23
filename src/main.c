/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:10:42 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/23 18:03:58 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		free_objects(t_global *global, int shape_height)
{
	int			i;

	i = 0;
	while (i < shape_height)
		free(global->shape[i++]);
	free(global->shape);
	i = 0;
	while (i < global->height)
		free(global->map[i++]);
	free(global->map);
	write(1, "\n", 1);
}

static int		get_shape_size(int *shape_height, int *shape_width)
{
	char		**line;
	char		*str;

	line = (char **)malloc(sizeof(char *));
	if (line)
	{
		get_next_line(0, line);
		str = *line + 6;
		*shape_width = ft_atoi(ft_strchr(str, ' '));
		*shape_height = ft_atoi(str);
		free(*line);
		if (*shape_height <= 0 || *shape_width <= 0)
			return (0);
	}
	return (1);
}

static int		get_shape(t_global *global, int shape_height)
{
	char		**line;
	int			j;

	j = 0;
	line = (char **)malloc(sizeof(char *));
	while (j < shape_height)
	{
		get_next_line(0, line);
		global->shape[j] = ft_strdup(*line);
		free(*line);
		j++;
	}
	return (1);
}

int				main(void)
{
	int			k;
	t_global	global;
	int			s_width;
	int			s_height;

	k = 1;
	s_height = 0;
	s_width = 0;
	ft_bzero(&global, sizeof(t_global));
	if (assign_player(&global) == 0)
		return (0);
	while (1)
	{
		assign_size(&global, k);
		global.map = (int **)malloc(global.height * sizeof(int *));
		if (get_map(&global) == 0 || get_shape_size(&s_height, &s_width) == 0)
			return (0);
		global.shape = (char **)malloc(s_height * sizeof(char *));
		get_shape(&global, s_height);
		if (solver(&global, lst_shape(&global, s_height, s_width)) == 1)
			free_objects(&global, s_height);
		k++;
	}
	return (0);
}
