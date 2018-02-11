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

int	main(void)
{
	int fd;
	char **line;
	int return_value;

	line = (char **)malloc(sizeof(char *));
	fd = 0;
	while ((return_value = get_next_line(fd, line)) == 1)
	{
		dprintf(2, "LINE -----------------------%s\n", *line);
		ft_putstr("2 2\n");
		free(*line);
	}
	free(*line);
	free(line);
	dprintf(2, "%s\n", "END OF PLAYER VTENNERO");
	return (0);
}
