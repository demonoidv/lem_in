/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:06:21 by vsporer           #+#    #+#             */
/*   Updated: 2017/12/11 19:20:36 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <limits.h>

# define DEFAULT 0
# define ANTS 1

typedef struct	s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_room
{
	int				i;
	char			*name;
	t_pos			pos;
	struct s_room	**pipe;
}				t_room;

typedef struct	s_data
{
	int		ants;
	char	**input;
	char	***path;
	t_room	*start;
	t_room	*end;
	t_room	**room;
}				t_data;

/*
** Base
*/
void			lem_in_error(int err, t_data *data);
/*
** Read map
*/
int				check_in(char *line, t_data *data);
void			read_map(t_data *data);
void			check_map(t_data *data);
/*
** Algorithm
*/
void			get_path(t_data *data);
void			release_ants(t_data *data);
/*
** Tools
*/
void			add_pipe(t_room *one, t_room *two);
void			new_room(char *name, int x, int y, t_data *data);
void			del_room_tab(t_room **room);
void			del_data(t_data *data);
t_room			*search_room(char *name, t_room **room);

#endif
