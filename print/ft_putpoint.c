/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:11:41 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/03 17:29:05 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointlen(unsigned long p)
{
	int	i;

	i = 0;
	if (p == 0)
		i++;
	while (p > 0)
	{
		p = p / 16;
		i++;
	}
	return (i);
}

static void	writepoint(unsigned long p, int *perr)
{
	if (p >= 16)
	{
		writepoint(p / 16, perr);
		writepoint(p % 16, perr);
	}
	else
	{
		if (p > 9)
			ft_putchar(p - 10 + 'a', perr);
		else
			ft_putchar(p + '0', perr);
	}
}

int	ft_putpoint(unsigned long p, int *perr)
{
	int	len;

	len = ft_putstr("0x", perr) + pointlen(p);
	writepoint(p, perr);
	return (len);
}
