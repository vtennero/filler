/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:22:03 by vtennero          #+#    #+#             */
/*   Updated: 2018/03/03 13:57:56 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	print_title(void)
{
	ft_dprintf(2, "\e[1;1H\e[2J");
	ft_dprintf(2, "\n\n");
	ft_dprintf(2, "\t\x1b[38;5;1m (           (    (                \n");
	ft_dprintf(2, "\t )\\ )   (    )\\   )\\     (    (    \n");
	ft_dprintf(2, "\t(()/(   )\\  ((_) ((_)   ))\\   )(   \n");
	ft_dprintf(2, "\t /(_)) ((_)  _    _    /((_) (()\\  \n");
	ft_dprintf(2, "\t(_) _|  (_) | |  | |  (_))    ((_) \n");
	ft_dprintf(2, "\t |  _|  | | | |  | |  / -_)  | '_| \n");
	ft_dprintf(2, "\t |_|    |_| |_|  |_|  \\___|  |_|   \x1b[0m\n");
	ft_dprintf(2, "\n\x1b[38;5;87m  ▽\x1b[0m : Player 1\n");
	ft_dprintf(2, "\x1b[38;5;220m  △\x1b[0m : Player 2\n\n");
}

void		print_map(t_global *global)
{
	int		i;
	int		j;

	i = 0;
	print_title();
	while (i < global->height)
	{
		j = 0;
		while (j < global->width)
		{
			if (global->map[i][j] == -1)
				ft_dprintf(2, "\x1b[38;5;87m  ▽\x1b[0m");
			else if (global->map[i][j] == -2)
				ft_dprintf(2, "\x1b[38;5;220m  △\x1b[0m");
			else
				ft_dprintf(2, "%3d", global->map[i][j]);
			j++;
			if (j == global->width)
				write(2, "\n", 1);
		}
		i++;
	}
	ft_dprintf(2, "\n\n");
	nanosleep((const struct timespec[]){{0, 100000000L}}, NULL);
}

void		print_coord_shape(t_shape *shape)
{
	while (shape)
	{
		ft_dprintf(2, "(%d, %d)\n", shape->x, shape->y);
		shape = shape->next;
	}
}

void		print_shape(t_global *global, int shape_height)
{
	int		j;

	j = 0;
	while (j < shape_height)
	{
		ft_dprintf(2, "%s\n", global->shape[j++]);
	}
}
