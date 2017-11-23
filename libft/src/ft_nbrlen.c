/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demodev <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:08:49 by demodev           #+#    #+#             */
/*   Updated: 2017/09/07 16:09:04 by demodev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int n)
{
	size_t	i;

	i = (n < 0) ? 2 : 1;
	while ((n = (n / 10)))
		i++;
	return (i);
}
