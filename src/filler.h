/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:09:01 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/11 18:09:03 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef int		t_bool;

typedef struct	s_point
{
	int			x;
	int			y;
	int			score;
}				t_point;

typedef struct	s_global
{
	int			height;
	int			width;
	int			player;
	int			**map;
	char		**shape;
	char		result[2];
}				t_global;

#endif