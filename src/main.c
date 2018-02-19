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

#include <filler.h>

void		print_map(t_global *global)
{
	int		i;
	int		j;


	dprintf(2, "PRINT MAP\n");
	i = 0;
	while (i < global->height)
	{
		// dprintf(2, "line[%d]\n", i);
		j = 0;
		while (j < global->width)
		{
			// dprintf(2, "map[%d][%d] = %d\n", i, j, map[i][j]);
			dprintf(2, "%d", global->map[i][j]);
			j++;
			if (j == global->width)
				write(2, "\n", 1);
			else
				write(2, "\t", 1);
		}
		i++;
	}
}

int		get_next_point(int *x, int *y, t_global *global)
{
	int		i;
	int		j;

	dprintf(2, "get_next_point(%d, %d)\n", *x, *y);
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
						dprintf(2, "get_next_point: adversary found on (%d, %d)\n", i, j);
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

// t_list	*create_territory(t_global *global)
// {
// 	t_list	*lst;
// 	t_list	*tmp;
// 	int	i;
// 	int	j;

// 	lst = NULL;
// 	tmp = NULL;
// 	i = 0;
// 	j = 0;
// 	while (i < global->height)
// 	{
// 		j = 0;
// 		while (j < global->width)
// 		{
// 			if (global->map[i][j] == -global->adversary)
// 			{
// 				tmp = ft_lstpush(lst, ft_lstnew(global->map[i][j], sizeof(t_point)));
// 				lst = (!(lst)) ? tmp : lst;
// 				lst->parent->y = i;
// 				lst->parent->x = j;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (lst);
// }

void	assign_score(t_global *global)
{
	int	i;
	int	j;
	int	x;
	int	y;

	dprintf(2, "assign score\n");
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
					dprintf(2, "first assignment for (%d, %d) : %d\n", i, j, global->map[i][j]);
					}
				else if (global->map[i][j] > 0)
					{
					global->map[i][j] = ft_min(global->map[i][j], ft_abs(y - i) + ft_abs(x - j));
					dprintf(2, "replacing (%d, %d) : %d\n", i, j, global->map[i][j]);
					}
				if (x < global->width)
					x++;
				if (x == global->width)
				{
					dprintf(2, "next line\n");
					x = 0;
					y++;
				}
				dprintf(2, "new value for (%d, %d) : %d\n", i, j, global->map[i][j]);
			}
			dprintf(2, "point done\n");
			x = 0;
			y = 0;
			j++;
		}
		i++;
	}
}

void		print_shape(t_global *global, int shape_height)
{
	int		j;

	dprintf(2, "PRINT SHAPE\n");
	j = 0;
	while (j < shape_height)
	{
		dprintf(2, "%s\n", global->shape[j++]);
	}	
}

void	assign_size(t_global *global, char **line)
{
	char	*str;

	dprintf(2, "assign_size\n");
	str = *line + 8;
	// ft_putendl_fd(str, 2);
	global->width = ft_atoi(ft_strchr(str, ' '));
	global->height = ft_atoi(str);
}

void	assign_player(t_global *global, char **line)
{
	char	*str;

	dprintf(2, "assign_player\n");
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

	dprintf(2, "fill_line\n");
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
			lst_shape(&global, shape);
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
