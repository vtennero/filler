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

typedef int				t_bool;

typedef struct			s_point
{
	int					x;
	int					y;
	int					score;
}						t_point;

typedef struct			s_global
{
	t_point				point;
	int					height;
	int					width;
	int					player;
	int					adversary;
	int					**map;
	char				**shape;
	char				result[2];
}						t_global;

typedef struct			s_shape
{
	int					x;
	int					y;
	struct s_shape		*next;
}						t_shape;

/*
** ------------------------- PARSER -------------------------
*/
t_shape		*lst_shape(t_global *global, int height, int width);
void		assign_score(t_global *global);
void		assign_size(t_global *global, char **line);
void		assign_player(t_global *global, char **line);
int			*fill_line(char *str, t_global *global);
/*
** ------------------------- SOLVER -------------------------
*/
t_shape		*lst_valid_territory(t_global *global, t_shape *shape);
/*
** ------------------------- UTILITIES -------------------------
*/
void		print_map(t_global *global);
void		print_coord_shape(t_shape *shape);
void		print_shape(t_global *global, int shape_height);

#endif