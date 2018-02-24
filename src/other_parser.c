/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:24:35 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/23 18:03:53 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				assign_size(t_global *global, int k)
{
	char		*str;
	char		*line;

	if (!get_next_line(0, &line))
		return (0);
	if (k == 1)
	{
		str = line + 8;
		if (ft_strlen(str) == 0)
		{
			free(line);
			return (0);
		}
		global->width = ft_atoi(ft_strchr(str, ' '));
		global->height = ft_atoi(str);
	}
	free(line);
	return (1);
}

int				assign_player(t_global *global)
{
	char		*line;
	char		*str;

	if (!get_next_line(0, &line))
		return (0);
	str = line + 10;
	if (str[0] == '1')
	{
		global->player = 1;
		global->adversary = 2;
	}
	else if (str[0] == '2')
	{
		global->player = 2;
		global->adversary = 1;
	}
	else
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}
