/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:09:01 by vtennero          #+#    #+#             */
/*   Updated: 2018/02/22 17:09:03 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef int			t_bool;

typedef struct		s_point
{
	int				x;
	int				y;
	int				score;
}					t_point;

typedef struct		s_global
{
	int				height;
	int				width;
	int				player;
	int				adversary;
	int				**map;
	char			**shape;
}					t_global;

typedef struct		s_shape
{
	int				x;
	int				y;
	struct s_shape	*next;
}					t_shape;

/*
** ------------------------- PARSER -------------------------
*/
int					assign_player(t_global *global);
int					assign_size(t_global *global, int k);
int					get_map(t_global *global);
int					get_shape_size(int *shape_height, int *shape_width);
int					get_shape(t_global *global, int shape_height);
t_shape				*build_shape(t_global *global, int height, int width);
/*
** ------------------------- SOLVER -------------------------
*/
int					all_checks(t_global *global, t_shape *shape, int x, int y);
int					solver(t_global *global, t_shape *shape);
/*
** ------------------------- UTILITIES -------------------------
*/
void				print_shape(t_global *global, int shape_height);
void				print_coord_shape(t_shape *shape);
void				print_map(t_global *global);

#endif
