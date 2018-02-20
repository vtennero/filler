/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:10:42 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/18 18:33:57 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	int 	fd;
	char 	**line;
	// int 	return_value;
	int		i;
	int		j;
	// int		**map;
	char	*str;
	t_global	global;
	t_shape		*shape;

	dprintf(2, "%s\n", "PLAYER VTENNERO");


	i = 0;
	j = 0;
	fd = 0;

	line = (char **)malloc(sizeof(char *));
	ft_bzero(&global, sizeof(t_global));


	// ft_putendl_fd("toto", 0);
	while (1)
	{

		// dprintf(2, "i = %d\n", i);
		if (i == 0)
		{
			dprintf(2, "i = %d\n", i);
			get_next_line(fd, line);
			assign_player(&global, line);
			dprintf(2, "vtennero is player%d\n", global.player);
			free(*line);
			i++;
		}

		// while ((return_value = get_next_line(fd, line)) == 1)
		// {
		// ft_putendl_fd("line read :", 0);
		// ft_putendl_fd(*line, 0);
		// // dprintf(2, "LINE -----------------------%s\n", *line);
		if (i == 1)
		{
			// ft_putendl_fd("to parse :", 2);
			// ft_putendl_fd(ft_strchr(*line + 8, ' '), 2);
			get_next_line(fd, line);
			assign_size(&global, line);
			// dprintf(2, "width: %d\n", global.width);
			// dprintf(2, "height: %d\n", global.height);
			dprintf(2, "Plateau %d %d:\n", global.height, global.width);
			free(*line);
			i = 3;
		}
		// dprintf(2, "LINE -----------------------%s\n", *line);



		//MAP CREATION


		if (i == 3)
		{
			global.map = (int **)malloc(global.height * sizeof(int *));

			get_next_line(fd, line);
			free(*line);

			while (j < global.height)
			{
				get_next_line(fd, line);
				str = *line + 4;
				// ft_putendl_fd(str, 2);
				global.map[j] = fill_line(str, &global);
				free(*line);
				j++;
			}
			// adv_lst = create_territory(&global);
			assign_score(&global);
			print_map(&global);
			i += global.height;
		}
		if (i == global.height + 3)
		{
			dprintf(2, "assign shape\n");

			int shape_width;
			int shape_height;

			get_next_line(fd, line);
			str = *line + 6;
			ft_putendl_fd(str, 2);
			shape_width = ft_atoi(ft_strchr(str, ' '));
			shape_height = ft_atoi(str);
			j = 0;
			global.shape = (char **)malloc(shape_height * sizeof(char *));

			while (j < shape_height)
			{
				dprintf(2, "Shaping...\n");
				get_next_line(fd, line);
				// dprintf(2, "line %p\n", &line);
				// dprintf(2, "*line : %s\n", *line);
				global.shape[j] = ft_strdup(*line);
				// dprintf(2, "shape: %s\n", global.shape[j]);
				free(*line);
				j++;
			}
			print_shape(&global, shape_height);
			shape = lst_shape(&global, shape_height, shape_width);
			// print_coord_shape(shape);
		}


		//RETURN


		if (i == global.height + 2)
		{
			dprintf(2, "%s\n", "vtennero is writing...");
			i = 297;
			printf("%s\n", "2 2");
		}
		i++;
		// }
	}

	// free(*line);
	// free(line);
	dprintf(2, "%s\n", "END OF PLAYER VTENNERO");
	return (0);
}
