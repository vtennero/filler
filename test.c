#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void		print_map(int **map, int width, int height)
{
	int		i;
	int		j;


	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			// dprintf(2, "map[%d][%d] = %d\n", i, j, map[i][j]);
			dprintf(2, "%d", map[i][j]);
			j++;
			if (j == width)
				write(1, "\n", 1);
		}
		i++;
	}
}

int	main(void)
{
	int		**map;
	int		h;
	int		w;
	int		i;
	int		j;

	h = 3;
	w = 2;
	i = 0;
	j = 0;
	map = malloc(sizeof(int *) * h);
	while (i < h)
    	map[i++] = malloc(w * sizeof(int));
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	print_map(map, w, h);
	return (0);
}