/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsporer <vsporer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:08:38 by vsporer           #+#    #+#             */
/*   Updated: 2017/12/01 21:12:34 by vsporer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_data	data;

	read_map(&data);
	check_map(&data);
	get_path(&data);
	release_ants(&data);
	del_data(&data);
	return (0);
}
