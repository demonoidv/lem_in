/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:08:38 by vsporer           #+#    #+#             */
/*   Updated: 2017/11/24 01:10:13 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	int		i;
	char	*line;
	t_data	data;

	i = 0;
	line = NULL;
	data.input = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!(data.input = ft_strtabadd(data.input, line)))
			lem_in_error(MALLOC, &data);

	}
	ft_dprintf(2, "Test = %s\n", line);
	ft_strdel(&line);
	return (0);
}
