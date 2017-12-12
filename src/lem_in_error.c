/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 21:12:58 by vsporer           #+#    #+#             */
/*   Updated: 2017/12/12 16:11:41 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		*create_msg(int err)
{
	char	*msg[3];

	msg[0] = NULL;
	msg[1] = "lem_in: ants error";
	msg[2] = "lem_in: malloc() error";
	if (err >= 0 && err < 3)
		return (msg[err]);
	else
		return (NULL);
}

void			lem_in_error(int err, t_data *data)
{
	char	*msg;

	msg = create_msg(err);
	del_data(data);
	ft_error(err, msg, 'q');
}
