/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:49:56 by vsporer           #+#    #+#             */
/*   Updated: 2017/12/12 01:21:14 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_ants(char *line, int *mode, t_data *data)
{
	int		i;
	int		n_ants;

	i = 0;
	(*mode)++;
	while (ft_isdigit(line[i]))
		i++;
	if (!line[i] && (n_ants = ft_atoi(line)) > 0)
		data->ants = n_ants;
	else
		lem_in_error(ANTS, data);
	return (0);
}

static int	check_room(char *line, t_data *data)
{
	int		i;
	int		j;
	char	**room;

	j = 0;
	if (!(room = ft_split_whitespace(line)))
		lem_in_error(DEFAULT, data);
	else if (ft_strtablen(room) == 3)
	{
		while (room[++j])
		{
			i = 0;
			while (ft_isdigit(room[j][i]))
				i++;
			if (room[j][i])
				return (1);
		}
		new_room(room[0], ft_atoi(room[1]), ft_atoi(room[2]), data);
		ft_strdel(&(room[1]));
		ft_strdel(&(room[2]));
		ft_memdel((void**)&room);
		return (0);
	}
	return (1);
}

static int	check_pipe(char *line, int *mode, t_data *data)
{
	char	**pipe;

	if (*mode != 2)
		*mode = 2;
	if (!(pipe = ft_strsplit(line, '-')))
		lem_in_error(DEFAULT, data);
	else if (ft_strtablen(pipe) == 2)
	{
		if (search_room(pipe[0], data->room) && \
		search_room(pipe[1], data->room))
		{
			
		}
	}
	return (1);
}

int			check_in(char *line, t_data *data)
{
	static int	mode = 0;

	if (!line)
		return (1);
	if (line[0] == '#' || mode == -1)
		return (0);
	else if (!line[0])
		return (1);
	else if (mode == 0)
		return (check_ants(line, &mode, data));
	else if (mode == 1 && !check_room(line, data))
		return (0);
	else
		return (check_pipe(line, &mode, data));
}
