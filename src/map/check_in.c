/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:49:56 by vsporer           #+#    #+#             */
/*   Updated: 2017/11/27 14:56:19 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_ants(char *line, int *mode, t_data *data)
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
	{
		del_data(&data);
		ft_error(ANTS, &lem_error, 'q');
	}
	return (0);
}

int		check_in(char *line, t_data *data)
{
	static int	mode = 0;

	if (!line)
		return (mode);
	if (line[0] == '#')
		return (0);
	else if (!line[0])
		return (1);
	else if (mode == 0)
		return (check_ants(line, &mode, data));
	else if (mode == 1 && !check_room(line))
		return (0);
	else
		return (check_pipe(line, &mode));
}
