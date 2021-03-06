/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 23:24:28 by demodev           #+#    #+#             */
/*   Updated: 2017/09/07 16:00:40 by demodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_ptr(void **p1, void **p2)
{
	void	*tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
