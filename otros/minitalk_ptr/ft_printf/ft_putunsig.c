/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:12:32 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/02 16:13:19 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	unsiglen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putunsig(unsigned int nb, int *perr)
{
	int	len;

	if (*perr < 0)
		return (-1);
	len = unsiglen(nb);
	if (nb == 0)
		return (ft_putchar ('0', perr));
	if (nb >= 10)
	{
		ft_putunsig(nb / 10, perr);
		ft_putunsig(nb % 10, perr);
	}
	else
	{
		ft_putchar(nb + '0', perr);
	}
	return (len);
}
