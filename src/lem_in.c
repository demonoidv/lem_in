/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:08:38 by vsporer           #+#    #+#             */
/*   Updated: 2017/12/12 16:56:20 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		data_init(t_data *data)
{
	data->ants = 0;
	data->input = NULL;
	data->path = NULL;
	data->start = NULL;
	data->end = NULL;
	data->room = NULL;
}

int				main(void)
{
	int		i;
	t_data	data;

	i = -1;
	data_init(&data);
	read_map(&data);
//	check_map(&data);
//	get_path(&data);
//	release_ants(&data);
	while (data.room && (data.room)[++i])
		ft_printf("Name: %s - Pos: x = %d; y = %d - First pipe: %s\n", \
		((data.room)[i])->name, ((data.room)[i])->pos.x, \
		((data.room)[i])->pos.y, ((((data.room)[i])->pipe)[0])->name);
	del_data(&data);
	return (0);
}
