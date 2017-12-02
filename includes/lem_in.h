/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:06:21 by vsporer           #+#    #+#             */
/*   Updated: 2017/12/02 05:12:43 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <limits.h>

# define DEFAULT 0
# define ANTS 1

typedef struct	s_room
{
	int				i;
	char			*name;
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
void			del_data(t_data *data);

#endif
