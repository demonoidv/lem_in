/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 21:12:58 by vsporer           #+#    #+#             */
/*   Updated: 2017/12/02 01:11:43 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		**create_msg(void)
{
	char	*msg[3];

	msg[0] = NULL;
	msg[1] = "lem_in: ants error";
	msg[2] = "lem_in: malloc() error";
	return ((char**)msg);
}

void			lem_in_error(int err, t_data *data)
{
	char	**msg;

	msg = create_msg();
	del_data(data);
	ft_error(err, msg[err], 'q');
}
