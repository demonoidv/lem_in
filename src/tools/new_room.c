/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:08:44 by vsporer           #+#    #+#             */
/*   Updated: 2017/12/12 16:20:08 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*roomalloc(t_data *data)
{
	int		i;
	int		size;
	t_room	**new;

	i = 0;
	size = 0;
	while (data->room && (data->room)[size])
		size++;
	size++;
	if (!(new = (t_room**)malloc(sizeof(t_room*) * (size + 1))))
		lem_in_error(DEFAULT, data);
	while (data->room && (data->room)[i])
	{
		new[i] = (data->room)[i];
		i++;
	}
	if (!(new[i] = (t_room*)malloc(sizeof(t_room))))
		lem_in_error(DEFAULT, data);
	new[i + 1] = NULL;
	ft_memdel((void**)&(data->room));
	data->room = new;
	return ((data->room)[i]);
}

void			new_room(char *name, int x,  int y, t_data *data)
{
	t_room	*new;

	new = roomalloc(data);
	new->i = 0;
	new->name = name;
	new->pos.x = x;
	new->pos.y = y;
	new->pipe = NULL;
}
