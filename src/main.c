/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:10:42 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/11 18:10:53 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void		print_map(int **map, int height, int width)
{
	int		i;
	int		j;


	dprintf(2, "PRINT MAP\n");
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			// dprintf(2, "line[%d]\n", j);
			// dprintf(2, "map[%d][%d] = %d\n", i, j, map[i][j]);
			dprintf(2, "%d", map[i][j]);
			j++;
			if (j == width)
				write(2, "\n", 1);
		}
		i++;
	}
}

int		*fill_line(char *str, int width)
{
	int	*new_line;
	int	j;

	j = 0;
    new_line = (int *)malloc(width * sizeof(int));
    ft_putendl_fd("str :", 2);
    ft_putendl_fd(str, 2);

	while (j < width)
		{
			if (str[j] == '.')
				new_line[j] = 0;
			else if (str[j] == 'O')
				{
					ft_putendl_fd("is O", 2);
				new_line[j] = 1;
				}
			else
				new_line[j] = 2;
			j++;
		}
	return (new_line);
}

// int		**fill_map(int height, int width)
// {
// 	int		i;
// 	int		j;
// 	int		**map;
// 	char	*str;
// 	char	**line;

// 	dprintf(2, "FILL MAP\n");
// 	i = 0;
// 	j = 0;
// 	map = NULL;

// 	line = (char **)malloc(sizeof(char *));
// 	map = (int **)malloc(height * sizeof(int *));
// 	while (i < height)
// 	{
// 		get_next_line(0, line);
// 		str = *(line + 4);
// 		map[i] = fill_line(str, width);
// 		i++;
// 	}
// 	return (map);
// }

int	main(void)
{
	int 	fd;
	char 	**line;
	int 	return_value;
	int		i;
	int		height;
	int		width;
	int		j;
	int		**map;
	char	*str;

	i = 0;
	j = 0;
	height = 0;
	width = 0;
	dprintf(2, "%s\n", "PLAYER VTENNERO");
	line = (char **)malloc(sizeof(char *));
	fd = 0;

	// ft_putendl_fd("toto", 0);
	while ((return_value = get_next_line(fd, line)) == 1)
	{
		// ft_putendl_fd("line read :", 0);
		// ft_putendl_fd(*line, 0);
		// // dprintf(2, "LINE -----------------------%s\n", *line);
		if (i == 1)
		{
			// ft_putendl_fd("to parse :", 2);
			// ft_putendl_fd(ft_strchr(*line + 8, ' '), 2);
			width = ft_atoi(ft_strchr(*line + 8, ' '));
			height = ft_atoi(*line + 8);
		 	dprintf(2, "width: %d\n", width);
			dprintf(2, "height: %d\n", height);
		}
		dprintf(2, "LINE -----------------------%s\n", *line);
		


		//MAP CREATION


		if (i == 3)
			{
				map = (int **)malloc(height * sizeof(int *));
				while (j < height)
				{
					str = ft_strdup(*line);
					str = str + 4;
					// ft_putendl_fd(str, 2);
					map[j] = fill_line(str, width);
					get_next_line(fd, line);
					j++;
				}
				print_map(map, width, height);
			}

		//RETURN

		ft_putstr("2 2\n");
		free(*line);
		i++;
	}

	free(*line);
	free(line);
	dprintf(2, "%s\n", "END OF PLAYER VTENNERO");
	return (0);
}
