/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:43:39 by vsporer           #+#    #+#             */
/*   Updated: 2017/12/12 16:04:31 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_tab(char ***tab)
{
	int		i;

	i = -1;
	while (*tab && (*tab)[++i])
		ft_strdel(&((*tab)[i]));
	ft_memdel((void**)tab);
}

void	del_data(t_data *data)
{
	int		i;

	i = -1;
	del_tab(&(data->input));
	while (data->path && (data->path)[++i])
		del_tab(&((data->path)[i]));
	ft_memdel((void**)&(data->path));
	del_room_tab(data->room);
}
