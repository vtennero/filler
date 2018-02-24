/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:10:42 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/24 22:21:19 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		free_map(t_global *global, int a)
{
	int			i;

	i = 0;
	if (a == 2)
	{
		if (global->map)
		{
			while (i < global->height)
				free(global->map[i++]);
		}
	}
	free(global->map);
	return (0);
}

static int		free_objects(t_global *global, int shape_height)
{
	int			i;

	i = 0;
	if (global->map)
	{
		while (i < global->height)
			free(global->map[i++]);
	}
	free_map(global, 1);
	i = 0;
	if (global->shape)
	{
		while (i < shape_height)
			free(global->shape[i++]);
		free(global->shape);
	}
	write(1, "\n", 1);
	return (0);
}

static int		in_turn(t_global *global)
{
	int			k;
	int			s_width;
	int			s_height;

	k = 1;
	s_height = 0;
	s_width = 0;
	while (1)
	{
		if (assign_size(global, k) == 0)
			return (0);
		global->map = (int **)malloc(global->height * sizeof(int *));
		if (get_map(global) == 0)
			return (free_map(global, 1));
		if (get_shape_size(&s_height, &s_width) == 0)
			return (free_map(global, 2));
		print_map(global);
		global->shape = (char **)malloc(s_height * sizeof(char *));
		if (get_shape(global, s_height) == 0)
			return (free_map(global, 2));
		solver(global, build_shape(global, s_height, s_width));
		free_objects(global, s_height);
		k++;
	}
	return (0);
}

int				main(void)
{
	t_global	global;

	ft_bzero(&global, sizeof(t_global));
	if (assign_player(&global) == 0)
		return (0);
	return (in_turn(&global));
}
