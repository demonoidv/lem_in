/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 20:08:13 by vsporer           #+#    #+#             */
/*   Updated: 2017/12/11 16:07:11 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_map(t_data *data)
{
	char	*line;

	line = NULL;
	data->input = NULL;
	while (get_next_line(stdin, &line) > 0 && !check_in(line, data))
	{
		if (ft_strtabadd(&(data->input), line))
		{
			ft_strdel(&line);
			lem_in_error(DEFAULT, data);
		}
		line = NULL;
	}
	ft_strdel(&line);
}
