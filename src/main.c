/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:10:42 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/22 18:14:59 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		free_objects(t_global *global, int shape_height)
{
	int		i;

	i = 0;
	while (i < shape_height)
		free(global->shape[i++]);
	free(global->shape);
	i = 0;
	while (i < global->height)
		free (global->map[i++]);
	free (global->map);
}

// int			get_shape()
// {
// 	int		j;
// 	char 	**line;
// 	char	*str;

// 	line = (char **)malloc(sizeof(char *));
// 	if (line)
// 	{
// 		get_next_line(0, line);
// 	str = *line + 6;
// 	*shape_width = ft_atoi(ft_strchr(str, ' '));
// 	*shape_height = ft_atoi(str);
// 	free(*line);
// 	if (*shape_height <= 0 || *shape_width <= 0)
// 		return (0);
// 	j = 0;
// 	while (j < *shape_height)
// 			{
// 				get_next_line(0, line);
// 				global->shape[j] = ft_strdup(*line);
// 				free(*line);
// 				j++;
// 			}
// 		}
// 		return (0);
// }

int			main(void)
{
	char 	**line;
	int		j;
	int		k;
	char	*str;
	t_global	global;
	t_shape		*shape;
	int shape_width;
	int shape_height;

	k = 1;

	line = (char **)malloc(sizeof(char *));
	ft_bzero(&global, sizeof(t_global));

	if (assign_player(&global) == 0)
		return (0);
	while (1)
	{
		j = 0;			
		get_next_line(0, line);
		if (k == 1)
			assign_size(&global, line);
		global.map = (int **)malloc(global.height * sizeof(int *));
		if (get_map(&global) == 0)
			return (0);
		get_next_line(0, line);
		str = *line + 6;
		shape_width = ft_atoi(ft_strchr(str, ' '));
		shape_height = ft_atoi(str);
		free(*line);
		j = 0;

		global.shape = (char **)malloc(shape_height * sizeof(char *));

		while (j < shape_height)
		{
			get_next_line(0, line);
			global.shape[j] = ft_strdup(*line);
			free(*line);
			j++;
		}
		shape = lst_shape(&global, shape_height, shape_width);
		if (solver(&global, shape) == 1)
		{
			free_objects(&global, shape_height);
			write(1, "\n", 1);
		}
		k++;
	}
	return (0);
}                  
